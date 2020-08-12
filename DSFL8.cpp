#include <iostream>
using namespace std;
void dij(int s,int d,int adj[10][10],int n)
{
	int pre[10], dist[10], visit[10],i,j,current,newdist,flag=0,opt_dist;
	for(i=0;i<n;i++)
	{
		pre[i]=0;
		dist[i]=999;
		visit[i]=0;
	}
	visit[s]=1;
	dist[s]=0;
	current=s;
	while(current!=d)
	{
		for(j=0;j<n;j++)
		{
			if(adj[current][j]>0 && visit[j]==0)
			{
				newdist= dist[current]+ adj[current][j];
				if(newdist<=dist[j])
				{
					dist[j]=newdist;
					pre[j]=current;
				}
			}
		}
		int min=999;
		current=0;
		for(i=0;i<n;i++)
		{
			if(dist[i]<min && visit[i]==0)
			{
				min=dist[i];
				flag=1;
				current=i;
			}
		}
		if(flag==1)
		{
			visit[current]=1;
		}
		opt_dist=dist[d];
	}
	cout<<"\nSHORTEST DISTANCE IS==>"<<opt_dist;
	j=current;
	cout<<j;
	do
	{
		j=pre[j];
		cout<<"<-"<<j;
	}while(j!=s);
}
int main()
{
	int n,s,d,adj[10][10];
	cout<<"Enter the number of nodes=>";
	cin>>n;
	cout<<"\nEnter Adjacency matrix\n";
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>adj[i][j];
		}
	}
	cout<<"\nEnter Source:- ";
	cin>>s;
	cout<<"\nEnter Destination:- ";
	cin>>d;
	dij(s,d,adj,n);
	return 0;
}
/*
Enter the number of node=>5
Adjacency matrix
0 10 0 30 100
10 0 50 0 0
0 50 0 20 10
30 0 20 0 60
100 0 10 60 0
Source0
Destination4
SHORTEST DISTANCE IS==>60
4<-2<-3<-0
*/
