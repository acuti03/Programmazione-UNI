#include "funzioni.h"

int main(int arcg, char *argv[]){
    FILE *fb, *ft;
    Alimento a;
    Lista l;
    char alimento[31];
    float calorie, calorieAlimento, calorieTotali = 0;

    fb = fopen(argv[1], "rb");
    ft = fopen(argv[2], "rt");


    if(arcg != 3){
        printf("\nUso Scorretto!");
        exit(1);
    }


    if(fb == NULL || ft == NULL){
        printf("\nErrore");
        exit(1);
    }

    listaVuota(&l);

    while(fread(&a, sizeof(a), 1, fb)){
        if(!piena(&l)) inserisciInCoda(&l, a);
    }

    for(int i = 0; i < l.nElementi; i++){
        printf("%s %f\n",l.dati[i].nome, l.dati[i].calorie);
    }
    
    while(fscanf(ft, "%s%f", alimento, &calorie) == 2){
        calorieAlimento = calcoloCalorie(alimento, &l, calorie);
        calorieTotali += calorieAlimento;
    }

    printf("\nLe calorie totali: %.1f\n", calorieTotali);

    fclose(fb);
    fclose(ft);
    
    printf("\n");
    return 0;
}