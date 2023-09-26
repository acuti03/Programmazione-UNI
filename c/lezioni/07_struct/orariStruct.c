#include <stdio.h>

struct orari{
    int ore;
    int minuti;
} o1, o2;


int main(){
    int diffMin, diffOre;


    printf("\nInserisci le ore e i minuti:\n");
    scanf("%d%d", &o1.ore, &o1.minuti);
    scanf("%d%d", &o2.ore, &o2.minuti);

    diffOre = o2.ore - o1.ore;
    diffMin = o2.minuti - o1.minuti;
    
    if(diffMin < 0){
        diffOre -= 1;
        diffMin += 60;

        printf("\nDifferenza: %d:%d", diffOre, diffMin);
    }
    else{
        printf("\nDifferenza: %d:%d", diffOre, diffMin);
    }

    printf("\n");

    return 0;
}