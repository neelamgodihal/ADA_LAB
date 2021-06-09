#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int a[20][20],visited[20],n;
void dfs(int v)
{
	int i;
	visited[v]=1;
	for(i=1;i<=n;i++)
	if(a[v][i] && !visited[i])
	{
		printf("\n %d->%d",v,i);
		dfs(i);
	}
}

void main()
{
	int i,j,count=0;
	clock_t start_t,end_t;
	double total_t;
	printf("\n Enter number of vertices:");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		visited[i]=0;
		for(j=1;j<=n;j++)
		a[i][j]=0;
	}
	printf("\n Enter the adjacency matrix:\n");
	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
	scanf("%d",&a[i][j]);
	
	start_t=clock();
	dfs(1);
	printf("\n");
	for(i=1;i<=n;i++)
	{
		if(visited[i])
		count++;
	}
	end_t=clock();
	total_t=(double)(end_t-start_t)/CLOCKS_PER_SEC;
	
	if(count==n)
	printf("\n Graph is connected");
	else
	printf("\n Graph is not connected");

	printf("\nThe total time taken is %f\n",total_t);
}
