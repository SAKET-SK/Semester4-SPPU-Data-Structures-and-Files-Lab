/******************************************
 Assignemnt No.:-09
Store data of students with telephone no and name in the structure using hashing function for 
telephone number and implement chaining with and without replacement.

***************************************************/

#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;
#define MAX 10

//Hash Table with Chaining
class chaining
{
   	struct student
   	{
      		long long int phone_no;
      		char sname[20];
      		int chain;
   	};
   	student ht[MAX];
  	public:
  
  	//Constructor :Initializing telephone no. and chain info. with -1 and name as empty string
  	chaining()
  	{
     		for(int i=0;i<MAX;i++)
     		{
       			ht[i].phone_no=ht[i].chain=-1;
       			strcpy(ht[i].sname,"");
     		}
  	}
  
  	void add_rec_without_rep(); //add a record with chaining and without replacement
  	void add_rec_with_rep(); //add a record with chaining and with replacement
  	void display();     // Display records present in hash table
  	int find_hash_value(long long int phoneno); //computes hash key
};

//compute hash key as sum of digits of phone number%10
int chaining::find_hash_value(long long int phoneno)
{
   	int sum=0;
   	int rem, key;
   	long long int temp=0;
   	temp=phoneno;
    	while(temp!=0)	//calculate the sum of digits
    	{
       		rem=temp % 10;
       		sum=sum+rem;
       		temp=temp/10;
    	}
       	key=sum%10 ; // calculate the hash value
    	return key;    
}

// insert student record in hashtable with chaining and without replacement

void chaining::add_rec_without_rep()
{
	int no,i,j,k;
   	long long int phoneno;
   	char name[MAX];
   	char ans;
   	do
   	{
      		cout<<"\nEnter the telephone no: "<<endl;
      		cin>>phoneno;
      		cout<<"\nEnter the student name: "<<endl;
      		cin>>name;
      		k=i=find_hash_value(phoneno);
       		if(ht[i].phone_no==-1)	//if the hashed index is empty, store the data
      		{
            		ht[i].phone_no=phoneno;
            		strcpy(ht[i].sname,name);
      		}
      		else
      		{
         		do //find an empty location
         		{
               			k=(k+1)%10;
         		}
			while(k!=i && ht[k].phone_no!=-1);
         		if(i==k)
         		{
            			cout<<"\nSorry. Cannot Insert. Hash table is full!!"<<endl;
            			return;
         		}
         		else
          		{
              			ht[k].phone_no=phoneno;
              			strcpy(ht[k].sname,name);
              			//check for synonym
              			if((find_hash_value(ht[i].phone_no))==(find_hash_value(ht[k].phone_no)))
              			{
                 			while(ht[i].chain!=-1)
                 			{
	                  			i=ht[i].chain;
                 			}
                  			ht[i].chain=k;
              			}
             			cout<<"Inserted at Location "<<k<<endl;
          		}//else inner
     		}//else main
		display();
		cout<<"Do you want to add more? (y/n) "<<endl;
		cin>>ans;
	}
	while(ans=='y');
}//end of addwithoutrecord function

