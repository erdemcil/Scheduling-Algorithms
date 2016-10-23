#include "Header.h"



void delayedDisplay(char str[], int k)
{
    int i;

    for(i = 0; str[i] != '\0'; i++)
    {
        printf("%c", str[i]);
        delay(k);
    }
}
void delay(int milliseconds)
{
    long pause;
    clock_t now,then;

    pause = milliseconds*(CLOCKS_PER_SEC/1000);
    now = then = clock();
    while( (now-then) < pause )
        now = clock();
}


