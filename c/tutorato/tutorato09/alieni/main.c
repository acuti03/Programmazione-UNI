#include <stdio.h>
#include <stdlib.h>


typedef struct{
    char lettera[2];
    char testo[4];
} Corrispondenza;



int comparazione(char *s1, char *s2){
    int i;

    for(i = 0; s1[i] != '\0'; i++){
        if(s1[i] != s2[i]){
            return 0;
        }
    }

    return 1;
}



int main(){
    FILE *fc, *fm;
    Corrispondenza corrispondenza[7];
    int dlc = 0, dlm = 0, i, j;
    char c, testoCry[4];
    int flag = 0;

    
    fc = fopen("corrispondenze.txt", "rt");
    fm = fopen("messaggi.txt", "r+t");

    if(fc == NULL || fm == NULL){
        printf("\nErrore: file non trovato!");
        exit(1);
    }

//  MEMORIZZO I DATI DEL FILE CORRISPONDENZE E STABILISCO IL NUMERO DI RIGHE
    while(fscanf(fc, "%s%s", corrispondenza[dlc].lettera, corrispondenza[dlc].testo) > 0){
        printf("%c %s\n", corrispondenza[dlc].lettera[0], corrispondenza[dlc].testo);
        dlc++;
    }

    printf("\n\n");

//  STABILISCO IL NUMERO DI CARATTERI DENTRO MESSAGGI
    while(fscanf(fm, "%c", &c) > 0){
        dlm++;
    }

//  POSIZIONO LA TESTINA ALL'INIZIO DEL FILE
    rewind(fm);

    i = 0;
    j = 0;
    while(i < dlm){
//  RIMPIAZZO LETTERA DENTRO IL TESTO CRITTATO
        if(j <= 2){
            fscanf(fm, "%c", &c);
            if(c == 'g' || c == 'G'){
                testoCry[j] = c;
                j++;
            }
            flag = 1;
        }
//  SE IL TESTO E' PIENO ALLORA PROCEDO CON LA TRADUZIONE
        else{
            testoCry[3] = '\0';
            printf("\ntesto: %s", testoCry);

            for(j = 0; j < dlc; j++){
                if(comparazione(testoCry, corrispondenza[j].testo)){
                    printf("\nLettera: %c", corrispondenza[j].lettera[0]);
                }
            }

            j = 0;
            flag = 0;
        }
//  QUANDO ARRIVA ALL'ULTIMA LETTERA DEVE COMUNQUE ESEGUIRE IL CONTROLLO, PERCIO GLI AGGIUNGO IL CASO
        if(i == dlm - 1){
            testoCry[3] = '\0';
            printf("\ntesto: %s", testoCry);

            for(j = 0; j < dlc; j++){
                if(comparazione(testoCry, corrispondenza[j].testo)){
                    printf("\nLettera: %c", corrispondenza[j].lettera[0]);
                }
            }
        }
//  SE HO IMPIEGATO IL CICLO PER TRADURRE ALLORA NON DEVO MANDARE AVANTI LA I
        if(flag == 1) i++;
    }
    

    fclose(fm);
    fclose(fc);


    printf("\n");
    return 0;
}