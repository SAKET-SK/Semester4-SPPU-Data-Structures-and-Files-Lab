//Hashing with replacement
#include <iostream>
using namespace std;
#define size 10
#define h(x) x%size
void insert(int data[],int flag[],int x)
{
int i,j,key;
int start;
start=h(x);
j=start;
if(flag[j]==1)
{
data[j]=x;
flag[j]=0;
return;
}
if(h(data[j])!=h(x))
{
while(flag[j]==0 && i<size)
{
j=(j+1)%size;
i++;
}
if(i==size)
cout<<"table is full";
data[j]=data[start];
data[start]=x;
flag[j]=0;
}
i=0;
if(h(data[j])==h(x))
{
while(flag[j]==0 && i<size)
{
j=(j+1)%size;
i++;
}
if(i==size)
cout<<"table is full";
data[j]=x;
flag[j]=0;
}
}
int main()
{
int i,n;
int data[10],flag[10],x;
cout<<"\n enter the no of elements";
cin>>n;
for(i=0;i<size;i++)
{
flag[i]=1;
 data[i]='\0';
}
for(i=0;i<n;i++)
{
cin>>x;
insert(data,flag,x);
}
cout<<"i data"<<" "<<"flag";
for(i=0;i<size;i++)
{
cout<<"\n"<<i;
if(data[i]=='\0')
cout<<"\t -";
else
cout<<"\t"<<data[i];
cout<<"\t"<<flag[i];
}
return 0;
}
