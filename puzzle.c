#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void up();
//char down();
// char left();
// char right();

int main()
{
    char board[4][4] = {
        {'A', 'B', 'C', 'D'}, 
        {'E', 'F', 'G', 'H'}, 
        {'I', 'J', 'K', 'L'}, 
        {'M', 'N', 'O', ' '}
    };
    up(board);
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("|%c|\n", board[i][j]);
        }
    }
    // int input = getch();
    // switch (input)
    // {
    //     case 72: //up
    //         return 1;
    //     case 80: //down
    //         return 2;
    //     case 75: //left
    //         return 3;
    //     case 77: //right
    //         return 4;
    // }
}

void up(char board[4][4])
{
    // char newBoard[4][4];
    for (int col = 0; col < 4; col++)
    {
        if (board[0][col] == ' ')
        {
            for (int i = 0; i < 3; i++)
            {
                board[i][col] = board[i + 1][col];
            }
            board[3][col] = ' ';
        }
    }
}
