#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct{
    int num;
    int den;
} Frazione;



int valoreAssoluto(int a){
    return a < 0 ? -a : a;
}


void semplifica(Frazione *f){
    int i, comune = 1;

    for(i = 2; i <= valoreAssoluto(f->num); i++){
        if((f->num % i == 0) && (f->den % i == 0)){
            comune = i;
        }
    }

    f->num /= comune;
    f->den /= comune;
}


int frazione(int n, int d, Frazione *f){
    if(d == 0) return 0;

    if(d < 0){
        n = -n;
        d = -d;
    }

/*
    (*f).num = n;
    (*f).den = d;
*/
//  PER INDICARE UN PUNTATORE A STRUTTURA POSSO SCRIVERE ANCHE COSI:
    f->num = n;
    f->den = d;

    semplifica(f);

    return 1;
}


int leggi(Frazione *f){
    int n, d;

    scanf("%d%d",&n, &d);

    return frazione(n, d, f);
}


void stampaFrazione(Frazione *f){
    printf("\nLa tua frazione: %d/%d", f->num, f->den);
    getchar();
}


void divisione(Frazione *a, Frazione *b, Frazione *nf){
    frazione(a->num * b->den, a->den * b->num, nf);
    stampaFrazione(nf);
}


void prodotto(Frazione *a, Frazione *b, Frazione *nf){
    frazione(a->num * b->num, a->den * b->den, nf);
    stampaFrazione(nf);
}


void sottrazione(Frazione *a, Frazione *b, Frazione *nf){
    frazione(a->num * b->den - a->den * b->num, a->den * b->den, nf);
    stampaFrazione(nf);
}


void somma(Frazione *a, Frazione *b, Frazione *nf){
    frazione(a->num * b->den + a->den * b->num, a->den * b->den, nf);
    stampaFrazione(nf);
}


void stampaIstruzioni(){
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
    int scelta;
    int creataA = false, creataB = false;


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
        printf("\n:");
        scanf("%d",&scelta);

        switch (scelta){

            case 1:{
                if(leggi(&a) == 0){
                    printf("\nErrore: divisione per 0!");
                    getchar();
                }
                else{
                    creataA = true;
                }
                break;
            }
            
            case 2:{
                if(leggi(&b) == 0){
                    printf("\nErrore: divisione per 0!");
                    getchar();
                }
                else{
                    creataB = true;
                }
                break;
            }

            case 3:{
                if(creataA) stampaFrazione(&a);
                else printf("\nErrore: Devi prima creare la frazione!");
    
                getchar();
                break;
            }

            case 4:{
                if(creataB) stampaFrazione(&b);
                else printf("\nErrore: devi prima creare una frazione!");

                getchar();
                break;
            }

            case 5:{
                if(creataA && creataB) somma(&a, &b, &c);
                else printf("\nErrore: prima di eseguire un'operazione devi creare le 2 frazioni");
                break;
            }

            case 6:{
                if(creataA && creataB) sottrazione(&a, &b, &c);
                else printf("\nErrore: prima di eseguire un'operazione devi creare le 2 frazioni");
                break;
            }

            case 7:{
                if(creataA && creataB) prodotto(&a, &b, &c);
                else printf("\nErrore: prima di eseguire un'operazione devi creare le 2 frazioni");
                break;
            }

            case 8:{
                if(creataA && creataB) divisione(&a, &b, &c);
                else printf("\nErrore: prima di eseguire un'operazione devi creare le 2 frazioni");
                break;
            }

            case 9:{
                stampaIstruzioni();
                getchar();
                break;
            }

            case 0:{
                printf("\nMio padre :(");
            }
        }

    }while(scelta != 0);



    printf("\n");
    return 0;
}