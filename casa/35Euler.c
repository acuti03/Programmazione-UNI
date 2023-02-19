#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 1000000
#define DIGIT 7


int max_digit(int n){
    int i = 1;

    while(n / i != 0){
        i *= 10;
    }

    return i / 10;
}


int array_to_num(int *v){
    int i, j, cifre, peso, n = 0;

    for(i = 0; i < DIGIT; i++){
        if(v[i] != 0){
            cifre = DIGIT - i;

            peso = 1;
            for(j = 0; j < cifre; j++){
                peso *= 10;
            }

			n = (peso * v[i]) + n;
        }
    }

	return n / 10;
}


bool is_prime(int n){
	int i;

	for(i = 2; i <= n / 2; i++){
		if(n % i == 0){
			return false;
		}
	}

	return true;
}


int main(){
    int v[7];
    int i, j, k, cifre, excess, tmp, cnt = 0;
	bool isPrime;

	system("clear");


//  ciclo fino ad un milione
    for(i = 1; i <= MAX; i++){
		isPrime = false;
        cifre = 0;
//      trovo il numero di cifre
        for(j = 1; (i / j) != 0; j *= 10){
            cifre++;
        }
//      riempimento
        for(j = 0; j < DIGIT; j++){
            if(j + cifre == DIGIT){

                k = max_digit(i);

                while(j < DIGIT){
                    v[j] = i / k;
        
                    while(v[j] >= 10){
                        excess = max_digit(v[j]) * (v[j] / max_digit(v[j]));
                        v[j] -= excess;
                    }

                    k /= 10;
                    j++;
                }
            }
            else{
                v[j] = 0;
            }
        }
//      stampa
        for(j = 0; j < DIGIT; j++){
            printf("%d ", v[j]);
        }

//		trasformo l'array in un numero e verifico se è primo
		isPrime = is_prime(array_to_num(v));


//      ciclo per fare gli shift e per vedere il nuovo numero è ancora primo
        for(k = 0; k < cifre && isPrime; k++){
            for(j = 0; j < DIGIT; j++){
                if(j + cifre == DIGIT){
                    while(j < DIGIT - 1){
                        tmp = v[j];
                        v[j] = v[j + 1];
                        v[j + 1] = tmp;
                        j++;
                    }
                }
            }
//      controllo se il nuovo numero è primo
			isPrime = is_prime(array_to_num(v));
        }

		if(isPrime && i != 1){
			printf(" -> è un numero primo circolare!");
			cnt++;
		}

		//getchar();

        printf("\n");
    }


	printf("\n\nI numeri primi circolari sotto a 1 MLN sono %d", cnt);


    printf("\n");
    return 0;
}