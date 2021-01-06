#include "queens.h"

//zamiana pionkow na krolowe
void swap_to_queen(char board[8][8])
{
    int i=7;
    for(int j=0;j<7;j+=2)
    {
        if(board[i][j]=='O') board[i][j]='o';
    }
    i=0;
    for(int j=1;j<8;j+=2)
    {
        if(board[i][j]=='X') board[i][j]='x';
    }

}
