#include<iostream>
using namespace std;
void kruskal(int w[10][10],int n)
{
	int i,j,min,ne=1,u,v,a,b,sum=0;
	char p[10];
	for(i=1;i<=n;i++)
	{
		p[i]=0;
	}
	while(ne < n)
	{
		min=999;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(w[i][j] < min)
				{
					min=w[i][j];
					u=a=i;
					v=b=j;
				}
			}
		}
		if(p[u])
		{
			u=p[u];
		}
		if (p[v])
		{
			v=p[v];
		}
		if(u!=v)
		{
			ne++;
			sum=sum+min;
			cout<<"\n edge "<<a<<" to "<<b<<" "<<min;
			p[v]=u;
		}
		w[a][b]=w[b][a]=999;
	}
	cout<<"\nMinimum distance is:- ";
	cout<<sum;
}
int main()
{
	int n,i,j,w[10][10];
	cout<<"\nEnter the no of vertices:- ";
	cin>>n;
	cout<<"\nMatrix is:-\n";
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			cin>>w[i][j];
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(w[i][j]==0)
			{
				w[i][j]=999;
			}
		}
	}
	kruskal(w,n);
	return 0;
}

/*OUTPUT:=
enter the no of vertices
3
matrix is:
0 1 1
1 0 1
1 1 0
edge 1 to 2 1
minimum distance is:1
*/
