#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[20][20],i,j,n,min=0,p[20],mi;
    int count=0,u,v,c,b;
    printf("Enter the num of Nodes: ");
    scanf("%d",&n);
    printf("Enter the Adjacency Matrix:\n");
    printf("If there is no edge enter as 999\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d",&a[i][j]);
            p[i]=i;
        }
    }
    printf("EDGE;\n");
    while(count<n)
    {
        mi=999;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(a[i][j]<=mi && i!=j)
                {
                    mi=a[i][j];
                    u=c=i;
                    v=b=j;
                }
            }
        }
        while(p[u]!=u)
            u=p[u];
        while(p[v]!=v)
            v=p[v];
        if(u!=v)
        {
            printf("( %d, %d)\n",b,c);
            p[v]=u;
            min+=mi;
        }
        count++;
        a[c][b]=a[b][c]=999;
    }
    printf("\n \n Cost = %d\n",min);
    return 0;
}
