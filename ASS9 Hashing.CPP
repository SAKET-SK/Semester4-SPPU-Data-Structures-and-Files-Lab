#include<iostream>
#include<string.h>
#define MAX 10
using namespace std;
class Hashing
{
 struct Student
     {
       char Name[20];
       long int Mobile;
       int chain;
       Student()
       {
		Name[0]='\0';
		Mobile=chain=-1;
       }
       void Accept()
		{ 
			cout<<"\nStudent Name: ";
			cin>>Name;
	  		cout<<"\nMobile Number";
			cin>>Mobile; 
	    }
       void Display()
	{ cout<<"\t\t"<<Name<<"\t"<<Mobile<<"\t"<<chain;}
     };
 Student Hash_Table[MAX];
 public:
 Hashing();
 int Hash(long int);
 int Empty(int);
 void Chaing_WO_Replacement();
 void Chaing_W_Replacement();
};
Hashing::Hashing()
{
 for(int I=0;I<MAX;I++)
      Hash_Table[I].Mobile=Hash_Table[I].chain=-1;

}
int Hashing::Hash(long int Key)
{
  return Key%MAX;
}

//Find out empty location
//If Find Empty Location then return position else return -1
int Hashing::Empty(int Location)
{
 int I=Location;
 do
 { I++; I=I%MAX;
 }while(Hash_Table[I].Mobile!=-1 && I!=Location);
 return I;
}

//with chaining - without replacement
void Hashing::Chaing_WO_Replacement()
{
  int I=0,Location,Pos=-1,Flag=0;
  char Answer;
    Student Stu;
  cout<<"\nHash Key\tName\tMobile No\tchain";
  for(I=0;I<MAX;I++)
  { cout<<"\n"<<I<<"   ";Hash_Table[I].Display(); }
  cout<<"\nEnter Data: ";
  Stu.Accept();
  Location=Hash(Stu.Mobile);
  if(Hash_Table[Location].Mobile==-1)//Location is Empty
    Hash_Table[Location]=Stu;
  else
  {
     Pos=Empty(Location);
     if(Pos==Location)
	cout<<"Hash Table Full\n";
     else //hash table not full
     { //Present Key Hash==New Key Hash
      if(Hash(Hash_Table[Location].Mobile)==Hash(Stu.Mobile))
      {
       I=Location;
       while(Hash_Table[I].chain!=-1)  I=Hash_Table[I].chain;
       Hash_Table[Pos]=Stu ;Hash_Table[I].chain=Pos;
      }//if
     else//Present Key Hash != New Key Hash
      {
       I=Location+1;
       while((I%MAX)!=Location)
       { //search existing key hash same with the new key hash
	 I=I%MAX;
	if(Hash(Hash_Table[I].Mobile)== Hash(Stu.Mobile))
	 { Flag=1;  break;}
	I++;
       }//while
       if(Flag!=1) Hash_Table[Pos]=Stu;
       else
	 {
	   while(Hash_Table[I].chain!=-1)  I=Hash_Table[I].chain;
	   Hash_Table[Pos]=Stu;  Hash_Table[I].chain=Pos;
	  }

      }//else
    }//else hash table not full
 }
 cout<<"\nHash Key\tName\tMobile No\tchain";
 for(I=0;I<MAX;I++)
     { cout<<"\n"<<I<<"   ";Hash_Table[I].Display(); }
}

//with chaining - with replacement
void Hashing::Chaing_W_Replacement()
{
  int Pos,T,I=0,J,Location;
  Student Stu;
  I=0;
cout<<"\nHash Key\tStudent Name\tMobile No\tchain";
 for(I=0;I<MAX;I++)
  { cout<<"\n"<<I<<"   ";Hash_Table[I].Display(); }
  cout<<"\nEnter Data: ";
  Stu.Accept();
  Location=Hash(Stu.Mobile);
  if(Hash_Table[Location].Mobile==-1)
    Hash_Table[Location]=Stu;
  else
  {
   Pos=Empty(Location);
   if(Pos==Location) cout<<"Hash Table Full";
   else
   {
    if(Location==Hash(Hash_Table[Location].Mobile))
      {
	I=Location;
	while(Hash_Table[I].chain!=-1)  I=Hash_Table[I].chain;
	Hash_Table[Pos]=Stu;
	Hash_Table[I].chain=Pos;

      }
    else
      {
	I=Hash(Hash_Table[Location].Mobile);
	while(I!=Location)
	{ J=I;I=Hash_Table[I].chain;}
	Hash_Table[Pos] = Hash_Table[Location];
	Hash_Table[J].chain = Pos;
	Hash_Table[Location] = Stu;
      }
   }
 }
//   cout<<"\nHash Key\tStudent Name\tMobile No\tchain";
  for(I=0;I<MAX;I++)
     { cout<<"\n"<<I<<"   ";Hash_Table[I].Display();}
}

int main()
{
 int ch;
 char Answer;
 Hashing ch_W,ch_WO;
do
 {
  cout<<"\n1:Chaining without replacement\n2:Chaining with replacement\n3:Exit";
  cout<<"\nEnter choice:";
  cin>>ch;
  switch(ch)
  {
   case 1:
	  do
	    {
	       ch_WO.Chaing_WO_Replacement();
	       cout<<"\nMore...";
	       cin>>Answer;
	    }while(Answer=='y'||Answer=='Y');
	  break;
   case 2:
	  do
	    {
	       ch_W.Chaing_W_Replacement();
	       cout<<"\nMore...";
	       cin>>Answer;
	    }while(Answer=='y'||Answer=='Y');
	  break;
   }
}while(ch<3);
}
