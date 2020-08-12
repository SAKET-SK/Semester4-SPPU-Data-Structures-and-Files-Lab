#include<iostream>
#include<cstring>
using namespace std;
int strcmp(char s[10],char country[10][10],int n)
{
	char *str;
	int i,j,fl;
	for(i=1;i<=n;i++)
	{
		str=country[i];
 		for(j=1;s[j]!='\0';j++)
 		{
 			if(s[j]!=str[j]&& s[j]!='\0')
 			{
 				fl=1;
 				break;
 			}
 			else
 				fl=0;
 		}
 		if(fl==0)
 		break;
	}
	return i;
}
int main()
{
	int n,i,j,cost[10][10],min,visit[10],u,v,total=0,ne=1,pos;
	char country[10][10],s[10];
	cout<<"Enter number of Countries==";
	cin>>n;
 	cout<<"\n Enter country who has office of Buisness house";
	for(i=1;i<=n;i++)
	{
		cin>>country[i];
	}
	for(i=1;i<=n;i++)
	{
		visit[i]=0;
	}
	cout<<"\n Enter rent charged by phone company to connect pairs of country";
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			cin>>cost[i][j];
			if(cost[i][j]==0)
				cost[i][j]=999;
		}
	}
	cout<<"Egdes of minimum spanning tree";
	cout<<"\nEnter the starting Country to connect lease line from:";
	cin>>s;
	pos=strcmp(s,country,n);
	visit[pos]=1;
	while(ne<n)
	{
		min=999;
		for(i=1;i<=n;i++)
		{
 			if(visit[i]==1)
 			{
				for(j=1;j<=n;j++)
				{
					if(cost[i][j]<min && visit[j]==0)
					{
						min=cost[i][j];
						u=i;
						v=j;
					}
				}
 			}//end if
		}
		if(u!=v)
		{
 			ne++;
			cout<<"\negde=="<<country[u]<<" to "<<country[v]<<"=="<<min;
			visit[u]=visit[v]=1;
			total+=min;
		}
	}
	cout<<"\n Minimum cost="<<total;
	return 0;
}
/*
Enter number of Countries==5
Enter country who has office of Buisness house
chin
india
usa
japan
italy
Enter rent charged by phone company to connect pairs of country
0 1 3 4 0
1 0 0 2 0
3 0 0 5 1
4 2 5 0 4
0 0 1 4 0
Egdes of minimum spanning tree
Enter the starting Country to connect lease line from:chin
egde==chin to india==1
egde==india to japan==2
egde==chin to usa==3
egde==usa to italy==1
Minimum cost=7
*/
