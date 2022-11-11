#include <stdio.h>

void perfetti();
void euclide();
void piramide();
void piramideReverse();

int main(){

//  NUMERI PERFETTI DA 1 A 10000
    perfetti();

    printf("\n\n");
//  ALGORITMO EUCLIDEO
    euclide();

//  STAMPA DELLA PIRAMIDE
    piramide();

//  STAMPA DELLA PIRAMIDE AL CONTRARIO
    piramideReverse();

    printf("\n\n");

}

void perfetti(){
    int n = 10000;
    int i;
    int j;
    int somma = 0;

    for(i=1; i<=n; i++){
        for(j=1; (j <= i/2) || (j == 1); j++){
            if(i % j == 0){
                somma = somma + j;
            }
        }
        if(somma == i) printf("\nIl numero %d è perfetto",i);
        somma = 0;
    }
}

void euclide(){
    int a, b, r = 0, q, tmpa, cnt=0;

    printf("\nScrivi a e b:\n");
    scanf("%d", &a);
    scanf("%d", &b);

    tmpa = a;

    int c = a;
    int d = b;


    while(b != 0){
        while(tmpa >= b){
            cnt++;
            tmpa = tmpa - b;
        }
        if(tmpa != 0){
            r = a - (b * cnt);
        }else{
            r = 0;
        }
        a = b;
        b = r;
        tmpa = a;
    }

    printf("\nmcd(%d-%d) = %d", c, d, a);
}

void piramide(){
    int i;
    int n;
    int cnt = 0;
    int j = 0;

    printf("\nInserisci il numero: ");
    scanf("%d",&n);

    printf("\nLa tua piramide:\n\n");
    while(n > 0){
        for(i=n*2-1; i>0; i--){
            printf("* ");
        }
        cnt++;
        printf("\n");
        while(j < cnt){
            printf("  ");
            j++;
        }
        n--;
        j = 0;
    }
    
}

void piramideReverse(){
    int i;
    int n;
    int tmp;
    int cnt = 0;
    int j = 0;

    printf("\nInserisci il numero: ");
    scanf("%d",&n);
    cnt = n;
    tmp = 1;

    printf("\nLa tua piramide:\n\n");
    while(n > 0){
        while(j < cnt){
            printf("  ");
            j++;
        }
        cnt--;
        for(i=0; i<tmp*2-1; i++){
            printf("* ");
        }

        printf("\n");
        n--;
        tmp++;
        j = 0;
    }
    

}