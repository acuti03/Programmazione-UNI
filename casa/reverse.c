/*
    Scrivere una funzione di prototipo void reverse(Lista *pl1, Lista *pl2) che
    faccia sì che *pl2 sia la lista inversa di *pl1, cioè contenga gli stessi elementi ma in
    ordine inverso. Ad esempio, l’inversa di [2,0,4,3] è [3,4,0,2].
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef struct nodo{
    int dato;
    struct nodo *next;
} Nodo;

typedef Nodo *Lista;



void stampa(Lista head){
    while (head){
        printf("|%d| --> ", head->dato);
        head = head->next;
    }
    printf("NULL");
}


void inserimentoInTesta(Lista *head, int d){
    Nodo *nodo = malloc(sizeof(Nodo));
    nodo->dato = d;
    nodo->next = *head;
    *head = nodo;
}



void reverse(Lista *head1, Lista *head2){
    while(*head1 != NULL){
        inserimentoInTesta(head2, (*head1)->dato);
        head1 = &(*head1)->next;
    }
    
}


int main(){
    srand(time(NULL));
    Lista head1 = NULL;
    Lista head2 = NULL;
    int dato;


    for(int i = 0; i < rand()% 10 + 1; i++){
        dato = rand() % 20;
        inserimentoInTesta(&head1, dato);
    }


    reverse(&head1, &head2);
    printf("\nLista 1:\n");
    stampa(head1);
    printf("\nLista 2:\n");
    stampa(head2);


    printf("\n");
    return 0;
}
