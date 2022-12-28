#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int ricorsiva(int *v, int i, int dim){
	if(i < dim){
		if(v[i] > 0){
			return 1 + ricorsiva(v, i + 1, dim);
		}
		return 0 + ricorsiva(v, i + 1, dim);
	}
    return 0;
};

int *allocaVettore(int n){
    int *v;

    v =(int *)malloc(n * sizeof(int));
    if(v == NULL){
        printf("Impossibile allocare il vettore\n");
        exit(2);
    }

    return v;
}

int main(int argc, char **argv){
	srand(time(NULL));
    int i;

    if(argc != 2){
        printf("Uso improrpio del programma");
        exit(1);
    }

	int dim = argv[1][0] - '0';

    printf("dim: %d\n", dim);
    int *vet = allocaVettore(dim);

	printf("\nIl vettore: \n");
	for(i = 0; i < dim; i++){
		vet[i] = (-10) + rand()% (21); // min + rand()% (max - min + 1);
		printf("%d ", vet[i]);
	}

	printf("\nIl numero di elementi positivi dentro l'array: %d", ricorsiva(vet, 0, dim));


    printf("\n");
    return 0;
}