#include <stdio.h>
#include <string.h>

int main(){
    char s1[50];
    char s2[50];
    int i, j, k, z;
    int flag = 0;
    int cnt = 0;

    scanf("%s", s1);
    scanf("%s", s2);

    int len2 = strlen(s2);

    j = 0;
    for(i=0; s1[i] != '\0'; i++){
        cnt = 0;
        if(s1[i] == s2[j]){
            k = i;
            z = j;
            while(s1[k] == s2[z]){
                k++;
                z++;
                cnt++;
                if(cnt == len2) flag = 1;
            }
        }
    }

    if(flag) printf("\n%s contiene %s\n", s1, s2);
}