// insert student record in hashtable with chaining and with replacement
void chaining::add_rec_with_rep()
{
  	int no,i,j,k;
  	long long int phoneno;
  	char name[MAX];
  	char ans;
  	do
  	{
      		cout<<"\nEnter the telephone no: "<<endl;
      		cin>>phoneno;
      		cout<<"\nEnter the student name: "<<endl;
      		cin>>name;
      		k=i=find_hash_value(phoneno);
      		if(ht[i].phone_no==-1)
      		{
            		ht[i].phone_no=phoneno;
            		strcpy(ht[i].sname,name);
      		}
      		else
      		{
           		do
           		{
              			k=(k+1)%10;
           		}
			while(k!=i && ht[k].phone_no!=-1);
          		if(i==k)
          		{
             			cout<<"\nSorry. Cannot Insert. Hash table is full!!"<<endl;
             			return;
          		}
          		if(find_hash_value(ht[i].phone_no)==i)
          		{
             			ht[k].phone_no=phoneno;
             			strcpy(ht[k].sname,name);
             			//check for synonym
            			if((find_hash_value(ht[i].phone_no))==(find_hash_value(ht[k].phone_no)))
            			{
                			while(ht[i].chain!=-1) //reach end of chain
                			{
	                			i=ht[i].chain;
                			}
                			ht[i].chain=k;
             			}
            			cout<<"\nInserted at Location "<<k;
          		}//end of inner if
          		else
          		{
             			cout<<"\nVal "<<ht[i].phone_no <<" should be replaced from Location "<<i;
             			ht[k].phone_no=ht[i].phone_no;
             			strcpy(ht[k].sname,ht[i].sname);
             			ht[k].chain=ht[i].chain;
                         	j=find_hash_value(ht[i].phone_no);
             			while(ht[j].chain!=i)
             			{
                 			j=ht[j].chain;
             			}
              			ht[j].chain=k;
               			ht[i].phone_no=phoneno;
              			strcpy(ht[i].sname,name);
              			ht[i].chain=-1;
              			cout<<"\nValue is added at Location "<<i<<endl;
          		}//end of inner else
       		}//end of outer else
 		display();
 		cout<<"Do you want to add more? (y/n) "<<endl;
 		cin>>ans;
	}
	while(ans=='y');
}//end of add_rec_with_rep()



// Display records present in hash table
void chaining::display()
{
   	cout<<"Location\tPhone_no\tName\t\tChain"<<endl;
   	for(int i=0;i<MAX;i++)
   	{
   		cout<<i<<"\t\t"<<ht[i].phone_no<<"\t\t"<<ht[i].sname<<"\t\t"<<ht[i].chain<<endl;
   	}
}
 
int main()
{
    	chaining htc,htcr;
    	int ch;
    	do
    	{
      		cout << "\n1. Chaining Without Replacement \n2. Chaining With Replacement \n3. Exit";
      		cout <<"\nEnter your choice:";
      		cin >> ch;
            	switch(ch)
      		{
          		case 1: htc.add_rec_without_rep(); //chaining without replacement
                  		break;
          		case 2: htcr.add_rec_with_rep();   // chaining with replacement
                  		break;
          		case 3: exit(0);
                  		break;
          		default: cout << "\nWrong Choice";
      		}
    	}
	while(ch!=3);
   	return 0;
}

