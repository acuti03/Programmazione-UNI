#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ALGO 16
#define MAX_ALGO_BUFF 64

typedef struct {
  int min_size;
  int max_size;
  int step;
  int repetitions;
  int seed;
  int n_algorithms;
  char algorithms[MAX_ALGO][MAX_ALGO_BUFF];
} Configuration;

typedef void (*algo_ptr)(int*, int, int);

/**
 * Inizializzazione della configurazione
*/
void init(Configuration *conf) {
  int i;
  conf->min_size = 10;
  conf->max_size = 1000;
  conf->step = 10;
  conf->repetitions = 50;
  conf->seed = 362372;
  conf->n_algorithms = 2;

  char *algorithms[] = {"insertion_sort", "merge_sort"};

  for(i = 0; i < conf->n_algorithms; i++) {
    strcpy(conf->algorithms[i], algorithms[i]);
  }

  //TODO: inserimento degli algoritmi dall'utente
}

/**
* Implementazione di insertionSort
*/
void insertion_sort(int *v, int start, int end) {
  int key, i, j;

  for (j = start; j < end + 1; j++) {
    key = v[j];
    i = j - 1;

    while(i >= start && v[i] > key) {
      v[i + 1] = v[i];
      i--;
    }

    v[i + 1] = key;
  }
}

/**
* Fa il merge di due array ordinati
*/
void merge(int *v, int start, int middle, int end) {
  int n1 = middle - start + 1;
  int n2 = end - middle;
  int i, j, k, left[n1], right[n2];

  for(i = 0; i < n1; i++) {
    left[i] = v[start + i];
  }

  for(j = 0; j < n2; j++) {
    right[j] = v[middle + 1 + j];
  }

  i = j = 0;

  for(k = start; k <= end; k++) {
    if(i < n1) {
      if(j < n2) {
        v[k] = (left[i] < right[j]) ? left[i++] : right[j++];
      }
      else {
        v[k] = left[i++];
      }
    }
    else {
      v[k] = right[j++];
    }
  }
}

/**
 * Implementazione di mergeSort
*/
void merge_sort(int *v, int start, int end) {
  if(start < end) {
    int middle = (start + end) / 2;
    merge_sort(v, start, middle);
    merge_sort(v, middle + 1, end);
    merge(v, start, middle, end);
  }
}

/**
 * Funzione di controllo per verificare che l'array sia ordinato
*/
int check(int *v, int size) {
  for(int i = 1; i < size; i++) {
    if(v[i] < v[i-1]) {
      return -1;
    }
  }
  return 0;
}

/**
 * Seleziona un algoritmo di ordinamento scegliendolo
 * in base alla stringa passata come argomento.
 * Vedi `algo_ptr`.
 */
algo_ptr select_algorithm(char *name) {
  if(strcmp(name, "insertion_sort") == 0) {
    return &insertion_sort;
  }
  else if(strcmp(name, "merge_sort") == 0) {
    return &merge_sort;
  }
  else {
    printf("Algoritmo non riconosciuto.\n");
    exit(-1);
  }
}

double run(size_t size, int repetitions, algo_ptr algorithm) {
  int i, j;
  int *v;
  clock_t start, end;
  double elapsed_time = 0.0;

  for(i = 0; i < repetitions; i++) {
    v = (int *)malloc(size * sizeof(int));
    
    for(j = 0; (size_t)j < size; j++) {
      v[j] = rand();
    }

    start = clock();
    algorithm(v, 0, (int)size-1);
    end = clock();

    if(check(v, size) == -1){
      printf("ERRORE: l'ordinamento è scorretto.\n");
    }

    elapsed_time += (end - start) / (double)CLOCKS_PER_SEC;
    free(v);
  }

  return (double)elapsed_time / repetitions;
}

void run_experiments(Configuration conf, FILE *report) {
  int i;
  double elapsed_time;

  for(int i = conf.min_size; i < conf.max_size; i+=conf.step) {
    fprintf(report, "%d ", i);
  }
  fprintf(report, "\n");

  for(int algo_index = 0; algo_index < conf.n_algorithms; algo_index++) {
    for(i = conf.min_size; i < conf.max_size; i+=conf.step) {
      srand(conf.seed);
      elapsed_time = run(i, conf.repetitions, select_algorithm(conf.algorithms[algo_index]));
      fprintf(report, "%g ", elapsed_time);
      conf.seed++;
    }
    fprintf(report, "\n");
  }
}

int main(void) {
  Configuration conf;
  FILE *report = fopen("report.txt", "w");
  init(&conf);

  run_experiments(conf, report);

  if(fclose(report) != 0) {
    printf("Errore nella chiusura del file.\n");
  }

  return 0;
}
