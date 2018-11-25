#include <stdio.h>
#include <limits.h>

int minDistance(int *mstSet,int *dist,int n)
{
    int minVal=INT_MAX,minIndex=0;
    int i;
    for(i=0;i<n;i++)
        if(!mstSet[i]&&dist[i]<minVal)
        {
            minVal=dist[i];
            minIndex=i;
        }
    return minIndex;
}

void dijkstra(int graph[20][20],int n)
{
    int i,j;
    int mstSet[n];
    for(i=0;i<n;i++)
        mstSet[i]=0;
    int dist[n];
    for(i=0;i<n;i++)
        dist[i]=INT_MAX;
    int parent[n];
    dist[0]=0;
    parent[0]=-1;

    for(i=0;i<n-1;i++)  //here n-1(important)
    {
        int u=minDistance(mstSet,dist,n);
        mstSet[u]=1;
        for(j=0;j<n;j++)
        {
            if(graph[u][j] && !mstSet[j] && dist[u]!=INT_MAX && (dist[u]+graph[u][j])<dist[j])
            {
                dist[j]=graph[u][j]+dist[u];
                parent[j]=u;
            }
        }
    }
    //printing
    for(i=1;i<n;i++)
        printf("%d distance = %d\n",i,dist[i]);
}

int main()
{
    int graph[20][20];
    int n,i,j;
    printf("Enter the no of vertices you want\t");
    scanf("%d",&n);
    printf("Enter the Adjacency Matrix :\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&graph[i][j]);
    dijkstra(graph,n);
    return 0;
}
