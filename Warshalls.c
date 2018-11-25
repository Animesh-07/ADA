#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i,j,k;
    printf("Enter no of vertex:\t");
    scanf("%d",&n);
    int a[n+1][n+1];
    printf("Enter the adjacency matrix\n");
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            scanf("%d",&a[i][j]);
    for(k=1;k<=n;k++)
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                a[i][j]=a[i][j] || (a[i][k] && a[k][j]);
    printf("**********The required transitive closure is*************\n\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            printf("%d ",a[i][j]);
        printf("\n");
    }
    return 0;
}
