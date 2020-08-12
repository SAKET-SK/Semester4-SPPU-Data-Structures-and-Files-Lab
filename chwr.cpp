//Chaining without replacement
#include<iostream>
#define h(x)x%size
#define size 10
using namespace std;
void insert (int data[20],int flag[20],int chain[],int x)
{
int start,i,j;
start=h(x);
while(flag[start]==0 && i<size)
{
if(data[start]%size==x%size)
break;
i++;
start=(start+1)%size;
}
if(i==size)
cout<<"table is full";
while(chain[start]!=-1)
start=chain[start];
j=start;
while(flag[j]==0 && i<size)
{
j=(j+1)%size;
i++;
}
if(i==size)
{
cout<<"table full";
return;
}
data[j]=x;
flag[j]=0;
if(j!=start)
chain[start]=j;
}
int main()
{
int i,n,flag[10],data[10],chain[10],x;
cout<<"enter the element u want to insert ";
cin>>n;
for(i=0;i<size;i++)
{
flag[i]=1;
chain[i]=-1;
data[i]='\0';
}
for(i=0;i<n;i++)
{
cin>>x;
insert(data,flag,chain,x);
}
cout<<"\n i data \t chain";
for(i=0;i<size;i++)
{
cout<<"\n"<<i;
if(data[i]=='\0')
cout<<"\t -";
else
cout<<"\t"<<data[i];
cout<<"\t"<<chain[i];
}
return 0;
}
