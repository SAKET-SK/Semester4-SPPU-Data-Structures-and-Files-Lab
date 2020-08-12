#include<iostream>
#include<fstream>
using namespace std;
class student
{
	int roll_no;
	char name[20];
	int age;
	public:
		void getata(int i);
		void display();
};
void student::getata(int i)
{
	roll_no=i+1;
	cout<<"Enter the name:- ";
	cin>>name;
	cout<<"Enter the age:- ";
	cin>>age;
}
void student::display()
{
	cout<<roll_no<<"\t"<<name<<"\t"<<age<<"\n";
}
int main()
{
	int n,ch,location;
	cout<<"\nEnter no of records:- ";
	cin>>n;
	student s;
	fstream file;
	fstream file1,file2;
	do
	{
		cout<<"1)Create\n2)Display\n3)Search\n4)Modify\n5)Delete";
		cout<<"Enter your choice:- ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				cout<<":::::Create Record:::::";
				file.open("Sample.doc",ios::in|ios::out|ios::app);
				int i;
				for(i=0;i<n;i++)
				{
					s.getata(i);
					file.write((char *)&s,sizeof(s));
				}
				file.seekp(0);
				break;
				
			case 2:
				cout<<":::::Display Record:::::";
				cout<<"Roll_No"<<"\t"<<"Name"<<"\t"<<"age"<<"\n";
				while(file.read((char *)&s,sizeof(s)))
				{
					s.display();
				}
				//file.close();
				//file.open("Sample.doc",ios::in|ios::out|ios::app);
				if(file.eof())
				file.clear();
				break;
				
			case 3:
				cout<<":::::Search Record:::::";
				int search;
				cout<<"Enter record you want to search:- ";
				cin>>search;
				file.seekg(0);
				location=(search-1)*sizeof(s);
				//cout<<location;
				file.seekg(location,ios::beg);
				file.read((char*)&s,sizeof(s));
				s.display();
				if(file.eof())
					file.clear();
				file.close();
				break;
				
			case 4:
				cout<<":::::Modify Record:::::";
				file.open("Sample.doc",ios::in|ios::out|ios::ate);
				int modify;
				cout<<"Enter record to modify:- ";
				cin>>modify;
				file.seekg(0);
				location=(modify-1)*sizeof(s);
				file.seekp(location,ios::beg);
				s.getata(0);
				file.write((char*)&s,sizeof(s));
				file.seekp(0);
				cout<<"Roll_No"<<"\t"<<"Name"<<"\t"<<"age"<<"\n";
				while(file.read((char*)&s,sizeof(s)))
				{
					s.display();
				}
				file.close();
				break;
				
			case 5:
				cout<<":::::Delete Record:::::";
					int pos,del;
					file1.open("Sample.doc",ios::in|ios::ate);
					file2.open("Temp.doc",ios::out);
					cout<<"Enter the position of record to delete:- ";
					cin>>pos;
					file1.seekg(0);
					location=(del-1)*(sizeof(s));
					while(file1.read((char*)&s,sizeof(s)))
					{
						int pos=file1.tellg()-sizeof(s);
						if(pos==location)
						{
							
						}
						else
						{
							file2.write((char*)&s,sizeof(s));
						}
					}
					file1.close();
					file2.close();
					rename("Temp.doc","Sample.doc");
					break;
				
		}
	}while(ch!=6);
}
