#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int num;
    int den;
} Frazione;

int valoreAssoluto(int n){
    return n < 0 ? -n : n;
}


Frazione semplifica(Frazione f){
    int i, comune = 1;

    for(i=2; i<=valoreAssoluto(f.num); i++){
        if(f.num % i == 0 && f.den % i == 0){
            printf("%d / %d = %d\n", f.num, i, f.num / i);
            comune = i;
        }
    }

    f.num = f.num / comune;
    f.den = f.den / comune;

    return f;

}


Frazione frazione(int n, int d){
    Frazione f;

    if(d == 0){
        printf("\nErrore: divisione per 0!");
        exit(1);
    }
    if(d < 0){
        d = -d;
        n = -n;
    }

    f.num = n;
    f.den = d;

    return semplifica(f);
}

Frazione divisione(Frazione a, Frazione b){
    return frazione(a.num * b.den, a.den * b.num);
}

Frazione prodotto(Frazione a, Frazione b){
    return frazione(a.num * b.num, a.den * b.den);
}

Frazione sottrazione(Frazione a, Frazione b){
    return frazione(a.num * b.den - a.den * b.num, a.den * b.den);
}

Frazione somma(Frazione a, Frazione b){
    return frazione(a.num * b.den + a.den * b.num, a.den * b.den);
}

Frazione leggi(){
    int n, d;

    scanf("%d%d",&n, &d);

    return frazione(n,d);;
}

void stampaFrazione(Frazione f){
    int i, max = 6, cifra = 0, n = f.num, d = f.den, flag = 0;

    if(f.num < 0) max -= 1;

    n = valoreAssoluto(n);
    d = valoreAssoluto(d);

    while((n / 10) > 0){
        n = n / 10;
        cifra++;
    }
    while((d / 10) > 0){
        d = d / 10;
        cifra++;
    }
    
    for(i=0; i<23; i++){
        printf("_");
    }

    printf("\n|La frazione: %d/%d",f.num, f.den);

    for(i=0; i<max-cifra; i++){
        printf(" ");
    }
    printf("|\n|");
    for(i=0; i<22; i++){
        printf("_");
    }
    printf("|\n");

    getchar();
}

void stampaIStruzioni(){
    printf("\n--- CALCOLATRICE DI FRAZIONI ---\n");
    printf("\n1) Inserisci la prima frazione");
    printf("\n2) Inserisci la seconda frazione");
    printf("\n3) Leggi la prima frazione");
    printf("\n4) Leggi la seconda frazione");
    printf("\n5) Somma di due frazioni");
    printf("\n6) Sottrazione di due frazioni");
    printf("\n7) Prodotto di due frazioni");
    printf("\n8) Divisione di due frazioni");
    printf("\n9) Per stampare le istruzioni");
    printf("\n0) Per uscire\n\n");
    getchar();
}

int main(){
    Frazione a, b, c;
    int i = 0;
    int create = 0;
    int scelta;

    system("clear");
    printf("\n--- CALCOLATRICE DI FRAZIONI ---\n");
    printf("\n1) Inserisci la prima frazione");
    printf("\n2) Inserisci la seconda frazione");
    printf("\n3) Leggi la prima frazione");
    printf("\n4) Leggi la seconda frazione");
    printf("\n5) Somma di due frazioni");
    printf("\n6) Sottrazione di due frazioni");
    printf("\n7) Prodotto di due frazioni");
    printf("\n8) Divisione di due frazioni");
    printf("\n9) Per stampare le istruzioni");
    printf("\n0) Per uscire\n\n");

    printf("Premere un tasto per andare avanti...");
    getchar();

    do{
        system("clear");
        printf("\n: ");
        scanf("%d",&scelta);

        switch (scelta){

            case 1:{
                a = leggi();
                create++;
                break;
            }

            case 2:{
                b = leggi();
                create++;
                break;
            }

            case 3:{
                stampaFrazione(a);
                getchar();
                break;
            }

            case 4:{
                stampaFrazione(b);
                getchar();
                break;
            }

            case 5:{
                if(create > 1){
                    c = somma(a, b);
                    stampaFrazione(c);
                    getchar();
                }
                break;
            }

            case 6:{
                if(create > 1){
                    c = sottrazione(a, b);
                    stampaFrazione(c);
                    getchar();
                }
                break;
            }

            case 7:{
                if(create > 1){
                    c = prodotto(a, b);
                    stampaFrazione(c);
                    getchar();
                }
                break;
            }

            case 8:{
                if(create > 1){
                    c = divisione(a, b);
                    stampaFrazione(c);
                    getchar();
                }
                break;
            }

            case 9:{
                stampaIStruzioni();
                getchar();
                break;
            }
            case 0:{
                printf("\nciao :)\n");
                break;
            }
        }
    } while (scelta != 0);
    

}
