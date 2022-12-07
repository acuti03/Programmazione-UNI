#include <stdio.h>
#include <math.h>

float media(float a, float x);
float radq(float a, float x);


int main(){
    double a;
    double x;

    scanf("%lf", &a);

    x = 1.0;

    while(media(a,x) > 1e-10){
        x = radq(a,x);
    }

    printf("%lf\n", x);

}

float media(float a, float x){
    return fabs(x * x - a) / a;
}

float radq(float a, float x){
    return (x + a/x) / 2;
}