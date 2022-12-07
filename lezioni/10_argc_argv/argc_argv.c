#include <stdio.h>

int main(int argc, char *argv[]){
    int i;

    for(i = 0 ; i < argc; i++){
        printf("\nArgomento del main: %s",argv[i]);
    }
    
    printf("\n");
    return 0;
}