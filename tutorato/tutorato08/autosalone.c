#include <stdio.h>


typedef struct{
    char nome[31];
    char cognome[31];
} Acquirente;


typedef struct{
    char marca[21];
    int cilindrata;
    int anno;
    Acquirente acquirente;
} Automobile;





int main(){
    Acquirente proprietario;
    Automobile macchina[5];

    


    printf("\n");
    return 0;
}