#include<iostream>
#include<cstring>
#define MAX 12          //defining max value as 12
#define TRUE 1
#define FALSE 0
using namespace std;
class Lgraph
{
	private:
	typedef struct node1
	{
		int vertex;
		int no_of_comments;
		char birthdate[40];
		struct node1 *next;
	}node;
	
	node *head[MAX];
	
	struct friendList
	{
		int no_of_friends;
		int no_of_comments;
		char birthdate[40];
	}friends[MAX];
	
	int visited[MAX];
	int Q[MAX],front,rear;
	
	public:
	Lgraph();
	void create();
	void bfs(int);
};
Lgraph::Lgraph()
{
	int v1;
	
	for(v1=0;v1< MAX;v1++)
		visited[v1]=FALSE;
	front=rear=-1;
	
	for(v1=0;v1<MAX;v1++)
		head[v1]=NULL;
}
void Lgraph::create()
{
	int v1,v2,c;
	char ans = 'y';
	node *New, *first;
	cout<<"\nEnter the user numbers beginning with 0";
	do
	{
		cout<<"\nEnter the two user numbers(1-10):- ";  //Input only 2 values at first, later we will add more edges
		cin>>v1>>v2;
		if(v1>=MAX || v2>=MAX)
			cout<<"\nInvalid vertex value!";
		else
		{
			New=new node;
			if(New==NULL)
				cout<<"\nInsufficient Data!";
			New->vertex=v2;
			New->next=NULL;
			first = head[v1];
			if(first==NULL)
				head[v1]=New;
			else
			{
				while(first->next!=NULL)
				first=first->next;
				first->next=New;
			}
			New=new node;
			if(New==NULL)
				cout<<"\nInsufficient Data!";
			New->vertex=v1;
			New->next=NULL;
			first=head[v2];
			if(first==NULL)
				head[v2]=New;
			else
			{
				while(first->next!=NULL)
					first=first->next;
				first->next=New;
			}
			cout<<"\nEnter no.of comments for user no. "<<v1<<":- ";
			cin>>c;
			head[v1]->no_of_comments=c;
			cout<<"\nEnter Birth Date(dd-mm-yyyy) for user no. "<<v1<<":- ";
			cin>>head[v1]->birthdate;
			cout<<"\nEnter no. of comments for user no."<<v2<<":- ";
			cin>>c;
			head[v2]->no_of_comments=c;
			cout<<"\nEnter Birth Date(dd-mm-yyyy)for user no. "<<v2<<":- ";
			cin>>head[v2]->birthdate;
		}
		cout<<"\nDo you want to add nore edges?(y/n):- ";
		cin>>ans;
	}while(ans=='y');
}

void Lgraph::bfs(int v1)
{
	int i,no_of_friends,n,max_friends,friend_node,choice;
	int max_comments, min_comments;
	char ans='y';
	char month[3],extract_month[MAX][3];
	node *first;
	Q[++rear]=v1;
	while(front!=rear)
	{
		i=Q[++front];
		if(visited[i]==FALSE)
		{
			visited[i]=TRUE;
		}
		first=head[i];
		friends[i].no_of_comments=head[i]->no_of_comments;
		strcpy(friends[i].birthdate,head[i]->birthdate);
		no_of_friends=0;
		while(first!=NULL)
		{
			if(visited[first->vertex]==FALSE)
			{
				Q[++rear]=first->vertex;
			}
			first=first->next;
			no_of_friends++;
		}
		friends[i].no_of_friends = no_of_friends;
	}
	n=i;
	cout<<"\nUser's_No\tNo.Of Friends\tNo.ofComments\t Birth Date";
	cout<<"\n ----------------------------------------------------------";
	for(i=0;i<=n;i++)
	{
		cout<<"\n" <<i<<"\t\t"<<friends[i].no_of_friends<<"\t\t"<<friends[i].no_of_comments<<"\t\t"<<friends[i].birthdate;
	}
	cout<<"\n -----------------------------------------------------------";
	do
	{
		cout<<"\n\n\t\tMenu";
		cout<<"\n1)Find who has max friends";
		cout<<"\n2)Find who has post max comments";
		cout<<"\n3)Find who has post min comments";
		cout<<"\n4)Enter the month to display birthdate";
		cout<<"\nEnter you choice code:- ";
		cin>>choice;
		switch(choice)
		{
			case 1:         //To find max friends
			friend_node= 0;
			max_friends=friends[0].no_of_friends;
			for(i=0;i<=n;i++)
			{
				if(max_friends < friends[i].no_of_friends)
				{
					max_friends=friends[i].no_of_friends;
					friend_node=i;
				}
			}
			cout<<"\n The user "<<friend_node<<" has max friends = "<<max_friends;
			break;
			
			case 2:         //To find max comments
			friend_node= 0;
			max_comments=friends[0].no_of_comments;
			for(i=0;i<=n;i++)
			{
				if(max_comments < friends[i].no_of_comments)
				{
					max_comments=friends[i].no_of_comments;
					friend_node=i;
				}
			}
			cout<<"\n The user "<<friend_node<<" has max comments = "<<max_comments;
			break;
			
			case 3:          //To find min comments
			friend_node= 0;
			min_comments=friends[0].no_of_comments;
			for(i=0;i<=n;i++)
			{
				if(min_comments > friends[i].no_of_comments)
				{
					min_comments=friends[i].no_of_comments;
					friend_node=i;
				}
			}
			cout<<"\n The user "<<friend_node<<" has min comments = "<<min_comments;
			break;
			
			case 4:                         //Display birthdate in particular month
			cout<<"\nEnter the month:- ";   
			cin>>month;
			for(int j=0;j<MAX;j++)
			{
				extract_month[j][0]=friends[j].birthdate[3];
				extract_month[j][1]=friends[j].birthdate[4];
				extract_month[j][2]='\0';
			}
			cout<<"\nDisplaying user's having birthday in this month...";
			for(i=0;i<=n;i++)
			{
				if(strcmp(month,extract_month[i])==0)
				{
					cout<<"\nUser no."<<i;
				}
			}
			break;
			
		}
		cout<<"\nDo you want to go to main menu?(y/n):- ";
		cin>>ans;
	}while(ans=='y' || ans=='Y');
}
int main()
{
	int v1;
	Lgraph gr;
	Lgraph();
	gr.create();
	cout<<"\nEnter vertex from which you want to traverse:- ";
	cin>>v1;
	if(v1>=MAX)
		cout<<"\nInvalid Vertex!";
	else
	{
		cout<<"\nThe BFS of Graph is:- ";
		gr.bfs(v1);
		return 0;
	}
}
