#include <stdio.h>
#define N 4

int board[N][N];

/* Function to print the solution */
void printBoard()
{
    int i, j;
    for(i = 0; i < N; i++)
    {
        for(j = 0; j < N; j++)
            printf("%d ", board[i][j]);
        printf("\n");
    }
}

/* Check if it is safe to place a queen */
int isSafe(int row, int col)
{
    int i, j;

    /* Check left side of row */
    for(i = 0; i < col; i++)
        if(board[row][i])
            return 0;

    /* Check upper diagonal */
    for(i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if(board[i][j])
            return 0;

    /* Check lower diagonal */
    for(i = row, j = col; j >= 0 && i < N; i++, j--)
        if(board[i][j])
            return 0;

    return 1;
}

/* Backtracking function */
int solveNQ(int col)
{
    int i;
    if(col >= N)
        return 1;

    for(i = 0; i < N; i++)
    {
        if(isSafe(i, col))
        {
            board[i][col] = 1;

            if(solveNQ(col + 1))
                return 1;

            /* Backtrack */
            board[i][col] = 0;
        }
    }
    return 0;
}

int main()
{
    if(solveNQ(0) == 0)
    {
        printf("Solution does not exist\n");
        return 0;
    }

    printBoard();
    return 0;
}
