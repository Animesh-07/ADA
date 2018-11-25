#include <stdio.h>
#include <limits.h>
#define INT_MAX __INT_MAX__

int minKey(int *mstSet,int *key,int n)
{
    int minVal=INT_MAX,minIndex=0;
    int i;
    for(i=0;i<n;i++)
        if(!mstSet[i] && key[i]<minVal)
        {
            minVal=key[i];
            minIndex=i;
        }
    return minIndex;
}

void prims(int graph[20][20],int n)
{
    int mstSet[n];
    int key[n],i,j;
    for(i=0;i<n;i++)
    {
        key[i]=INT_MAX;
        mstSet[i]=0;
    }
    int parent[n];
    key[0]=0;
    parent[0]=-1;

    for(i=0;i<n-1;i++)  //here n-1(important)
    {
        int u=minKey(mstSet,key,n);
        mstSet[u]=1;

        for(j=0;j<n;j++)
        {
            if(graph[u][j] && !mstSet[j] && graph[u][j]<key[j])
            {
                key[j]=graph[u][j];
                parent[j]=u;
            }
        }
    }

    //printing
    for(i=1;i<n;i++)
        printf("%d---%d\nWeight = %d\n",parent[i],i,graph[i][parent[i]]);
}

int main()
{
    int graph[20][20];
    int i,j,n;
    printf("Enter the no of vertices you want\n");
    scanf("%d",&n);
    printf("Enter Adjacency Matrix:\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&graph[i][j]);
    prims(graph,n);
    return 0;
}
