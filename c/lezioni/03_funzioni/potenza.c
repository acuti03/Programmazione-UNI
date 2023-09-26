#include <stdio.h>

float potenza(float a, float b);

int main(){
    float base;
    float esp;

    scanf("%f%f", &base, &esp);
    
    printf("\nIl risultato di %f elevato a %f fa: %f \n",base, esp, potenza(base, esp));

    return 0;
}

float potenza(float a, float b){
    int i;
    int tmp = a;

    if(b == 0) return 1;

    if(b < 0){
        b = -b;
        for(i=1; i<b; i++){
            a = a * tmp;
        }
        return 1 / a;
    }
    
    for(i=1; i<b; i++){
        a = a * tmp;
    }
    return a;
}