#include "board.h"

//tworzenie planszy
void pull_board_up(char board[8][8])
{
    printf("   1 2 3 4 5 6 7 8 \n");
    printf("  ----------------- \n");
    for(int i=0;i<8;++i)
    {
        printf("%d |",i+1);
        for(int j=0;j<8;++j)
        {
            printf("%c|",board[i][j]);
            if(j==7)
            {
                printf(" %d",i+1);
                printf("\n");
            }
        }
    }
    printf("  ----------------- \n");
    printf("   1 2 3 4 5 6 7 8 \n");
}

//wypelnianie planszy pionkami
void fill_board(char board[8][8])
{
    char player_mark = 'X';
    char AI_mark = 'O';
    for(int i=0;i<8;++i)
    {
        for(int j=0;j<8;++j)
        {
            board[i][j]=' ';
        }
    }
    board[5][0] = player_mark;
    board[7][0] = player_mark;
    board[6][1] = player_mark;
    board[5][2] = player_mark;
    board[7][2] = player_mark;
    board[6][3] = player_mark;
    board[5][4] = player_mark;
    board[7][4] = player_mark;
    board[6][5] = player_mark;
    board[5][6] = player_mark;
    board[7][6] = player_mark;
    board[6][7] = player_mark;

    board[0][1] = AI_mark;
    board[0][3] = AI_mark;
    board[0][5] = AI_mark;
    board[0][7] = AI_mark;
    board[1][0] = AI_mark;
    board[1][2] = AI_mark;
    board[1][4] = AI_mark;
    board[1][6] = AI_mark;
    board[2][1] = AI_mark;
    board[2][3] = AI_mark;
    board[2][5] = AI_mark;
    board[2][7] = AI_mark;
}
