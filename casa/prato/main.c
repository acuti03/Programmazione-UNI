#include <stdio.h>
#include <stdlib.h>
#include "conio.h"

#define RIG 4
#define COL 6
#define PROB 0.2

typedef enum{
    Vinto,
    Perso,
    InCorso
} Stato;


typedef struct{
    float minata;
    int coperta;
} Casella;


typedef struct{
    Casella griglia[RIG][COL];
} Campo;


typedef struct{
    int riga;
    int colonna;
} Mossa;


float rnd_float(Campo *c, float a, float b){
    return a + (b - a) * (float)rand() / RAND_MAX;
}

void inizializza(Campo *c){
    int i, j;

    for(i = 0; i < RIG; i++){
        for(j = 0; j < COL; j++){
            c->griglia[i][j].minata = rnd_float(c, 0.0, 1.0) <= PROB;
            c->griglia[i][j].coperta = 1;
        }
    }
}

void stampaBordo(){
    printf("  ");
    for(int i = 0; i < (COL * 2) + 1; i++){
        printf("-");
    }
}

void stampaIndici(){
    char c = 'a';

    printf("   ");
    for(int i = 0; i < COL; i++){
        cprintf("%c ",c + i);
    }
}

int mineVicine(Campo *c, int i, int j){
    int m, n;
    int cont = 0;

    for(m = i - 1; m <= i + 1; m++){
        for(n = j - 1; n <= j + 1; n++){
            if((m >= 0 && m < RIG ) && (n >= 0 && n < COL)){
                if(c->griglia[m][n].minata){
                    cont++;
                }
            }
        }
    }

    return cont;
}

void stampa(Campo *c){
    int i , j;

    printf("\n\n");
    stampaIndici();
    printf("\n");
    stampaBordo();
    printf("\n");

    for(i = 0; i<RIG; i++){
        cprintf("%d",i);
        printf("| ");
        for(j = 0; j < COL; j++){
            if(c->griglia[i][j].coperta){
                textcolor(CYAN);
                cprintf("# ");
                textcolor(WHITE);
            }
            else if(!c->griglia[i][j].coperta && !c->griglia[i][j].minata){
                int m = mineVicine(c, i, j);
                textcolor(GREEN);
                cprintf("%d ",m);
                textcolor(WHITE);
            }
            else{
                textcolor(RED);
                cprintf("* ");
                textcolor(WHITE);
            }
        }
        printf("|\n");
    }
    stampaBordo();
}

Stato statoGioco(Campo *c){
    int i, j;


    for(i = 0; i < RIG; i++){
        for(j = 0; j < COL; j++){
            if(c->griglia[i][j].minata && !c->griglia[i][j].coperta){
                return Perso;
            }
        }
    }

    for(i = 0; i < RIG; i++){
        for(j = 0; j < COL; j++){
            if(!c->griglia[i][j].minata && c->griglia[i][j].coperta){
                return InCorso;
            }
        }
    }

    return Vinto;
}

void eseguiMossa(Campo *c, Mossa *m){
    c->griglia[m->riga][m->colonna].coperta = 0;
}

void scriviMossa(Campo *c){
    Mossa m;
    char s[2];

    cprintf("\n\nScrivi la mossa (RIGA-COLONNA):\n");
    scanf("%s", s);
    
    m.riga = (int)s[0] - 48; //'a';
    m.colonna = (int)s[1] - 97; // '1';

    eseguiMossa(c, &m);
}


int main(){
    Campo c;
    Stato s = InCorso;

    clrscr();
    textcolor(WHITE);
    inizializza(&c);

    do{
        stampa(&c);
        scriviMossa(&c);
        s = statoGioco(&c);
        clrscr();
    }while(s == InCorso);

    stampa(&c);
    printf("\n\n");
    if(s == Vinto){
        textcolor(GREEN);
        cprintf("\nBravo! Hai vinto!");
    }
    else{
        textcolor(RED);
        cprintf("\nHai perso! >:(");
    }

    printf("\n\n");
    return 0;
}