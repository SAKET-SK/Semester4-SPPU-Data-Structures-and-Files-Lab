/*Construct and expression tree from postfix/prefix expression and perform recursive and non-recursive Inorder , preorder  and postorder traversals.*/
#include<iostream>
using namespace std;

class tree
{
	public:
	char data;
	tree *left,*right;
    tree(char c)
      {
          data=c;
          left=right=NULL;
       }
};
class stack
{
	tree *stk[20];        //stack of 20 elements
	int top;

	public:
	stack()
	{
		top=-1;
	}

	int isempty();
	int isfull();
	void push(tree*);
	tree* pop();
};
int stack::isempty()
{
	if(top==-1)
		return 1;
	return 0;
}

int stack::isfull()
{
	if(top==19)             //as stack contains 20 elements,it will go 0-19
		return 1;
	return 0;
}

void stack::push(tree *d)
{
	if(!isfull())             //if stack not full, then push data onto the stack
		stk[++top]=d;
}

tree* stack::pop()
{
	tree *temp=stk[top];     //temp points to top
	top--;                   //delete the pointed top
	return temp;
}

tree *create()
{
	char post_exp[25];
	int i=0;
	stack s;
	cout<<"**********EXPRESSION CONVERSION**********";
	cout<<"\n Enter the Postfix expresion:-  ";
	cin>>post_exp;
	while(post_exp[i]!='\0')
	{
		tree *node=new tree(post_exp[i]);
		if(isalnum(post_exp[i]))
			s.push(node);
		else
		{
			node->right=s.pop();
			node->left=s.pop();
			s.push(node);
		}
		i++;
	}
	return s.pop();
}

void intrav(tree *root)              //RECURSIVE INORDER
{
	if(root!=NULL)
	{
		intrav(root->left);
		cout<<root->data;
		intrav(root->right);
	}
}
void pretrav(tree *root)            //RECURSIVE PREODER
{
	if(root!=NULL)
	{
		cout<<root->data;
		pretrav(root->left);
		pretrav(root->right);
	}
}

void posttrav(tree *root)          //RECURSIVE POSTORDER
{
	if(root!=NULL)
	{
		posttrav(root->left);
		posttrav(root->right);
		cout<<root->data;
	}
}

void nonpre(tree *root)               //NON RECURSIVE PREORDER
{
	stack s;
	while(!s.isempty()||root!=NULL)
	{
		while(root!=NULL)
		{
			cout<<root->data;
			s.push(root);
			root=root->left;
		}
		root=s.pop();
		root=root->right;
	}
}

void nonrin(tree *root)               //NON RECURSIVE INORDER
{
	stack s;
	while(!s.isempty()||root!=NULL)
	{
		while(root!=NULL)
		{
			s.push(root);
			root=root->left;
		}
		root=s.pop();
		cout<<root->data;
		root=root->right;
	}
}

void nonpost(tree *root)             //NON RECURSIVE POSTORDER
{
	stack s;
	int i=0;
	char str[20];
	while(!s.isempty()||root!=NULL)
	{
		while(root!=NULL)
		{
			str[i++]=root->data;
			s.push(root);
			root=root->right;
		}
		root=s.pop();
		root=root->left;
	}
	while(--i>=0)
	cout<<str[i];
}

int main()
{
struct tree *root=NULL;
char ch='y';
int choice;

root=create();
do
{
	cout<<"\n1)Preorder Traversal\n2)Inorder Traversal\n3)Postorder Traversal\n";
	cout<<"Enter your choice code:- ";
	cin>>choice;
	switch(choice)
	{
	case 1:
		cout<<"\n-----------------------";
		cout<<"\nRECURSIVE Preorder:- ";  
		pretrav(root);
		cout<<"\n-----------------------";
	
		cout<<"\n----------------------";
		cout<<"\nNON-RECURSIVE Preorder:- ";
		nonpre(root);
		cout<<"\n-----------------------";
		break;
	
	case 2:
		cout<<"\n-----------------------";
		cout<<"\nRECURSIVE Inorder:- ";
		intrav(root);
		cout<<"\n-----------------------";
	
		cout<<"\n----------------------";
		cout<<"\nNON-RECURSIVE Inorder:- ";
		nonrin(root);
		cout<<"\n-----------------------";
		break;

	case 3:
		cout<<"\n----------------------";
		cout<<"\nRECURSIVE Postorder:- ";
		posttrav(root);
		cout<<"\n-----------------------";
	
		cout<<"\n------------------------";
		cout<<"\nNON-RECURSIVE Postorder:- ";
		nonpost(root);
		cout<<"\n-----------------------";
		break;
	
	default:
		cout<<"\nInvalid Choice...Please Enter Again!";
	break;
}
cout<<"\nDo u want to continue(y/n) :- ";
cin>>ch;
}while(ch=='y'||ch=='Y');

return 1;
}
