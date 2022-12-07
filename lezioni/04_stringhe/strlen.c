#include <stdio.h>
#define COND(i, s) s != '\0' ? s : 0

int main(){
    int i = 0;
    char s[20];

    scanf("%s", s);

    for(i=0; COND(i, s[i]); i++){}

    printf("\nLa lunghezza della stringa: %d\n", i);
}