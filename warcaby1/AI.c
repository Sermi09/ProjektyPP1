#include "AI.h"

int AI_move(char board[8][8])
{
    int a=1;
    int max=0;
    int price[8][8];
    //liczenie najwiekszej ilosci mozliwych zbic
    for(int i=0;i<8;++i)
    {
        for(int j=0;j<8;++j)
        {
            price[i][j]=0;
            if((board[i][j]=='O') && (board[i+a+1][j+a+1]!='X' || board[i-a-1][j+a+1]!='X'))
            {
             while(((board[i+a][j+a]=='X' || board[i+a][j+a]=='x') && board[i+a+1][j+a+1]==' ')||((board[i+a][j-a]=='X' || board[i+a][j-a]=='x') && board[i+a+1][j-a-1]==' '))
             {
               price[i][j]+=1;
               a+=2;
             }
            }
            else if(board[i][j]=='o')
            {//uzupełnić warunek do poruszania sie krolowych!!!
             while(((board[i+a][j+a]=='X' || board[i+a][j+a]=='x') && board[i+a+1][j+a+1]==' ')||((board[i+a][j-a]=='X' || board[i+a][j-a]=='x') && board[i+a+1][j-a-1]==' ')||((board[i-a][j-a]=='X' || board[i-a][j-a]=='x') && board[i-a-1][j-a-1]==' ')||((board[i-a][j+a]=='X' || board[i-a][j+a]=='x') && board[i-a-1][j+a+1]==' '))
             {
               price[i][j]+=1;
               a+=2;
             }
            }
            if(max<=price[i][j]) max=price[i][j];
        }
    }
    //wykonywanie zbicia z najwieksza iloscia mozliwych pionkow
    for(int i=0;i<8;++i)
    {
        for(int j=0;j<8;++j)
        {
          if(price[i][j]==max && board[i][j]=='O' && (board[i+1][j+1]=='X' || board[i+1][j+1]=='x') && board[i+2][j+2]==' ' && j+1!=7)
           {
            board[i][j]=' ';
            board[i+2][j+2]='O';
            board[i+1][j+1]=' ';
            goto point1;
           }
          else if(price[i][j]==max && board[i][j]=='O' && (board[i+1][j-1]=='X' || board[i+1][j-1]=='x') && board[i+2][j-2]==' ' && j-1!=0)
           {
            board[i+1][j-1]=' ';
            board[i+2][j-2]='O';
            board[i][j]=' ';
            goto point1;
           }
           else if(price[i][j]==max && board[i][j]=='o' && (board[i+1][j-1]=='X' || board[i+1][j-1]=='x') && board[i+2][j-2]==' ' && j-1!=0)
           {
            board[i+1][j-1]=' ';
            board[i+2][j-2]='o';
            board[i][j]=' ';
            goto point1;
           }
           else if(price[i][j]==max && board[i][j]=='o' && (board[i+1][j+1]=='X' || board[i+1][j+1]=='x') && board[i+2][j+2]==' ' && j+1!=7)
           {
            board[i][j]=' ';
            board[i+2][j+2]='o';
            board[i+1][j+1]=' ';
            goto point1;
           }
           else if(price[i][j]==max && board[i][j]=='o' && (board[i-1][j-1]=='X' || board[i-1][j-1]=='x') && board[i-2][j-2]==' ' && j-1!=0)
           {
            board[i][j]=' ';
            board[i-2][j-2]='o';
            board[i-1][j-1]=' ';
            goto point1;
           }
           else if(price[i][j]==max && board[i][j]=='o' && (board[i-1][j+1]=='X' || board[i-1][j+1]=='x') && board[i-2][j+2]==' ' && j+1!=7)
           {
            board[i][j]=' ';
            board[i-2][j+2]='o';
            board[i-1][j+1]=' ';
            goto point1;
           }
           else if(price[i][j]==max && board[i][j]=='O' && board[i+1][j+1]==' ' && i+1>0 && j+1>0 && i+1<8 && j+1<8)
           {
             board[i][j]=' ';
             board[i+1][j+1]='O';
             goto point1;
           }
           else if(price[i][j]==max && board[i][j]=='O' && board[i+1][j-1]==' ' && i+1>0 && j-1>0 && i+1<8 && j-1<8)
           {
             board[i+1][j-1]='O';
             board[i][j]=' ';
             goto point1;
           }

           else if(price[i][j]==max && board[i][j]=='o' && board[i+1][j-1]==' ' && j-1!=7)
           {
             board[i+1][j-1]='o';
             board[i][j]=' ';
             goto point1;
           }
           else if(price[i][j]==max && board[i][j]=='o' && board[i-1][j+1]==' ' && j+1!=0)
           {
             board[i][j]=' ';
             board[i-1][j+1]='o';
             goto point1;
           }
           else if(price[i][j]==max && board[i][j]=='o' && board[i-1][j-1]==' ' && j-1!=7)
           {
             board[i][j]=' ';
             board[i-1][j-1]='o';
             goto point1;
           }
           else if(price[i][j]==max && board[i][j]=='o' && board[i+1][j+1]==' ' && j+1!=0)
           {
             board[i][j]=' ';
             board[i+1][j+1]='o';
             goto point1;
           }

        }
    }
    point1:
    return 0;
}
