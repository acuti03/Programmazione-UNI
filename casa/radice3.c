#include <stdio.h>
#include <math.h>
#define DIM 5

float radice3(float y){
    float a = 1.0;
    float b = y;
    float x = 1.0;

    do{
        x = (a + b) / 2;

        if(x * x * x > y){
            b = x;
        }
        else{
            a = x;
        }
    }while(fabsf(b - a) > 1e-5);

    return x;
}


int main(){
    int i,j;
    float vet1[10];
    int cnt = 0;

    for(i=0; i<DIM; i++){
        scanf("%f",&vet1[i]);
    }

    for(i=0; i<DIM; i++){
        if(vet1[i] > 1){
            cnt++;
        }
    }

    float vet2[cnt];

    j = 0;
    for(i=0; i<DIM; i++){
        if(vet1[i] > 1){
            vet2[j] = vet1[i];
            j++;
        }
    }

    printf("\n\n");
    for(i=0; i<cnt; i++){
        vet2[i] = radice3(vet2[i]);
        printf("%f\t",vet2[i]);
    }

    printf("\n\n");


}