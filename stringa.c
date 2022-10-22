#include <stdio.h>

int main(){
    char n;

    do{
        scanf("%c", &n);
        printf("%c", (n >= 'a') && (n <= 'z') ? n - 32 : n);
    } while (n != '\n');
    
    
}