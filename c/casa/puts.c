#include <stdio.h>

int main(){
    char word[20];

    if(scanf("%19s", word) == 1){
        puts(word);
    }
}