#include <stdio.h>

int main(){
    char s[20];

    scanf("%[^\n]s", s);

    printf("la tua stringa: %s\n",s);

    return 0;
}