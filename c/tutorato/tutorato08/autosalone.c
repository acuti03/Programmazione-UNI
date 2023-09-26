#include <stdio.h>


typedef struct{
    char nome[31];
    char cognome[31];
} Acquirente;


typedef struct{
    char marca[21];
    int cilindrata;
    int anno;
    Acquirente acquirente;
} Automobile;



void aggiungiAutomobile(Automobile *a, int *dl){
    int i; 

    do{
        printf("\nDigita il numero di auto da aggiungere: ");
        scanf("%d", dl);
    }while(*dl > 5);

    for(i = 0; i < *dl; i++){
//	INSERIMENTO DEL NOME DELL'AUTO
		printf("\nInserisci il nome del proprietario: ");
		scanf("%s", a[i].acquirente.nome);
//	INSERIMENTO DEL COGNOME DELL'AUTO
		printf("Inserisci il cognome del proprietario: ");
		scanf("%s", a[i].acquirente.cognome);
//	INSRIMENTO DELLA MARCA
        printf("Inserisci la marca dell'auto: ");
        scanf("%s", a[i].marca);
//	INSERIMENTO DELLA CILINDRATA
        do{
            printf("Inserisci la cilindrata dell'auto: ");
            scanf("%d", &a[i].cilindrata);
        } while (a[i].cilindrata <= 800 && a[i].cilindrata >= 2500);
//	INSERIMENTO DELL'ANNO
		do{
            printf("Inserisci l'anno dell'auto: ");
            scanf("%d", &a[i].anno);
        } while (a[i].cilindrata <= 2000 && a[i].cilindrata >= 2019);
        
    }
}

unsigned long luns(char *m){
	int i = 0;

	while (m[i] != '\0'){
		i++;
	}

	return i;
}

void ricercaAuto(Automobile *a, int *dl){
	int i, j;
	int trovati;
	char marca[21];

	printf("\nInserisci il nome dell'auto: ");
	scanf("%s", marca);

	unsigned long len = luns(marca);

//	CICLO DI SCORRIMNENTO DI TUTTE LE AUTO
	for(i = 0; i < *dl; i++){
		trovati = 0;
//	CICLO DI SCORRIMENTO DEI CARATTERI DELLE MARCHE
		for(j = 0; a[i].marca[j] != '\0'; j++){
			if(marca[j] == a[i].marca[j]){
				trovati++;
			}
		}
		if(trovati == len){
			printf("---------------------------------------\n");
			printf("\nIl nome del proprietario: %s", a[i].acquirente.nome);
			printf("\nIl cognome del proprietario: %s", a[i].acquirente.cognome);
			printf("\nLa cilindrata dell'auto: %d", a[i].cilindrata);
			printf("\nL'anno dell'auto: %d\n",a[i].anno);
		}
	}
}

void stampaCognome(Automobile *a, int *dl){
	int i;

	for(i = 0; i < *dl; i++){
		if(a[i].cilindrata >= 1800){
			printf("\nIl cognome del proprietario dell'auto %s: %s", a[i].marca, a[i].acquirente.cognome);
		}
	}
}

void annoImmatricolazioni(Automobile *a, int *dl){
	int i, cont = 0;
	int anno;

	do{
		printf("\nInserisci l'anno: ");
		scanf("%d", &anno);
	}while(anno < 2000 && anno > 2019);

	for(i = 0; i < *dl; i++){
		if(anno == a[i].anno){
			cont++;
		}
	}

	printf("\nLe auto comn l'anno di immatricolazione che corrispondono all'anno inserito sono: %d", cont);
}


int main(){
    Automobile autosalone[5];
	int dl;

    aggiungiAutomobile(autosalone, &dl);
	ricercaAuto(autosalone, &dl);
	stampaCognome(autosalone, &dl);
	annoImmatricolazioni(autosalone, &dl);
    


    printf("\n");
    return 0;
}