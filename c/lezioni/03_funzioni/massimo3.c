#include <stdio.h>

int massimo(int a, int b);
int massimo3(int a, int b, int c);



int main(){

 int a,b,c;

 scanf("%d%d%d",&a, &b, &c);
 
 
 printf("\nIl massimo tra %d - %d - %d è: %d",a,b,c, massimo3(a,b,c));

 printf("\n");

 return 0;
}


int massimo(int a, int b){
 return a > b ? a : b;
}

int massimo3(int a, int b, int c){
 int max = massimo(a,b);

 return massimo(max,c);
}
