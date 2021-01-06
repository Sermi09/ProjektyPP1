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
