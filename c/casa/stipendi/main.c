#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char nome[11];
    int stipendio;
} Persona;

int main(){
    FILE *f;
    Persona p;
    /*[3] = {
        {"Simone", 1000},
        {"Alessio", 800},
        {"Marius", 700}
    };*/

    f = fopen("stipendi.dat", "r+b");
    if(f == NULL){
        printf("Errore: il file non esiste");
        exit(1);
    }

    //fwrite(p, sizeof(Persona), 3, f);
    
    while(fread(&p, sizeof(Persona), 1, f) == 1){
        if(p.stipendio < 1000){
            p.stipendio += (p.stipendio / 10);
            fseek(f, -(int)sizeof(Persona), SEEK_CUR);
            fwrite(&p, sizeof(Persona), 1, f);
            fseek(f, 0, SEEK_CUR);
            //anche se non devo cambiare posizione alla testina per passare
            //da lettura a scrittura devo sempre mettere un fseek
        }
    }

    fclose(f);
    printf("\n");
    return 0;
}
