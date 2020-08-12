#include<iostream>
using namespace std;

class tree
{
	int data;
	tree *l_child,*r_child;
	public:
		void insert(tree **);
		void display(tree *);
		void leaf_node(tree *);
		void height(tree *);
};

void tree::insert(tree **root)
{
	char ch;
	tree *newnode,*temp=*root;
	newnode=new tree;
	cout<<"\nEnter data:-";
	cin>>newnode->data;
	newnode->l_child=NULL;
	newnode->r_child=NULL;
	if(*root==NULL)
		*root=newnode;
	else
	{
		while(1)
		{
			cout<<"\nEnter the side you want to insert(LEFT->[L,l],RIGHT->[R,r])of "<<temp->data<<" ?:-";
			cin>>ch;
			if(ch=='L'||ch=='l')	
			{
				if(temp->l_child==NULL)                   //check if left child is null
				{
					temp->l_child=newnode;                //then newnode is left child 
					return;
				}
				else
					temp=temp->l_child;	                  //else go to the left of left child
			}
			if(ch=='R'||ch=='r')
			{
				if(temp->r_child==NULL)                   //check if right child is null
				{
					temp->r_child=newnode;                //then right child is newnode
					return;
				}
				else
					temp=temp->r_child;                   //else move to the right of right child
			}
		}	
	}
}

void tree::display(tree *root)
{
	if(root==NULL)                      //displaying inorder traversal of a tree
		return;
	else
	{
		display(root->l_child);
		cout<<root->data<<"\t";
		display(root->r_child);
		
	}
}

void tree::leaf_node(tree *root)      //function to obtain leaf nodes (STACKS used)
{
	int i=0;
	tree *stack[10];                 //declare an stack pointer capacity of 10
	tree *temp=root;                 //set temp pointer to root
	if(root==NULL)
		cout<<"Tree Empty";
	else
	{
		stack[i++]=temp;             //if tree is not null, sacn the element and push onto stack
		while(i>0)
		{
			temp=stack[--i];         //pop elements other than leaf nodes
			while(temp!=NULL)
			{
				if(temp->l_child==NULL & temp->r_child==NULL)   //condition for leaf node
				{
					cout<<temp->data<<"\t";
				}
				if(temp->r_child!=NULL)             //if right child is present
				{
					stack[i++]=temp->r_child;       //push it onto stack
				}
				temp=temp->l_child;                 //if above is false,point to left child
													//this while loop will give node close to bottom
			}
		}
	}
}

void tree::height(tree *root)
{
	int i=0,size=0,height=0,front=0;
	tree *queue[10],*temp=root;         //(QUEUE used)declare a queue and set root as temp pointer
	if(root==NULL)
		cout<<"\n Height of tree is 0";
	else
	{
		queue[i++]=temp;               //if root is not null,insert element in queue
		size++;                        //increase size of queue
		height=0;                      //but not height
		while(size>0)                  //continue the loop till size not becomes zero
		{
			
			while(size>0)
			{
				temp=queue[front++];         //pop the element;Assign to temp first
				size--;                      //decrease the size
				if(temp->l_child)
				{
					queue[i++]=temp->l_child;      //insert left child in case of temp is left child
					
				}
				if(temp->r_child)
				{
					queue[i++]=temp->r_child;      //insert right child in case of temp is right child
					
				}
			}
			size=i-front;                     
			height++;
		}
		
	}
	cout<<"\nHeight of tree is:-"<<height;
	cout<<"\n";
}
int main()
{
	int ch;
	tree t,*root=NULL;
	do
	{
		cout<<"\n----------------------BINARY TREE OPEARTIONS--------------------";
		cout<<"\n1)Insert Data in Binary Tree\n2)Display Data in Binary Tree\n3)Print Leaf Nodes\n4)Height of tree";
		cout<<"\nEnter your choice code:-";
		cin>>ch;
		switch(ch)
		{
			case 1:
					t.insert(&root);
					break;
			case 2:
					t.display(root);
					break;
			case 3:
					t.leaf_node(root);
					break;
			case 4:
					t.height(root);
					break;
			case 5:
					exit(0);
		}
	}while(ch!=5);
}
