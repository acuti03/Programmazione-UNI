#include <stdio.h>

typedef enum {Lun, Mar, Mer, Gio, Ven, Sab, Dom} Giorni;

int main(){
    Giorni giorno;

    int i;
    float pagaOraria = 15.4;
    float paga[7], ore[7] = {8.0, 7.5, 0.0, 4.5, 6.0, 8.0, 8.0};

    for(giorno=Lun; giorno <= Dom; giorno++){
        if(giorno == Sab && giorno == Dom)
            paga[i] = ore[i] * pagaOraria * 1.5;
        else
            paga[i] = ore[i] * pagaOraria;
    }
}