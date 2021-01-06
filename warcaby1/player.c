#include "player.h"


void player_move(char board[8][8])
{
    int a1,a2,b1,b2;
    char player_mark = 'X';
    char AI_mark = 'O';
    char player_queen = 'x';
    char AI_queen = 'o';

    startp:

    printf("Podaj wspołrzedne pionka którym chcesz sie poruszyc (numer kolumny i wiersza)\n");
    scanf("%d %d",&a1,&a2);

       //poruszanie się pionkiem
       if(board[a2-1][a1-1]==player_mark)
       {
         printf("Podaj wspołrzedne pola na którym chcesz ustawic pionka (numer kolumny i wiersza)\n");
         scanf("%d %d",&b1,&b2);
         if((b2-a2==-1 && b1-a1==1)||(b2-a2==-1 && b1-a1==-1))
         {
            if(board[b2-1][b1-1]==' ')
         {
            for(int i=0;i<8;++i)
            {
                for(int j=0;j<8;++j)
                {
                    if(((board[i-1][j-1]==AI_mark || board[i-1][j-1]==AI_queen) && b1-a1<0 && board[i-2][j-2]==' ') || ((board[i+1][j-1]==AI_mark || board[i+1][j-1]==AI_queen) && b1-a1<0 && board[i+2][j-2]==' '))
                    {
                        printf("Musisz zbic!!!\n");
                    }
                }
            }
            board[b2-1][b1-1]=player_mark;
            board[a2-1][a1-1]=' ';
         }
         else if((board[b2-1][b1-1]==AI_mark || board[b2-1][b1-1]==AI_queen) && b1-a1<0 && board[b2-2][b1-2]==' ')
         {
            board[b2-1][b1-1]=' ';
            board[b2-2][b1-2]=player_mark;
            board[a2-1][a1-1]=' ';
         }
         else if((board[b2-1][b1-1]==AI_mark || board[b2-1][b1-1]==AI_queen) && b1-a1>0 && board[b2-2][b1]==' ')
         {
            board[b2-1][b1-1]=' ';
            board[b2-2][b1]=player_mark;
            board[a2-1][a1-1]=' ';
         }
         else
         {
          printf("Nie mozna tam umiescic pionka\n");
          goto startp;
         }
         }
         else
         {
           printf("Nie mozesz tam umiescic pionka\n");
           goto startp;
        }
       }
       //poruszanie sie królową
       else if(board[a2-1][a1-1]==player_queen)
       {
        printf("Podaj wspołrzedne pola na którym chcesz ustawic pionka (numer kolumny i wiersza)\n");
         scanf("%d %d",&b1,&b2);
         if((b2-a2==-1 && b1-a1==1)||(b2-a2==-1 && b1-a1==-1)||(b2-a2==1 && b1-a1==1)||(b2-a2==1 && b1-a1==-1))
         {
            if(board[b2-1][b1-1]==' ')
             {
               board[b2-1][b1-1]=player_queen;
               board[a2-1][a1-1]=' ';
             }
            else if((board[b2-1][b1-1]==AI_mark || board[b2-1][b1-1]==AI_queen) && b1-a1<0 && board[b2-2][b1-2]==' ')
              {
                board[b2-1][b1-1]=' ';
                board[b2-2][b1-2]=player_queen;
                board[a2-1][a1-1]=' ';
              }
            else if((board[b2-1][b1-1]==AI_mark || board[b2-1][b1-1]==AI_queen) && b1-a1>0 && board[b2-2][b1]==' ')
              {
                board[b2-1][b1-1]=' ';
                board[b2-2][b1]=player_queen;
                board[a2-1][a1-1]=' ';
              }
            else if((board[b2-1][b1-1]==AI_mark || board[b2-1][b1-1]==AI_queen) && b1-a1<0 && board[b2][b1]==' ')
              {
                board[a2-1][a1-1]=' ';
                board[b2-1][b1-1]=' ';
                board[b2][b1-2]=player_queen;
              }
            else if((board[b2-1][b1-1]==AI_mark || board[b2-1][b1-1]==AI_queen) && b1-a1>0 && board[b2][b1-2]==' ')
              {
                board[a2-1][a1-1]=' ';
                board[b2-1][b1-1]=' ';
                board[b2][b1]=player_queen;
              }
            else
              {
                printf("Nie mozna tam umiescic pionka\n");
                goto startp;
              }
         }
         else
          {
           printf("Nie mozesz tam umiescic pionka\n");
           goto startp;
          }
        }
        else
        {
         printf("Na tym polu nie ma twojego pionka!\n");
         goto startp;
        }
}
