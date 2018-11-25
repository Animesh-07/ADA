//BIONOMIAL COEFFICIENT

#include <stdio.h>
#include <stdlib.h>

int min(int a,int b)
{
    if(a<b)
        return a;
    return b;
}

int main()
{
    int n,k,i,j;
    printf("Enter the value of n & k to find BINOMIAL Coefficient C(n,k)\t");
    scanf("%d %d",&n,&k);
    int C[n+1][k+1];
    for(i=0;i<=n;i++)
        for(j=0;j<=min(i,k);j++)
            if(j==0 || j==i)
                C[i][j]=1;
            else
                C[i][j]=C[i-1][j-1]+C[i-1][j];
    printf("\nC(%d,%d) = %d\n",n,k,C[n][k]);
    return 0;
}
