#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *allorcaStringa(int n){
    char *indirizzo = (char *)malloc(n * sizeof(char));

    return indirizzo;
}

int main(){
    char *s;

    s = allorcaStringa(80);
    scanf("%s", s);
    printf("%lu\n", strlen(s));

    free(s);
    return 0;
}