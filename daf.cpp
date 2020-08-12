#include<fstream>
#include<iostream>
#include<cstring>
using namespace std;
class emp
{
	typedef struct employee
	{
		char name[20];
		int empid;
		int sal;
		int link;
		int loc;
	}rec;
	rec rec1;
	
	public:
		int size;
		int chaintab[10][10];
		emp();
		void insert();
		void init();
		void display();
		void search();
		void chainwr();
		void modify();
		friend int hash(int);
};

emp::emp()
{
	strcpy(rec1.name," ");
	rec1.empid=-1;
	rec1.sal=-1;
	rec1.link=-1;
}

void emp::init()
{
	fstream seqfile;
	seqfile.open("xyz.txt",ios::out|ios::binary);
	cout<<"\n Enter Hash Table size";
	cin>>size;
	for(int i=0;i<size;i++)
	{
		strcpy(rec1.name," ");
		rec1.empid=-1;
		rec1.sal=-1;
		rec1.link=-1;
		rec1.link=i;
		seqfile.write((char*)&rec1,sizeof(rec1));
		for(int i=0;i<size;i++)
			for(int j=0;j<size;j++)
				chaintab[i][j]=-1;
	}
	cout<<"\n\n Hash table is initialized.";
	seqfile.close();
}

int hash(int num)
{
	int key;
	key=num%10;
	return key;
}

void emp::chainwr()
{
	fstream seqfile;
	int i,j,h,offset;
	seqfile.open("xyz.txt",ios::in|ios::out|ios::binary);
	for(i=0;i<size;i++)
	{
		h=i;
		for(j=0;j<size;j++)
		{
			if(chaintab[i][j]==1)
			{
				offset=h*sizeof(rec1);
				seqfile.seekg(offset);
				seqfile.read((char*)&rec1,sizeof(rec1));
				seqfile.seekp(offset);
				rec1.link=j;
				seqfile.write((char*)&rec1,sizeof(rec1));
				rec1.link=j;
				h=j;
 			}
 		}
	}
	seqfile.close();
}

void emp::insert()
{
	int i,h;
	char ch='y';
	char newname[10];
	int newempid;
	int newsal;
	fstream seqfile;
	init();
	seqfile.open("xyz.txt",ios::in|ios::out|ios::binary);
	do
	{
		cout<<"\n Enter Name:";
		cin>>newname;
		cout<<"\n Enter empid:";
		cin>>newempid;
		cout<<"\n Enter Salary:";
		cin>>newsal;
		h=hash(newempid);
		int offset;
		offset=h*sizeof(rec1);
		seqfile.seekg(offset);
		seqfile.read((char*)&rec1,sizeof(rec1));
		seqfile.seekp(offset);
		if(rec1.empid==-1)
		{
			strcpy(rec1.name,newname);
			rec1.empid=newempid;
			rec1.sal=newsal;
			rec1.link=-1;
			rec1.loc=h;
			seqfile.write((char*)&rec1,sizeof(rec1))<<flush;
 		}
 		else
 		{
			int flag=0;
			int prevlink=rec1.loc;
			do
 			{
				h++;
				if(h>size+1)
				{
					cout<<"\n Hash table is full.";
					return;
				}
				offset=h*sizeof(rec1);
				seqfile.seekg(offset);
				seqfile.read((char*)&rec1,sizeof(rec1));
				if(rec1.empid==-1)
				{
					seqfile.seekp(offset);
					strcpy(rec1.name,newname);
					rec1.empid=newempid;
					rec1.sal=newsal;
					rec1.link=-1;
					rec1.loc=h;
					seqfile.write((char*)&rec1,sizeof(rec1))<<flush;
					chaintab[prevlink][h]=1;
					flag=1;
				}
			}while(flag==0);
		}
		cout<<"\n Do you want to add more recs";
		cin>>ch;
		chainwr();
	}while(ch=='y');
	seqfile.close();
}

void emp::display()
{
	fstream seqfile;
	seqfile.open("xyz.txt",ios::in|ios::out|ios::binary);
	seqfile.seekg(0,ios::beg);
	cout<<"\n contents of file are..";
	cout<<"\nLoc\tName\tempid\tsal\tlink";
	while(seqfile.read((char*)&rec1,sizeof(rec1)))
	{
		if(strcmp(rec1.name," ")!=0)
		{
			cout<<"\n"<<rec1.loc<<"\t"<<rec1.name<<flush<<"\t"<<rec1.empid;
			cout<<"\t"<<rec1.sal<<"\t"<<rec1.link;
		}
	}
	seqfile.close();
}

void emp::search()
{
	fstream seqfile;
	int key,h,offset,flag=0;
	cout<<"\n Enter Emp id for searching the rec";
	cin>>key;
	seqfile.open("xyz.txt",ios::in|ios::binary);
	h=hash(key);
	while(seqfile.eof()==0)
	{
		offset=h*sizeof(rec1);
		seqfile.seekg(offset,ios::beg);
		seqfile.read((char*)&rec1,sizeof(rec1));
		if(key==rec1.empid)
		{
			cout<<"\n The rec is present in file";
			cout<<"\n Name:"<<rec1.name;
			cout<<"\n EmpId:"<<rec1.empid;
			cout<<"\n Emp Sal:"<<rec1.sal;
			flag=1;
			return;
		}
		else
		{
			h=rec1.link;
		}
	}
	if(flag==0)
	cout<<"\n The rec is not present in file";
	seqfile.close();
}

void emp::modify()
{
	int pos,no;
	cout<<"\n For updation";
	fstream seqfile;
	cout<<"\n Enter emp id for searching the record";
	cin>>no;
	seqfile.open("xyz.txt",ios::ate|ios::in|ios::out|ios::binary);
	seqfile.seekg(0,ios::beg);
	pos=-1;
	int i=0;
	while(seqfile.read((char*)&rec1,sizeof(rec1)))
	{
		if(no==rec1.empid)
		{
			pos=i;
			break;
		}
		i++;
	}
	if(pos==-1)
	{
		cout<<"\n The record is not present in the file";
		return;
	}
	int offset=pos*sizeof(rec);
	seqfile.seekp(offset);
	cout<<"\n Enter the values for updation..";
	cout<<"\n Name:";
	cin>>rec1.name;
	cout<<"\n Salary:";
	cin>>rec1.sal;
	seqfile.write((char*)&rec1, sizeof(rec1))<<flush;
	seqfile.seekg(0);
	seqfile.close();
	cout<<"\n The record is updated.";
}

int main()
{
	emp list;
	char ans='y';
	int ch,key;
	do
	{
		cout<<"\n--------------Main Menu--------------";
		cout<<"\n 1.Insert";
		cout<<"\n 2.Display";
		cout<<"\n 3.Search";
		cout<<"\n 4.Modify";
		cout<<"\n 5.Exit";
		cout<<"\n Enter your choice";
		cin>>ch;
		switch(ch)
		{
			case 1:
			list.insert();
			break;
			
			case 2:
			list.display();
			break;
			
			case 3:
			list.search();
			break;
			
			case 4:
			list.modify();
			break;
		}
		cout<<"\n Do u want to go back to main menu";
		cin>>ans;
	}while(ans=='y');
	return 0;
}
