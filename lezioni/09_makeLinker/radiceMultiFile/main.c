#include "headers.h"

int main(void) {
    float a;
    printf("Digita un numero\n");
    scanf("%f", &a);
    if (a <= 0) {
        printf("%f e` negativo o nullo\n", a);
        return -1;
    }
    printf("La radice quadrata di %f e` circa %f\n", a, radq(a));
    return 0;
}
