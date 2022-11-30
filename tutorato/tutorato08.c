#include <stdio.h>
#include <stdlib.h>
#include <time.h>



int ricercaStr(char *s1, char *s2, char *occorrenze){
    int i, j, k = 0;
    int elementi = 0;
    int trovato = 0, inserito = 0;
    char tmp[100];


    for(i = 0; s1[i] != '\0'; i++){
        tmp[i] = s1[i];
    }

    for(i = 0; s1[i] != '\0'; i++){
        trovato = 0;
        inserito = 0;
        for(j = i + 1; s1[j] != '\0'; j++){
            if(s1[i] == s1[j] && s1[i] != '0'){
                s1[j] = '0';
                trovato = 1;
            }
            if(trovato == 1 && inserito == 0){
                occorrenze[k] = s1[i];
                k++;
                inserito = 1;
            }
        }
    }

    for(i = 0; tmp[i] != '\0'; i++){
        s1[i] = tmp[i];
    }

    for(i = 0; s1[i] != '\0'; i++){
        for(k = 0; occorrenze[k] != '\0'; k++){
            if(s1[i] == occorrenze[k]){
                for(j = 0; s2[j] != '\0'; j++){
                    if(s2[j] == s1[i]){
                        s1[i] = '0';
                        elementi++;
                    }
                }
            }
        }
    }

    return elementi;
}


void duplicati(){
    char s1[100];
    char s2[100];
    int elementi;
    char occorrenze[100];

    printf("\nInserisci le due stringhe: ");
    scanf("%s",s1);
    scanf("%s",s2);

    elementi = ricercaStr(s1, s2, occorrenze);

    printf("le occorrenze: %s",occorrenze);
    printf("\nElementi rimossi: %d",elementi);
    printf("\nLa tua stringa: %s", s1);

}


void ricerca(int *a, int *elemento, int *occorrenze, int n){
    int i, j;
    int tmp;
    
    for(i = 0; i < n; i++){
        tmp = 0;
        for(j = i; j < n; j++){
            if(a[i] == a[j]){
                tmp++;
                if(tmp > *occorrenze){
                    *occorrenze = tmp;
                    *elemento = a[i];
                }
            }
        }
    }

}


void occorrenze(){
    srand(time(NULL));
    int n, k;
    int i;
    int elemento, occorrenze = 0;

    printf("Inserisci il numero di elementi:");
    do{
        scanf("%d", &n);
    }while(n < 0 && n > 100);

    int vet[n];

    printf("Inserisci il range degli elementi:");
    do{
        scanf("%d", &k);
    } while (k > n);

    printf("\nIL tuo array:\n");
    for(i = 0; i < n; i++){
        vet[i] = rand() % k;
        printf("%d ",vet[i]);
    }

    ricerca(vet, &elemento, &occorrenze, n);
    printf("\n\nL'elemento con le massime occorrenze è: %d e sono: %d",elemento, occorrenze);

}


int main(){
    int scelta;

    printf("\n1. occorreze\n");
    printf("2. rimuovi duplicati\n");
    printf(":");
    scanf("%d",&scelta);

    switch (scelta){
    case 1:
        system("clear");
        occorrenze();
        break;
    
    case 2:
        system("clear");
        duplicati();
        break;

    default:
        break;
    }

    printf("\n");
    return 0;

}