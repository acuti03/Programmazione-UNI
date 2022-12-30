#include <stdio.h>
#include <stdlib.h>


typedef struct nodo{
	int dato;
	struct nodo *next;
} Nodo;



int main(int argc, char **argv){
	Nodo *head= NULL;
	Nodo *nodo;
	Nodo *tmp;
	int i;

	for(i = 0; i < 5; i++){
		nodo = malloc(sizeof(Nodo));
		nodo->next = head;
		nodo->dato = i;
		head = nodo;
	}

	i = 0;
	while(head != NULL){
		printf("| %d ||%x| --> ", head->dato, head->next);
		if(i == 0){
			tmp = head;
		}
		head = head->next;
		i++;
	}

	printf("\n\n");
	head = tmp;
	printf("%d ", tmp->dato);

	printf("\n");
	return 0;
}