#include <stdio.h>

int main()
{
  int tab1[5]={1,2,3,4,5},tab2[5];
  for(int i=0,j=4;i<5,j>=0;++i,--j)
  {
    tab2[i]=tab1[j];
  }
  for(int i=0;i<5;++i)
  {
  printf("%d\n", tab2[i]);
  }

  return 0;
}

----------------------------------------------

#include <stdio.h>

teskt (char a[])
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
