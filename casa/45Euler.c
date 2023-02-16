/*

Triangle    Tn=n(n+1)/2
Pentagonal  Pn=n(3n−1)/2
Hexagonal   Hn=n(2n−1)

T285 = P165 = H143 = 40755.

*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>


#define START_TRIANGLE 286
#define START_PENTAGONE 166
#define START_HEXAGONE 144


unsigned long long triangle(int n){
    return (unsigned)(n * (n + 1)) / 2;
}

unsigned long long pentagonal(int n){
    return (unsigned)(n * ((3 * n) - 1)) / 2;
}

unsigned long long hexagonal(int n){
    return (unsigned)n * ((2 * n) - 1);
}


int main(){
    unsigned long long t, p, h;
    int i, j, k;


    j = START_PENTAGONE;
    k = START_HEXAGONE;
    while(p != h){
        p = pentagonal(j);
        h = hexagonal(k);

        if(h > p){
            k = START_HEXAGONE;
            j++;
        }
        else{
            k++;
        }
    }

    for(i = START_TRIANGLE; t != p; i++){
        t = triangle(i);
    }

    printf("\ntriangle number: %llu", t);

    printf("\n");
    return 0;
}

// result: 1533776805