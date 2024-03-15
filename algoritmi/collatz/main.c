#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
	
	FILE* file = fopen("input.txt", "r");
	int n, i;

	if(file == NULL) {
		fprintf(stderr, "Errore: I/O error");
		exit(1);
	}

	fscanf(file, "%d", &n);

	for (i = 1; n != 1; i++) {
		printf("%d\n", n);
		
	 	if((int) pow(2, (int)log2(n)) == n){
			i += log2(n);
			break;
		}

		if(n % 2 == 0){
			n /= 2;
		}
		else {
			n = 3 * n + 1;
		}
	}
	
	file = fopen("output.txt", "w");

	if (file == NULL) {
		fprintf(stderr, "Errore: I/O error");
		exit(1);
	}

	printf("Programma terminato con una sequenza lunga: %d\n", i);
	fprintf(file, "%d", i);

	fclose(file);
	return 0;
}
