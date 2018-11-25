#include <stdio.h>
#include <stdlib.h>

int a[20][20], reach[20], n;

void dfs(int v)
{
    int i;
    reach[v]=1;

    for(i=1;i<=n;i++)
    {
        if(a[v][i] && !reach[i])
        {
            printf("%d----->%d\n",v,i);
            dfs(i);
        }
    }
}
int main()
{
    int i,j,count=0,v;
    printf("\nEnter no. of vertices:\t");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        reach[i]=0;
        for(j=1;j<=n;j++)
            a[i][j]=0;
    }
    printf("\nEnter adjacency matrix: \n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
             scanf("%d",&a[i][j]);
        }
    }
    printf("\nEnter starting vertex:\t");
    scanf("%d",&v);
    dfs(v);
    for(i=1;i<=n;i++)
    {
        if(reach[i])
        count++;
    }
    printf("\n\n\n");
    if(count==n)
        printf("\nGraph is connected");
    else
        printf("\nGraph is not connected");
    printf("\n\n\n");
    return 0;
}
