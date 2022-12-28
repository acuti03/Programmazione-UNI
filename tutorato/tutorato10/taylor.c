#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.141

int fatt(int n){
	if(n == 1){
		return 1;
	}
	return n * fatt(n - 1);
}

double sinTaylor(double x, int n, int k){
	if(k > n){
		return 0;
	}
	return pow(-1, k) * (pow(x, 2 * k + 1)) / fatt(2 * k + 1) + sinTaylor(x, n, k + 1);
}


int main(){
	int n, k = 0;
	double sinx, x = 0.0;

/*
	ALTRO MODO
	printf("\nScrivi il numero di iterazioni: ");
	while(scanf("%d", &n) && n < 1){
		printf("\nScrivi il numero di iterazioni: ");
	}
*/
	do{
		printf("\nScrivi il numero di iterazioni: ");
		scanf("%d", &n);
	} while (n < 1);

	do{
		printf("\nScrivi l'angolo in radianti: ");
		scanf("%lf", &x);
	}while(x < 0 || x >= 2 * PI);


	sinx = sinTaylor(x, n, k);
	printf("\nIl seno di %lf è: %lf", x, sinx);
	printf("\nSeno da funzione di %lf: %lf", x, sin(x));


	printf("\n");
	return 0;
}