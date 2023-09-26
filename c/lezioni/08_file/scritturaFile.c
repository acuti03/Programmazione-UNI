#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



bool chiusura(char *s){
    int i;
    bool uguale = false;
    char fine[10] = "FINE";

    for(i = 0; fine[i] != '\0'; i++){
        if(s[i] == fine[i]){
            uguale = true;
        }
        else{
            uguale = false;
        }
    }

    return uguale;
}


int main(){
    FILE *fp;

    fp = fopen("prova.txt", "wt");

    char parola[20];

    do{
        scanf("%s", parola);
        fprintf(fp, "%s\n", parola);
    } while(!chiusura(parola));

    if(fclose(fp) != 0){
        printf("\nErrore nella chiusura");
        exit(2);
    }


    printf("\n");
    return 0;
}