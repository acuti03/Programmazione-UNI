#include <stdio.h>

int main(){
    int a, b;
    char ch;
    int *p;

    printf("\nScegli a o b: ");
    scanf("%c", &ch);

    if(ch == 'a') p = &a;
    else if(ch == 'b') p = &b;

    a = 1;
    b = 2;

    printf("\nil valore di *p: %d", *p);

    printf("\n");
    return 0;
}