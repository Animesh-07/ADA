#include <stdio.h>
#include <stdlib.h>

int a[20][20],b[20][20],q[20],visited[20],f=0,r=-1,i,n,j,v,m=0;

void bfs(int v) // utility function for bfs
{
    for(i=1;i<=n;i++)
    {
        if(b[v][i] && !visited[i])
        {
            b[i][v]=0;
            b[v][i]=0;
            printf("\t%d--->%d",v,i);
        }
    }
      for(i=1;i<=n;i++)
     {
          if(a[v][i] && !visited[i])
          {
                 q[++r]=i;
                 //printf("\t%d--->%d",v,i);
          }
     }
     if(f<=r)
     {
         visited[q[f]]=1;
         bfs(q[f++]);
     }
}
int main()
{
      printf("Enter the no. of vertices\n");
      scanf("%d",&n);
      for(i=1;i<=n;i++)
      {
          visited[i]=0;
          q[i]=0;
      }
      printf("Enter adjacency matrix for the graph\n");
      for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            scanf("%d",&a[i][j]);
      printf("Enter the starting vertex\n");
      scanf("%d",&v);
      for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            b[i][j]=a[i][j];
      printf("Path:\n");
      bfs(v);
      printf("\nNodes reachable from the given starting vertex %d is\n",v);
      for(i=1;i<=n;i++)
      {
            if(visited[i])
            {
                m=1;
                printf("\t%d",i);
            }
      }
      if(m==0)
          printf("\n\nGraph is not connected\n");
      else if(m==1)
                printf("\n\nGraph is connected\n");
     return 0;
}
