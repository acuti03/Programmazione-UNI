#include "conio.h"
#include <stdio.h>

int main(){
    textbackground(BLUE);
    clrscr();
    textcolor(WHITE);
    gotoxy(30, 5);
    cprintf("Hello World WHITE");
    textcolor(YELLOW);
    gotoxy(30, 6);
    cprintf("Hello World YELLOW");
    int i;
    for (i = 0; i < 16; i++)
    {
        textcolor(i);
        gotoxy(1, 2 + i);
        cprintf("Hello World");
    }
    getch();
    return 0;
}