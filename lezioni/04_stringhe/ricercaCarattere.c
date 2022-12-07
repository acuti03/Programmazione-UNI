#include <stdio.h>

int main(){
    char s[20];
    char input[2];
    char c;
    int i;
    int trovato = 0;

    scanf("%s", s);
    scanf("%s", input);
    c = input[0];

/*
    do{
        scanf("%c", &c);
    }while(c == '\n' || c == '\t' || c == ' ');
*/
    
    for(i=0; s[i] != '\0'; i++){
        if(s[i] == c) trovato = 1;
    }

    if(trovato) printf("\n%c è presente\n", c);

    return 0;
}