#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define DIM 21

typedef struct {
    char esame[DIM];
    int voto;
} libretto;

int main() {
    libretto l1, l2;
    FILE *f1, *f2, *f3;
    
    f1=fopen("libretto1.bin", "rb");
    f2=fopen("libretto2.bin", "rb");
    f3=fopen("esiti.bin", "w+b");

    
    if(f1==NULL || f3==NULL || f2==NULL){
        printf("Errore\n");
        exit(1);
    }

//  CONTROLLO E SCRITTURA
    while((fread(&l1, sizeof(libretto), 1, f1) == 1) && (fread(&l2, sizeof(libretto), 1, f2) == 1)){
        if(l1.voto >= l2.voto){
            fwrite(&l1, sizeof(libretto), 1, f3);
        }
        else{
            fwrite(&l2, sizeof(libretto), 1, f3);
        }
    }
    
	fclose(f1);
    fclose(f2);
//  SPOSTO LA TESTINA ALL INIZIO DEL FILE PER LEGGERE	
    rewind(f3);

    while(fread(&l1, sizeof(libretto), 1, f3) == 1) {
        printf("%s %d\n", l1.esame, l1.voto);
    }
    
    fclose(f3);
	
	return 0;
}