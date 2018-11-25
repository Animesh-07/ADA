#include <stdio.h>
#include <stdlib.h>

int min(int a,int b)
{
    if(a>b)
        return b;
    return a;
}

int main()
{
    int i,j,k,n;
    printf("Enter the number of vertex\n");
    scanf("%d",&n);
    int a[n+1][n+1];
    printf("Enter the weighted adjacency matrix\n");
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            scanf("%d",&a[i][j]);
    for(k=1;k<=n;k++)
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                a[i][j]=min(a[i][j],(a[i][k]+a[k][j]));
    printf("********The Required transitive closure is*************\n\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            printf("%d ",a[i][j]);
        printf("\n");
    }
    return 0;
}
