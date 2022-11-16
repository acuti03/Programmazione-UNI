#include <stdio.h>

int main(){
    char s[20];
    char c;
    int i;
    int trovato = 0;

    scanf("%s", s);
    scanf("%c", &c);
    
    for(i=0; s[i] != '\0'; i++){
        if(s[i] == c) trovato = 1;
    }

    if(trovato) printf("\n%c è presente\n", c);

    return 0;
}