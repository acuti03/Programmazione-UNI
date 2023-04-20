/*
	programma per fare operazioni di base tra matrici
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ncurses.h>

#define CANDOPRODUCT(a, b) (a == b)
#define NOTNULL(a) (a != NULL)


//	ALLOCAZIONE DINAMICA DELLA MATRICE
int **allocateMatrix(int **mat, int row, int col){

	mat = (int **)malloc(row * sizeof(int *));

	for(int i = 0; i < row; i++){
		mat[i] = (int *)malloc(col * sizeof(int));
	}

	return mat;
}

//	STAMPA DELLA MATRICE
void printMatrix(int **mat, int row, int col){

	printf("\n");

	for(int i = 0; i < row; i++){
		for(int j = 0; j < col; j++){
/*			if(i == 0 && j == 0) mat[i][j] = 0;
			else if(i == 0 && j != 0) mat[i][j] = mat[i][j-1] + 1;
			else if(i != 0 && j == 0) mat[i][j] = mat[i-1][col-1] + 1;
			else mat[i][j] = mat[i][j-1] + 1;*/
			printf("%d ", mat[i][j]);
		}
		printf("\n");
	}
}

//	RIEMPIMENTO MATRICE
void createMatrix(int **mat, int row, int col){
	srand(time(NULL));
	int scelta;

	do{
		printf("\nIndica come vuoi riempire la matrice:\n1. random\n2. selfmade\n:");
		scanf("%d", &scelta);
	}while(scelta != 1 && scelta != 2);

	switch (scelta){
		case 1:{
			for(int i = 0; i < row; i++){
				for(int j = 0; j < col; j++){
					mat[i][j] = rand() % 10;
				}
			}
			break;
		}
		case 2:{
			for(int i = 0; i < row; i++){
				for(int j = 0; j < col; j++){
					scanf("%d", &mat[i][j]);
					//printf(" ");
				}
				printf("\n");
			}
			break;
		}
	}
}


int cell(int **mat1, int **mat2, int row, int i, int j){
	int sum = 0;

	for(int k = 0; k < row; k++){
		sum += mat1[i][k] * mat2[k][j];
	}

	return sum;
}


int **matrixProduct(int **mat1, int **mat2, int row1, int col1, int row2, int col2){
	int **mat = NULL;
	int sum = 0;

	mat = allocateMatrix(mat, row1, col2);

	for(int i = 0; i< row1; i++){
		for(int j = 0; j < col2; j++){
			// for(int k = 0; k < row2; k++){
			// 	sum += mat1[i][k] * mat2[k][j];
			// }
			sum = cell(mat1, mat2, row2, i, j);
			mat[i][j] = sum;
			sum = 0;
		}
	}

	return mat;
}



int main(int argc, char **argv){
	int **mat1 = NULL;
	int **mat2 = NULL;
	int operazioni;

	if(argc != 5){
		fprintf(stderr, "Please insert argument row1_col1_row2 _col2]\n");
		exit(1);
	}

	system("clear");
	do{
		printf("\nScegliere:\n\n0. Uscita\n1. Creazione matrice 1\n2. Creazione matrice 2\n3. Eliminazione matrice 1\n4. Eliminazione matrice 2\n5. Moltiplicazione\n6. Determinante\n7. Mostra matrici\n");
		printf("\n: ");
		scanf("%d", &operazioni);

		switch(operazioni){
			case 0:{
				printf("\nGrazie e a presto");
				break;
			}
			case 1:{
				system("clear");
				mat1 = allocateMatrix(mat1, atoi(argv[1]), atoi(argv[2]));
				createMatrix(mat1, atoi(argv[1]), atoi(argv[2]));
				system("clear");
				break;
			}
			case 2:{
				system("clear");
				mat2 = allocateMatrix(mat2, atoi(argv[3]), atoi(argv[4]));
				createMatrix(mat2, atoi(argv[3]), atoi(argv[4]));
				system("clear");
				break;
			}
			case 3:{
				free(mat1);
				mat1 = NULL;
				system("clear");
				break;
			}
			case 4:{
				free(mat2);
				mat2 = NULL;
				system("clear");
				break;
			}
			case 5:{
				if(CANDOPRODUCT(atoi(argv[2]), atoi(argv[3])) && NOTNULL(mat1) && NOTNULL(mat2)){
					printf("\nIl risultato della moltiplicazione:\n");
					printMatrix(matrixProduct(mat1, mat2, atoi(argv[1]), atoi(argv[2]), atoi(argv[3]), atoi(argv[4])), atoi(argv[1]), atoi(argv[4]));
				}
				else{
					fprintf(stderr, "Impossibile eseguire la moltiplicazione\n");
				}
				break;
			}
			case 6:{
				printf("\nNon ancora disponibile :)");
				break;
			}
			case 7:{
				system("clear");
				if(mat1 != NULL){
					printf("Matrice 1\n");
					printMatrix(mat1, atoi(argv[1]), atoi(argv[2]));
				}

				if(mat2 != NULL){
					printf("\n\nMatrice 2\n");
					printMatrix(mat2, atoi(argv[3]), atoi(argv[4]));
				}
				break;
			}
			default :{
				fprintf(stderr, "\nScelta non valida");
				system("clear");
				break;
			}
		}
		
	}while(operazioni != 0);
	

	if(!NOTNULL(mat1)) free(mat1);
	if(!NOTNULL(mat2)) free(mat2);

	printf("\n");
	return 0;
}