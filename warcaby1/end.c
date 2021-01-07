#include "end.h"

int end_game(char board[8][8])
{
    int player_lost=0;
    int AI_lost=0;
    int a=1;
    for(int i=0;i<8;++i)
    {
        for(int j=0;j<8;++j)
        {
            if(board[i][j]=='X') player_lost+=2;
            else if(board[i][j]=='O') AI_lost+=2;
            else if(board[i][j]=='x') player_lost+=2;
            else if(board[i][j]=='o') AI_lost+=2;
        }
    }
    if(player_lost==0) return 1;
    else if(AI_lost==0) return 1;
    else return 0;
}
