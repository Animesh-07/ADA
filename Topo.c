//TOPOLOGICAL SORTING
#include <stdio.h>
#include <stdlib.h>

int temp[100],k=0;

void topo(int n,int indegree[],int a[][100])
{
    int i,j;
    for(i=1;i<=n;i++)
    {
        if(indegree[i]==0)
        {
            indegree[i]=-1;
            temp[++k]=i;
            for(j=1;j<=n;j++)
                if(indegree[j]!=0 && a[i][j]==1)
                    indegree[j]--;
            i=0;
        }
    }
}

int main()
{
    int i,j,n,indegree[100],a[100][100];
    printf("Enter the no of vertices:\n");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        indegree[i]=0;
    printf("Enter the adjacency matrix:\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d",&a[i][j]);
            if(a[i][j]==1)
                indegree[j]++;
        }
    }
    topo(n,indegree,a);
    if(k!=n)
        printf("\nTopological sorting not possible\n\n");
    else
    {
        printf("\n\nTopological sorting order:\n");
        for(i=1;i<=n;i++)
            printf("%d ",temp[i]);
        printf("\n");
    }
    return 0;
}
