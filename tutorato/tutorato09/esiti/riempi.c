#include <stdio.h>

typedef struct{
    char materia[21];
    int voto;
} Libretto;

int main(){
    FILE *f1, *f2;

    f1 = fopen("libretto1.bin", "wb");
    f2 = fopen("libretto2.bin", "wb");

    Libretto l1[5] = {
        {"Matematica", 19},
        {"Sistemi", 29},
        {"Italiano", 28},
        {"Informatica", 10},
        {"Tpsi", 10}
    };
    Libretto l2[6] = {
        {"Matematica", 29},
        {"Sistemi", 28},
        {"Italiano", 10},
        {"Informatica", 30},
        {"Tpsi", 30},
        {"EDC", 30}
    };
    int i = 0;
    while(i < 5){
        fwrite(&l1[i], sizeof(Libretto), 1, f1);
        fwrite(&l2[i], sizeof(Libretto), 1, f2);
        i++;
    }

    fwrite(&l2[5], sizeof(Libretto), 1, f2);
}