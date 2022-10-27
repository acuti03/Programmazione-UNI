#include <stdio.h>
#include <math.h>

double fattoriale(int n);


int main(){
    double x;
    double sin = 0.0;
    int i;
    double fact, power;

    scanf("%lf",&x);

    for(i=0; i<10; i++){
        power = pow(-1, i) * pow(i, 2 * i + 1);
        fact = fattoriale(2 * i + 1);
        sin += power / fact;
    }

    printf("%lf\n",sin);


    return 0;
}

double fattoriale(int n){
    if(n == 0 || n == 1) return 1.0;
    return n * fattoriale(n - 1);
}