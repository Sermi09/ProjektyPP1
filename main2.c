#include <stdio.h>

void teskt (char a[])
{
    static int b=1;
    printf("%d %s\n", b , a);
    ++b;
}

int main()
{
    int a[255];
    printf("Podaj tekst\n");
    scanf("%s", a);
    teskt (a);
    teskt (a);
    teskt (a);

    return 0;
}
