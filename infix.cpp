#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;
class node
{
	public:
		char data;
		node *next;
};

class stack
{
	public:
		node *top;
		stack();
		void push(char c);
		char pop();
		int empty();                //Tells whether stack is empty or not
		char getTop();              //returns top most element
};

class exp_conversion
{
	public:
		infixToPostfix(char infix[], char postfix[]);
		int precedence(char c);
		int Eval_Postfix(char postfix[]);         //evalueates postfix operation
		int Eval_Prefix(char prefix[]);           //evalueates prefix opeartions
		int evaluate(char x, int op1, int op2);   //evalueation function
};

stack::stack() 
{
	top=NULL;
}
int stack::empty() 
{
	if(top==NULL)
		return 1;
	else
		return 0;
}

char stack::getTop() 
{
	if(top==NULL)
		return -1;
	else
		return top->data;
}

int exp_conversion::infixToPostfix(char infix[], char postfix[]) 
{
		stack s;
		char c, data;
		int i, j=0;
		for(i=0; infix[i]!='\0'; i++)
		{
			data=infix[i];
			if((data>='a' && data<='z') || (data>='A' && data<='Z') || (data>='0' && data<='9'))  /*if element is an operand, output it*/
			{
				postfix[j]=data;
				j++;
			}
			else if(data=='(')     /*if ( , push it onto stack*/
			{
				s.push(data);
			}
			else if(data==')')      /*if ), pop elements until  we get ( */
			{
				while(s.getTop()!='(' && !s.empty()) 
				{
					c=s.pop();
					postfix[j]=c;
					j++;
				}
				if(s.getTop()=='(')     /*if ( is on top of the stack, pop */
				{
					c=s.pop();
				}
			}
			else
			{
				while(precedence(data)<=precedence(s.getTop()) && !s.empty()) 
				{
					c=s.pop();
					postfix[j]=c;
					j++;
				}
				s.push(data);
			}
		}
		while(!s.empty())  //pop and output the remaining contents of the stack
		{
			c=s.pop();
			postfix[j]=c;
			j++;
		}
		postfix[j]='\0';
		return 0;
	
}
void stack::push(char c) 
{
	node *temp=new node;
	if(temp==NULL)
	{
		cout<<"Stack full";
	}
	temp->data=c;
	temp->next=top;
	top=temp;
}

char stack::pop() 
{
	if(top==NULL)
	{
		return -1;
	}
	else
	{
		node *temp=new node;
		char c;
		c=top->data;
		temp=top;
		top=top->next;
		temp->next=NULL;
		return c;
	}
}
int exp_conversion::precedence(char c) 
{
	if(c=='^')
		return 3;
	else if(c=='*' || c=='/')
		return 2;
	else if(c=='+' || c=='-')
		return 1;
	else
		return -1;
}


void reverse(char infix[],char rinfix[])
{
	int l=strlen(infix);
	int i,j=0;
	for(i=l-1;i>=0;i--)
	{
		if(infix[i]=='(')
		{
			rinfix[j]=')';
			j++;
		}
		else if(infix[j]==')')
		{
			rinfix[j]='(';
			j++;
		}
		else
		{
			rinfix[j]=infix[i];
			j++;
		}
	}
	rinfix[j]='\0';
}


int exp_conversion::evaluate(char x, int op1, int op2)   //function for evalueation
{
	if(x=='+')
		return(op1+op2);
	else if(x=='-')
		return(op1-op2);
	else if(x=='*')
		return(op1*op2);
	else if(x=='/')
		return(op1/op2);
	else if(x=='^')
		return(pow(op1,	op2));
	else
		return -1;
}



int exp_conversion::Eval_Postfix(char postfix[])  //evaluate postfix exp
{
	stack s;
	char x;
	int op1, op2, value, i;
	for(i=0; postfix[i]!='\0'; i++)
	{
	x=postfix[i];
		if(isalpha(x))       //if element is an operand, get the value and push
		{
			cout << "\nEnter the value of " << x << ": ";
			cin >> value;
			s.push(value);
		}
		else      //else, pop two operands, evaluate exp and push result in the stack
		{
			op2=s.pop();
			op1=s.pop();
			value=evaluate(x, op1, op2);
			s.push(value);
		}
	}
	value=s.pop();
	return value;
}

int exp_conversion::Eval_Prefix(char prefix[])    //evaluate prefix exp
{
	stack s;
	char x;
	int op1, op2, value, i, length=0;
	while(prefix[length]!='\0')  
	{
		length++;
	}
	for(i=length-1; i>=0; i--)
	{
		x=prefix[i];
		if(isalpha(x))     //if element is an operand, get the value and push
		{
			cout << "\nEnter the value of " << x << ": ";
			cin >> value;
			s.push(value);
		}
		else              //else, pop two operands, evaluate exp and push result on to stack
		{
			op1=s.pop();
			op2=s.pop();
			value=evaluate(x, op1, op2);
			s.push(value);
		}
	}
	value=s.pop();
	return value;
}
int main()
{
	exp_conversion exp;
	int res,ch;
	char ch1;
	char infix[50], postfix[50],prefix[50],rinfix[50];
	do{
		cout<<"\n***************EXPRESSION CONVERSION AND EVALUEATION******************";
		cout<<"\n1)Infix To PostFix\n2)Infix To PreFix\n3)Exit";
		cout<<"\nEnter your choice code:-";
		cin>>ch;
		switch(ch)
		{
			case 1:
				cout << "\nEnter infix exp:-";
				cin >> infix;
				res=exp.infixToPostfix(infix, postfix);
				if(res==-1)
				{
					cout << "\nInvalid exp!\n";
				}
				else
				{
					cout << "\nPostfix exp:-"<< postfix << endl;
					cout << "\nEvaluate postfix exp?(y/n):-";
					cin >>ch1;
					if(ch1=='y' || ch1=='Y')
					{
						res=exp.Eval_Postfix(postfix);
						cout << "\nValue of the exp is:-" << res << endl;
					}
				}
				break;
			
			case 2:
				cout << "\nEnter infix exp:-";
				cin >> infix;
					
				reverse(infix,rinfix);
				cout << "\nReverse infix exp:-"<<rinfix;
					
				res=exp.infixToPostfix(rinfix, postfix);
				if(res==-1)
				{
					cout << "\nInvalid exp!\n";
				}
				else
				{
					cout << "\nPostfix exp:-" << postfix << endl;
					reverse(postfix,prefix);
					cout << "\nPrefix exp:-"<<prefix;
					cout << "\nEvaluate prefix exp?(y/n):-";
					cin >> ch1;
					if(ch1=='y' || ch1=='Y')
					{
						res=exp.Eval_Prefix(prefix);
						cout << "\nValue of the exp is:-"<< res << endl;
					}
				}
				break;
			
			case 3:	break;
			
			default:
			{
				cout << "\nInvalid Input!\n";
				break;
			}			
		}
	}while(ch!=3);
}
