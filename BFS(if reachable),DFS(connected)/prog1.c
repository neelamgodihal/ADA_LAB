#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int a[20][20],q[20],visited[20],n,i,j,f=0,r=-1;
void bfs(int v)
{
	for(i=1;i<=n;i++)
	if(a[v][i] && !visited[i])
	q[++r]=i;
	if(f<=r)
	{
		visited[q[f]]=1;
		bfs(q[f++]);
	}
}
void main()
{
	int v;
	clock_t start_t,end_t;
	double total_t;
	
	printf("\n Enter the number of vertices:");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		q[i]=0;
		visited[i]=0;
	}
	printf("\n Enter the adjacency matrix:\n");
	
	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
	scanf("%d",&a[i][j]);
	
	printf("\n Enter the starting vertex:");
	scanf("%d",&v);
	start_t=clock();
	bfs(v);
	end_t=clock();
	total_t=(double)(end_t-start_t)/CLOCKS_PER_SEC;
	
	printf("\n The node which are reachable are:\n");
	for(i=1;i<=n;i++)
	if(visited[i])
	printf("%d\t",i);
	
	printf("\nThe total time taken for is %f\n",total_t);
	
}
