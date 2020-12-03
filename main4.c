#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int func(int a)
{
    int b;
    b=(a<<3)+(a<<1);
    printf("%d",b);
    return b;
}
int main()
{
    int a;
    scanf("%d",&a);
    func(a);

    return 0;
}
