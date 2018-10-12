//============================================================================
// Name        : assign1.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

/*write c++ program to store marks for first test on data structure and algorithm for n students. Compute
  1)avg score of class
  2)highest score and lowest score of class
  3)marks scored by most of the students
  4)list of students who were absent for the test*/
#include<iostream>
#include<cstring>
using namespace std;
int i,ns;
class Student
{
 int count;
 string name;
 string rno;
 float marks;
 int absent;
 public:
 static float most_scored;
 static float max,min,sum;
 static float avg;
 void getdata();
 void printdata();
 friend void calculate();
}s[30];

float Student :: most_scored;
float Student :: max=0;
float Student :: min=30;
float Student :: sum=0;
float Student :: avg;

void Student :: getdata()
  {
 cout<<"\nEnter Student Details";
 cout<<"\nName:";
 getline(cin >> ws,name);
 cout<<"\nRoll no.:";
 cin>>rno;
  int invalid;
  do
  {
  cout<<"\nEnter marks out of 30.If absent enter any negative value";
  cin>>marks;
  if(marks>30)
   {
    invalid=1;
   cout<<"Invalid input.Re-enter marks";
   }
  if(marks<0)
   {
    marks=0;
    absent=1;
   }
  }while(invalid!=0);
 }

void Student :: printdata()
 {
 cout<<"\nName:"<<name;
 cout<<"\nRoll no.:"<<rno;
 cout<<"\nMarks(out of 30):"<<marks<<endl;
 }


void calculate()
{
	int t=1,hit=0;
// calculating average
 for(i=0;i<ns;i++)
 {
 Student :: sum = Student :: sum + s[i].marks;
 }
 Student :: avg=Student :: sum/ns;
 cout<<"Average score of class is :"<<Student :: avg<<endl;
 //calculating max score
 for(i=0;i<ns;i++)
 {
  if(Student :: max< s[i].marks && s[i].absent!=1)
   {
    Student :: max = s[i].marks;
   }
 }
 cout<<"\nMaximum score of class is:"<<Student :: max;
 //calculating min score
 for(i=0;i<ns;i++)
 {
  if(Student :: min > s[i].marks && s[i].absent!=1)
   {
    Student :: min = s[i].marks;
   }
 }
 cout<<"\nMinimum score of class is:"<<Student :: min<<endl;
//calculating marks scored by most of the students
 for(i=0;i<ns;i++)
 {
	for(int j=0;j<ns;j++)
	{
		if(s[i].marks==s[j].marks)
		{
			s[i].count++;
		}
	}
	if(t<s[i].count)
	{
	  Student::most_scored=s[i].marks;
	}
 }
cout<<"\nMarks scored by most of students is:"<<Student::most_scored<<endl;
//Displaying list of absent students
cout<<"\nList of absent students:"<<endl;
for(i=0;i<ns;i++)
 {
	if(s[i].absent==1)
	{       hit++;
		cout<<hit<<")"<<s[i].name<<" - "<<s[i].rno<<endl;
	}
 }
 if(hit==0)
 {
	 cout<<"\nThere were no absent students for the test"<<endl;
 }
}

int main()
{

  int choice;
  do
  {
    cout<<"\n1.Read data";
    cout<<"\n2.Calculate and display";
    cout<<"\n3.Display read data";
    cout<<"\n4.Exit";
    cout<<"\nEnter your choice:";
    cin>>choice;
    switch(choice)
    {
      case 1: {
               cout<<"\nEnter total no. of students:";
               cin>>ns;
               for(i=0;i<ns;i++)
               {
                s[i].getdata();
               }
               break;
              }
      case 2: {
                calculate();
                break;
              }
      case 3: {
                cout<<"\nStudent Details:";
                for(i=0;i<ns;i++)
                {
                  s[i].printdata();
                }
               break;
              }
      case 4:  break;
      default: cout<<"\nEnter valid choice";
  }
 }while(choice!=4);
return 0;
}
