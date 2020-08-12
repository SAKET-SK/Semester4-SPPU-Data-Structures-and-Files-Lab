#include <iostream>
using namespace std;
class node           
{
    public:
        char name[30];
        int priority;
        node *next;
        node()                    //Initializing name,priority and next pointer values
        {
        	name[0]='\0';          
		    priority=-1;
		    next=NULL;
		}
};

class Priority_Queue                             
{
        node *front,*rear;
    public:
        Priority_Queue()
        {
        	front=rear=NULL;
		}
        void enqueue();
        void dequeue();
        void display();
};

int main()
{
    Priority_Queue pq;
    int ch;

    do
    {
    	cout<<"\n***********PATIENT MANAGEMENT**************\n";
        cout<<"1)Admit\n2)Release\n3)Display\n4)Exit";
		cout<<"\nEnter your choice code:-";
        cin>>ch;

        switch(ch)
        {
            case 1:
                {
                    pq.enqueue();
                    break;
                }
            case 2:
                {
                    pq.dequeue();
                    break;
                }
            case 3:
                {
                    pq.display();
                    break;
                }
            case 4: 
				break;
				
            default:
                {
                    cout << "\nInvalid Choice!\n";
                    break;
                }
        }
    }
    while(ch!=4);
}

void Priority_Queue::display()                                //function to display patient list
{
    if(front==NULL)
    {
        cout << "\nQueue is Empty\n";
    }
    else                                              
    {
        int Sr_No=1;
        node *temp=front;
        cout<<"*********Priority Wise Patient Details**********";
        cout<<"\nSr_No\tName\t\tPriority of Patient";
        cout<<"\n************************************************";
        while(temp!=NULL)
        {
            cout<<"\n"<<Sr_No<<"     |"<<temp->name<<"    |\t\t";
            if(temp->priority==1)
            {
                cout<<"Serious\n";
                cout<<"----------------------------------------------";
            }
            else if(temp->priority==2)
            {
                cout << "Medium\n";
                cout<<"----------------------------------------------";
            }
            else
            {
                cout << "Normal\n";
                cout<<"----------------------------------------------";
            }
            Sr_No++;
            temp=temp->next;
        }
    }
}
void Priority_Queue::enqueue()                                    //function to add new entry in the queue
{
    node *p=new node;
    cout<<"\nEnter patient's name:-";
    cin>>p->name;
    cout<<"1)Serious\n2)Medium\n3)Normal";
	cout<<"\nSelect priority:- ";
    cin>>p->priority;

    if(rear==NULL)             
    {
        p->next=NULL;
        front=rear=p;
    }
    else if(p->priority < front->priority)        //priority check
    {
        p->next=front;
        front=p;
    }
    else                                    //insert patient accroding to priority
    {
        node *temp=front, *prev;
        while((temp->priority <= p->priority) && temp->next!=NULL)         
        {
            prev=temp;
            temp=temp->next;
        }
        if(temp->next==NULL && (temp->priority <= p->priority))     //if patient is the last element in the queue
        {
            temp->next=p;
            p->next=NULL;
            rear=p;
        }
        else
        {
            p->next=temp;
            prev->next=p;
        }
    }
    cout << "\nPatient Admitted!\n";
}

void Priority_Queue::dequeue()                    //function to remove an entry from queue
{
    if(front==NULL)    
    {
        cout<<"\nQueue is empty\n";
    }
    else
    {
        cout<<"\nDeleted Entry\n";
        cout<<"\nName:-"<<front->name;
        cout<<"\nPriority:-";
        switch(front->priority)
        {
            case 1:
                {
                    cout <<"Patient is of Serious Priority\n";
                    break;
                }
            case 2:
                {
                    cout <<"Patient is of Medium Priority\n";
                    break;
                }
            case 3:
                {
                    cout <<"Patient is of Normal priority\n";
                    break;
                }
        }

        node *temp=front;           
        front=front->next;
        delete(temp);
    }
}


