/*
    IL PROGRAMMA RICEVE IN INGRESSO UNA DATA E 
    RESTITUISCE IN OUTPUT LA DATA INSERITA +1 GIORNO
*/

#include <stdio.h>

int main(){
    int G_1, M_1, A_1, J_1;
    int N0_1, N1_1, N2_1, N3_1;
    int G_2, M_2, A_2, J_2;

    printf("Inserisci DD/MM/AAAA:\n");
    scanf("%d%d%d", &G_1, &M_1, &A_1);

    N0_1 = (M_1 - 14) / 12;
    N1_1 = (1461 * (A_1 + 4800 + N0_1)) / 4;
    N2_1 = (367 * (M_1 - 2 - 12 * N0_1)) / 12;
    N3_1 = (3 * (A_1 + 4900 + N0_1)) / 400;

    J_1 = N1_1 + N2_1 + N3_1 + G_1 + 32075;
    J_2 = J_1 + 1;



    return 0;
}