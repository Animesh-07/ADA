//KNAPSACK 0/1

#include <stdio.h>
#include <stdlib.h>

int max(int a,int b)
{
    if(a>b)
        return a;
    return b;
}

void knapsack(int n,int *w,int *p,int m)
{
	int v[10][10],i,j;
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=m;j++)
        {
            if(i==0||j==0)
                v[i][j]=0;
            else if(j<w[i])
                v[i][j]=v[i-1][j];
            else
                v[i][j]=max(v[i-1][j],v[i-1][j-w[i]]+p[i]);
        }
    }
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=m;j++)
            printf("%d\t",v[i][j]);
        printf("\n");
    }
    printf("\n\nThe Optimised value is:\t%d\n",v[n][m]);
}
int main()
{
    int w[10],p[10],m,n,i;
    printf("\nEnter the number of items:\n");
    scanf("%d",&n);
    printf("\nEnter the capacity of knapsack:\n");
    scanf("%d",&m);
    printf("\nEnter the weight of the items:\n");
    for(i=1;i<=n;i++)
        scanf("%d",&w[i]);
    printf("\nEnter the value of the items:\n");
    for(i=1;i<=n;i++)
        scanf("%d",&p[i]);
    printf("\nTHE TABLE IS :\n\n");
    knapsack(n,w,p,m);
    return 0;
}
