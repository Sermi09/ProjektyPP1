#include <stdio.h>
#include <stdlib.h>

void menu(int a)
{
 poczatek:
 scanf("%d", &a);
 if(a!=0) goto poczatek;
 void exit();
}

int main()
{
    int a;
    menu(a);

    return 0;
}
