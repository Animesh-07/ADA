#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int count=0;
bool isSafe(int board[20][20],int row,int col,int n)
{
    int i,j=0;
    for(i=0;i<col;i++)
        if(board[row][i])
            return false;
    for(i=row,j=col;j>=0&&i>=0;j--,i--)
        if(board[i][j])
            return false;
    for(i=row,j=col;j>=0&&i<n;j--,i++)
        if(board[i][j])
            return false;
    return true;
}

bool nQueenPossible(int board[20][20],int col,int n)
{
    int row,i,j=0;
    for(row=0;row<n;row++)
    {
        if(isSafe(board,row,col,n))
        {
            board[row][col]=1;
            nQueenPossible(board,col+1,n);
            board[row][col]=0;
        }
    }
    if(col==n)
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
                printf("%d\t",board[i][j]);
            printf("\n");
        }
        printf("\n");
        count++;
        return true;
    }
    return false;
}

int main()
{
    int n,i,j;
    int board[20][20];
    printf("Enter the no. of queens\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            board[i][j]=0;
    if(nQueenPossible(board,0,n))
        count++;
    if(count!=0)
        printf("No. of solution for %d queens is %d\n",n,count);
    else
        printf("Solution doesnot exist\n");
    return 0;
}

/*#include <stdio.h>

int  SIZE, MASK, COUNT;

void Backtrack(int y, int left, int down, int right)
{
    int  bitmap, bit;

    if (y == SIZE) {
        COUNT++;
    } else {
        bitmap = MASK & ~(left | down | right);
        while (bitmap) {
            bit = -bitmap & bitmap;
            bitmap ^= bit;
            Backtrack(y+1, (left | bit)<<1, down | bit, (right | bit)>>1);
        }
    }
}
int main(void)
{
    SIZE = 8;
    COUNT = 0;

    MASK = (1 << SIZE) - 1;
    Backtrack(0, 0, 0, 0);

    printf("N=%d -> %d\n", SIZE, COUNT);
    return 0;
}*/
