#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int compareArray();

void main()
{
    char board[3][3] = {
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', ' '}
    };
    char solved[3][3] = {
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', ' '}
    };
    int s = 50;
    goto scramble;
    play:;
    system("cls");
    for (int i = 0; i < 3; i++)
    {
        printf("|");
        for (int j = 0; j < 3; j++)
        {
            printf("%c|", board[i][j]);
        }
        printf("\n");
    }
    int input = _getch();
    scramble:;
    int index[2];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (' ' == board[i][j])
            {
                index[0] = i;
                index[1] = j;
            }
        }
    }
    char moves[2][3];
    for (int col = 0; col < 3; col++)
    {
        moves[0][col] = board[index[0]][col];
    }
    for (int row = 0; row < 3; row++)
    {
        moves[1][row] = board[row][index[1]];
    }
    if (s > 0) //scrambler -------------------------------
    {
        int i[] = { rand() % 3, rand() % 3 };
        int j[] = { rand() % 3, rand() % 3 };
        if (compareArray(i, j, 2))
        {
            goto scramble;
        }
        char tmp = board[i[0]][i[1]];
        board[i[0]][i[1]] = board[j[0]][j[1]];
        board[j[0]][j[1]] = tmp;
        s--;
    }
    int axis;
    int position;
    int position2;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (input == moves[i][j])
            {
                axis = i;
                position = j;
            }
        }
    }
    for (int j = 0; j < 3; j++)
    {
        if (' ' == moves[axis][j])
        {
            position2 = j;
        }
    }
    int diff = position - position2;
    if (axis == 0)
    {
        if (diff < 0)
        {
            for (int i = 0; i < abs(diff); i++)
            {
                board[index[0]][position2 - i] = board[index[0]][position2 - i - 1];
                board[index[0]][position2 - i - 1] = ' ';
            }
        }
        else
        {
            for (int i = 0; i < abs(diff); i++)
            {
                board[index[0]][position2 + i] = board[index[0]][position2 + i + 1];
                board[index[0]][position2 + i + 1] = ' ';
            }
        }
    }
    else
    {
        if (diff < 0)
        {
            for (int i = 0; i < abs(diff); i++)
            {
                board[position2 - i][index[1]] = board[position2 - i - 1][index[1]];
                board[position2 - i - 1][index[1]] = ' ';
            }
        }
        else
        {
            for (int i = 0; i < abs(diff); i++)
            {
                board[position2 + i][index[1]] = board[position2 + i + 1][index[1]];
                board[position2 + i + 1][index[1]] = ' ';
            }
        }
    }
    if (s > 0)
    {
        goto scramble;
    }
    else if (1)
    {
        goto play;
    }
}

int compareArray(int a[], int b[], int len)
{
    int test = 1;
    for (int n = 0; n < len; n++)
    {
        if (a[n] != b[n])
        {
            test = 0;
        }
    }
    return test;
}