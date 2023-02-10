#include <stdio.h>
#include <stdlib.h>



int main() {
    int h;
    int i, j;

    printf("Scrivi altezza: ");
    scanf("%d", &h);


    for(i = 1; i <= h; i++){
//  per gli spazi
        for(j = i; j < h; j++){
            printf(" ");
        }
        if(i != 1){
            j = i;
            while(j <= ((2 * i) - 1)){
                printf("%d", j);
                j++;
            }
            j -= 2;
            while(j >= i){
                printf("%d", j);
                j--;
            }
            
            
        }else{
            printf("%d",i);
        }
        printf("\n");    
    }

    printf("\n");
    return 0;
}