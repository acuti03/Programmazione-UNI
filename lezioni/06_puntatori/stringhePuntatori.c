#include <stdio.h>

void stampa(char *s){
//    printf("%s", s);

    do{
        printf("%c", *s++);
    } while (*s);
    
}

int main(){
    stampa("Hello World!");

    printf("\n");
    return 0;
}