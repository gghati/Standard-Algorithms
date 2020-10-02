#include <stdio.h>
#include <stdbool.h> 
 int n;

void printSolution(int board[n][n])
{
    static  int k = 1;
    printf("%d-\n",k++);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf(" %d ", board[i][j]);
        printf("\n");
    }
    printf("\n");
}
 
bool isSafe(int board[n][n], int row, int col)
{
    int i, j;
 
    
    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;
 
    
    for (i=row, j=col; i>=0 && j>=0; i--, j--)
        if (board[i][j])
            return false;
 
   
    for (i=row, j=col; j>=0 && i<n; i++, j--)
        if (board[i][j])
            return false;
 
    return true;
}

bool solvenQUtil(int board[n][n], int col)
{
    if (col == n )
    {
        printSolution(board);
        return true;
    }
 
    for (int i = 0; i < n; i++)
    {
        
        if ( isSafe(board, i, col) )
        {
            
            board[i][col] = 1;
 
            
            solvenQUtil(board, col + 1);
 
            board[i][col] = 0; 
        }
    }
 
    return false;
}
 

void solvenQ()
{
    int board[n][n];
    for(int i = 0; i < n; i++)
        for (int j = 0; j < n; ++j)
        {
            board [i] [j] = 0;
        }
 
    if (solvenQUtil(board, 0))
    {
        printf("Solution does not exist\n");
        return ;
    }
 
    return ;
}
 

int main()
{
    printf("Enter the size of the board, ie value of n:\n");
    scanf("%d",&n);
    solvenQ();
    return 0;
}