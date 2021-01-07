#include <stdio.h>
#include <stdlib.h>
#include "board.h"
#include "player.h"
#include "AI.h"
#include "points.h"
#include "queens.h"
#include "end.h"

int main()
{
    char board[8][8];
    fill_board(board);
    int moves=0;

    //Pętla wykonująca program//
    while(moves<=100)
    {
       pull_board_up(board);
       player_move(board);
       AI_move(board);
       swap_to_queen(board);
       if(end_game(board)==1) moves+=101;
       moves+=2;
    }
    count_the_points(board);
    return 0;
}
