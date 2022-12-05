#include "headers.h"

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