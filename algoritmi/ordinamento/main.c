#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
  int min_size;
  int max_size;
  int step;
  int repetitions;
  int seed;
} Configuration;


Configuration init(void) {
  Configuration conf;

  conf.min_size = 1000;
  conf.max_size = 30000;
  conf.step = 1000;
  conf.repetitions = 50;
  conf.seed = 362372;

  return conf;
}

void insertion_sort(int *v, int start, int end) {
    int key, i, j;
    
    for (j = start; j < end + 1; j++) {
      key = v[j];
      i = j-1;

      while(i>=start && v[i] > key) {
        v[i+1] = v[i];
        i--;
      }
      v[i+1] = key;
    }

}

int check(int *v, int size) {
  for(int i = 1; i < size; i++) {
    if(v[i] < v[i-1]) {
      return -1;
    }
  }
  return 0;
}

double run(size_t size, int repetitions) {
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
    insertion_sort(v, 0, (int)size - 1);
    if(check(v, size) == -1){
      printf("ERRORE: l'ordinamento è scorretto.\n");
    }
    end = clock();

    elapsed_time += (end - start) / (double)CLOCKS_PER_SEC;
    free(v);
  }

  return (double)elapsed_time / repetitions;
}

void run_experiments(Configuration conf) {
  int i;
  double elapsed_time;

  for(i = conf.min_size; i < conf.max_size; i+=conf.step) {
    srand(conf.seed);
    elapsed_time = run(i, conf.repetitions);
    printf("Tempo impiegato: %g\n", elapsed_time);
    conf.seed++;
  }
}

int main(void) {
  
  Configuration conf = init();
  run_experiments(conf);

  return 0;
}
