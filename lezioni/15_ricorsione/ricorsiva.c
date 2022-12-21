#include <stdio.h>

void f(int *a){
    if(*a > 0){
        *a = *a - 1;
        f(a);
    }
}

int main(){
    int i = 5;

    f(&i);
    printf("%d", i);
}