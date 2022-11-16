#include <stdio.h>

int differenza(char a, char b){
    int differenza;

    differenza = a - b;

    return differenza;
}

int main(){
    int i;
    char s1[20];
    char s2[20];
    int diff = 0;

    scanf("%s", s1);
    scanf("%s", s2);

    for(i=0; diff == 0 && (s1[i] != '\0' || s2[i] != '\0'); i++){
        diff = differenza(s1[i], s2[i]);
    }

    if(diff > 0) printf("\n%s precede %s\n", s2, s1);
    else if (diff < 0) printf("\n%s precede %s\n", s1, s2);
    else printf("\n%s è uguale a %s\n", s1, s2);
    

    return 0;

}