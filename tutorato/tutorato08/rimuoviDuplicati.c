#include <stdio.h>

#define DIM 101

//  SCRIVERE CHAR S1[101] O *S1 E' LA STESSA COSA

void shift(char *s, int indice){
    int i;
    
    for(i = indice; s[i] != '\0'; i++){
        s[i] = s[i+1];
    }
}


int rimuoviDuplicati(char *s1, char *s2){
    int eliminati = 0;
    int i, j;

    for(i = 0; s2[i] != '\0'; i++){
        for(j = 0; s1[j] != '\0'; j++){
            if(s1[j] == s2[i]){
                shift(s1, j);
                eliminati++;
            }
        }
    }

    return eliminati;
}



int main(){
    char s1[DIM];
    char s2[DIM];

    scanf("%s", s1);
    scanf("%s", s2);

    printf("Eliminati: %d, la tua stringa: %s",rimuoviDuplicati(s1, s2), s1);

    printf("\n");
    return 0;
}