#include <stdio.h>

#define DIM 20

char maiuscola(char c){
    if(c >= 'a' && c <= 'z'){
        return c - 32;
    }
    return c;
}

int main(){
    int i;
    char s[DIM];

    scanf("%s", s);

    for(i=0; i<DIM; i++){
        s[i] = maiuscola(s[i]);
    }

    printf("\n%s\n", s);
}