#include <stdio.h>
#include <stdlib.h>
#define N 20

int numbers[N];int top=-1;

int hasSubsetSol(int pos,int sum,int n,int *stk)
{
    int i;
    static int foundSol=0;
    if(sum>0)
        for(i=pos;i<n;i++)
        {
            stk[++top]=numbers[i];
            hasSubsetSol(i+1,sum-numbers[i],n,stk);
            top--;
        }
    if(sum==0)
    {
        for(i=top;i>=0;i--)
            printf("%d ",stk[i]);
        printf("\n");
        foundSol=1;
    }
    return foundSol;
}

int main()
{
    int i,n,sum;
    int stk[N];
    printf("Enter the number of elements you want?\n");
    scanf("%d",&n);
    printf("Enter numbers\n");
    for(i=0;i<n;i++)
        scanf("%d",&numbers[i]);
    printf("Enter the sum\n");
    scanf("%d",&sum);
    if(!hasSubsetSol(0,sum,n,stk))
        printf("No solution\n");
    else
        printf("The solutions possible is right in front of you\n");
    return 0;
}