/*******OUTPUT***********

bvcoew@bvcoew-Lenovo-S510:~$ cd Desktop/rn35
bvcoew@bvcoew-Lenovo-S510:~/Desktop/rn35$ g++ ass9.cpp
bvcoew@bvcoew-Lenovo-S510:~/Desktop/rn35$ ./a.out

1. Chaining Without Replacement 
2. Chaining With Replacement 
3. Exit
Enter your choice:1

Enter the telephone no: 
8698233456

Enter the student name: 
Neha
Location	Phone_no	Name		Chain
0		-1				-1
1		-1				-1
2		-1				-1
3		-1				-1
4		8698233456		Neha		-1
5		-1				-1
6		-1				-1
7		-1				-1
8		-1				-1
9		-1				-1
Do you want to add more? (y/n) 
y

Enter the telephone no: 
7030687536

Enter the student name: 
nisha
Location	Phone_no	Name		Chain
0		-1				-1
1		-1				-1
2		-1				-1
3		-1				-1
4		8698233456	Neha		-1
5		7030687536	nisha		-1
6		-1				-1
7		-1				-1
8		-1				-1
9		-1				-1
Do you want to add more? (y/n) 
y

Enter the telephone no: 
8698234365

Enter the student name: 
Ruchi
Inserted at Location 6
Location	Phone_no	Name		Chain
0		-1				-1
1		-1				-1
2		-1				-1
3		-1				-1
4		8698233456	Neha		6
5		7030687536	nisha		-1
6		8698234365	Ruchi		-1
7		-1				-1
8		-1				-1
9		-1				-1
Do you want to add more? (y/n) 
y

Enter the telephone no: 
8624024087

Enter the student name: 
pooja
Location	Phone_no	Name		Chain
0		-1				-1
1		8624024087	pooja		-1
2		-1				-1
3		-1				-1
4		8698233456	Neha		6
5		7030687536	nisha		-1
6		8698234365	Ruchi		-1
7		-1				-1
8		-1				-1
9		-1				-1
Do you want to add more? (y/n) 
y

Enter the telephone no: 
8600242478

Enter the student name: 
sneha
Inserted at Location 2
Location	Phone_no	Name		Chain
0		-1				-1
1		8624024087	pooja		2
2		8600242478	sneha		-1
3		-1				-1
4		8698233456	Neha		6
5		7030687536	nisha		-1
6		8698234365	Ruchi		-1
7		-1				-1
8		-1				-1
9		-1				-1
Do you want to add more? (y/n) 
y

Enter the telephone no: 
9911889271

Enter the student name: 
Komal
Inserted at Location 7
Location	Phone_no	Name		Chain
0		-1				-1
1		8624024087	pooja		2
2		8600242478	sneha		-1
3		-1				-1
4		8698233456	Neha		6
5		7030687536	nisha		7
6		8698234365	Ruchi		-1
7		9911889271	Komal		-1
8		-1				-1
9		-1				-1
Do you want to add more? (y/n) 
y

Enter the telephone no: 
7030685763

Enter the student name: 
aarti
Inserted at Location 8
Location	Phone_no	Name		Chain
0		-1				-1
1		8624024087	pooja		2
2		8600242478	sneha		-1
3		-1				-1
4		8698233456	Neha		6
5		7030687536	nisha		7
6		8698234365	Ruchi		-1
7		9911889271	Komal		8
8		7030685763	aarti		-1
9		-1				-1
Do you want to add more? (y/n) 
y

Enter the telephone no: 
8308520746

Enter the student name: 
Krutika
Location	Phone_no	Name		Chain
0		-1				-1
1		8624024087	pooja		2
2		8600242478	sneha		-1
3		8308520746	Krutika		-1
4		8698233456	Neha		6
5		7030687536	nisha		7
6		8698234365	Ruchi		-1
7		9911889271	Komal		8
8		7030685763	aarti		-1
9		-1				-1
Do you want to add more? (y/n) 
y               

Enter the telephone no: 
8528300674

Enter the student name: 
Rina
Inserted at Location 9
Location	Phone_no	Name		Chain
0		-1				-1
1		8624024087	pooja		2
2		8600242478	sneha		-1
3		8308520746	Krutika		9
4		8698233456	Neha		6
5		7030687536	nisha		7
6		8698234365	Ruchi		-1
7		9911889271	Komal		8
8		7030685763	aarti		-1
9		8528300674	Rina		-1
Do you want to add more? (y/n) 
y         

Enter the telephone no: 
9850575435

Enter the student name: 
aditi
Inserted at Location 0
Location	Phone_no	Name		Chain
0		9850575435	aditi		-1
1		8624024087	pooja		2
2		8600242478	sneha		0
3		8308520746	Krutika		9
4		8698233456	Neha		6
5		7030687536	nisha		7
6		8698234365	Ruchi		-1
7		9911889271	Komal		8
8		7030685763	aarti		-1
9		8528300674	Rina		-1
Do you want to add more? (y/n) 
y         

Enter the telephone no: 
986745231 

Enter the student name: 
shruti

Sorry. Cannot Insert. Hash table is full!!

1. Chaining Without Replacement 
2. Chaining With Replacement 
3. Exit
Enter your choice:2

Enter the telephone no: 
8308520743

Enter the student name: 
Pooja
Location	Phone_no	Name		Chain
0		8308520743	Pooja		-1
1		-1				-1
2		-1				-1
3		-1				-1
4		-1				-1
5		-1				-1
6		-1				-1
7		-1				-1
8		-1				-1
9		-1				-1
Do you want to add more? (y/n) 
y         

Enter the telephone no: 
9011889273

Enter the student name: 
Payal
Location	Phone_no	Name		Chain
0		8308520743	Pooja		-1
1		-1				-1
2		-1				-1
3		-1				-1
4		-1				-1
5		-1				-1
6		-1				-1
7		-1				-1
8		9011889273	Payal		-1
9		-1				-1
Do you want to add more? (y/n) 
y

Enter the telephone no: 
8624024085

Enter the student name: 
Jiya
Location	Phone_no	Name		Chain
0		8308520743	Pooja		-1
1		-1				-1
2		-1				-1
3		-1				-1
4		-1				-1
5		-1				-1
6		-1				-1
7		-1				-1
8		9011889273	payal		-1
9		8624024085	Jiya		-1
Do you want to add more? (y/n) 
y         

Enter the telephone no: 
9011882739

Enter the student name: 
varsha

Inserted at Location 1
Location	Phone_no	Name		Chain
0		8308520743	Pooja		-1
1		9011882739	varsha		-1
2		-1				-1
3		-1				-1
4		-1				-1
5		-1				-1
6		-1				-1
7		-1				-1
8		9011889273	payal		1
9		8624024085	Jiya		-1
Do you want to add more? (y/n) 
y

Enter the telephone no: 
8890117239

Enter the student name: 
Kajal

Inserted at Location 2
Location	Phone_no	Name		Chain
0		8308520743	Pooja		-1
1		9011882739	varsha		2
2		8890117239	Kajal		-1
3		-1				-1
4		-1				-1
5		-1				-1
6		-1				-1
7		-1				-1
8		9011889273	Payal		1
9		8624024085	Jiya		-1
Do you want to add more? (y/n) 
y

Enter the telephone no: 
8308520347

Enter the student name: 
Swati

Inserted at Location 3
Location	Phone_no	Name		Chain
0		8308520743	Pooja		3
1		9011882739	varsha		2
2		8890117239	Kajal		-1
3		8308520347	Swati		-1
4		-1				-1
5		-1				-1
6		-1				-1
7		-1				-1
8		9011889273	Payal		1
9		8624024085	Jiya		-1
Do you want to add more? (y/n) 
y         

Enter the telephone no: 
7239818109

Enter the student name: 
Riya

Inserted at Location 4
Location	Phone_no	Name		Chain
0		8308520743	Pooja		3
1		9011882739	varsha		2
2		8890117239	Kajal		4
3		8308520347	Swati		-1
4		7239818109	Riya		-1
5		-1				-1
6		-1				-1
7		-1				-1
8		9011889273	Payal		1
9		8624024085	Jiya		-1
Do you want to add more? (y/n) 
y

Enter the telephone no: 
7685935460

Enter the student name: 
Teju

Val 8308520347 should be replaced from Location 3
Value is added at Location 3
Location	Phone_no	Name		Chain
0		8308520743	Pooja		5
1		9011882739	varsha		2
2		8890117239	Kajal		4
3		7685935460	Teju		-1
4		7239818109	Riya		-1
5		8308520347	Swati		-1
6		-1				-1
7		-1				-1
8		9011889273	Payal		1
9		8624024085	Jiya		-1
Do you want to add more? (y/n) 
y

Enter the telephone no: 
8976354275

Enter the student name: 
Tiya
Location	Phone_no	Name		Chain
0		8308520743	Pooja		5
1		9011882739	varsha		2
2		8890117239	Kajal		4
3		7685935460	Teju		-1
4		7239818109	Riya		-1
5		8308520347	Swati		-1
6		8976354275	Tiya		-1
7		-1				-1
8		9011889273	Payal		1
9		8624024085	Jiya		-1
Do you want to add more? (y/n) 
y         

Enter the telephone no: 
7865647394

Enter the student name: 
manasi

Inserted at Location 7
Location	Phone_no		Name		Chain
0		8308520743		Pooja		5
1		9011882739		varsha		2
2		8890117239		Kajal		4
3		7685935460		Teju		-1
4		7239818109		Riya		-1
5		8308520347		Swati		-1
6		8976354275		Tiya		-1
7		7865647394		manasi		-1
8		9011889273		Payal		1
9		8624024085		Jiya		7
Do you want to add more? (y/n) 
y

Enter the telephone no: 
9867452324

Enter the student name: 
Gita

Sorry. Cannot Insert. Hash table is full!!

1. Chaining Without Replacement 
2. Chaining With Replacement 
3. Exit
Enter your choice:3
bvcoew@bvcoew-Lenovo-S510:~/Desktop/rn35$ */
