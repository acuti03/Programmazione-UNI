#include <stdio.h>

int main(){
    char s1[20];
    char s2[20];
    int i;

    scanf("%s", s1);

    for(i=0; s1[i] != '\0'; i++){
        s2[i] = s1[i];
    }
    
    printf("\nLa tua stringa copiata: %s\n", s2);

}