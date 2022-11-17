#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(){
    srand(time(NULL));
    char s[13];
    int i;

    for(i=0; i<12; i++){
        if(i != 3 && i != 8) s[i] = (rand() % (122 - 97 + 1)) + 97;
        else s[i] = '-';
    }

    printf("\n%s\n", s);

}