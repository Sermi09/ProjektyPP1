#include "points.h"

//zliczanie punktow w przypadku zakonczenia gry
void count_the_points(char board[8][8])
{
    int player_points=0;
    int AI_points=0;
    for(int i=0;i<8;++i)
    {
        for(int j=0;j<8;++j)
        {
            if(board[i][j]=='X') player_points+=1;
            if(board[i][j]=='O') AI_points+=1;
        }
    }
    if(player_points>AI_points) printf("Gratulacje wygrales!!!\n");
    else if(player_points==AI_points) printf("Tym razem remis ;/ \n");
    else if(player_points<AI_points) printf("Niestety przegrales :((( \n");
    printf("Uzyskales %d punktow\n",player_points);
    printf("Przeciwnik uzyskal %d punktow\n",player_points);
}
