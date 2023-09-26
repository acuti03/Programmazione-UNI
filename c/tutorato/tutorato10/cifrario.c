#include <stdio.h>
#include <stdlib.h>


int charToNum(char *s){
    int n = 0;
    int i = 0, j, cnt = 1;

    while (s[i] != '\0'){
        if(s[i + 1] == '\0'){
            for(j = i; j >= 0; j--){
                n = ((s[j] - '0') * cnt) + n;
                cnt *= 10;
            }
        }
        i++;
    }

    return n;
}


int main(int argc, char **argv){
    char parola[21];
    int i;
    FILE *f;

//  CONTROLLO SE GLI ARGOMENTI E IL NOME DEL FILE SONO CORRETTI
    if(argc != 3){
        printf("Uso improprio del programma\n");
        exit(1);
    }

    f = fopen(argv[1], "w+t");
    if(f == NULL){
        printf("Errore...\n");
        exit(1);
    }

//  CIFRATURA DELLA PAROLA
    int n = charToNum(argv[2]);
    printf("\nIl tuo valore numerico: %d", n);

    printf("\nDigita la parola: ");
    scanf("%s", parola);

    for(i = 0; parola[i] != '\0'; i++){
        parola[i] = parola[i] + n;
    }

//  SCRITTURA DELLA PAROLA SUL FILE
    fprintf(f, "%s", parola);

//  LETTURA DELLA PAROLA DAL FILE E STAMPA
    rewind(f);
    while(fscanf(f, "%s", parola) > 0){
        printf("\nLa parola cifrata: %s", parola);
    }

//  LETTURA DELLA PAROLA PER DECIFRARLA
    rewind(f);
    while(fscanf(f, "%s", parola) > 0){
//      DECIFRO LA PAROLA
        for(i = 0; parola[i] != '\0'; i++){
            parola[i] = parola[i] - n;
        }
    }
    printf("\nLa parola decifrata: %s", parola);
    

    printf("\n");
    return 0;
}