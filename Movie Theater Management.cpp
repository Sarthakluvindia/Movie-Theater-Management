#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<math.h>
#include<process.h>
#include<stdlib.h>
#include<dos.h>
#include<fstream.h>

//Below I'll list all the prototypes.

ofstream fo;
ifstream fi;//use the standard 2 streams change it everywhere in program
fstream fio;

void firstmenu();
void management();
void putempdata();//outside of class.
void modify();//for modifying data.    //check once by removing modify prototype.
void empaccess();
void custaccess();
void putmoviedata();//outside of class.

class employee
{
 char fname[50];
 char lname[50];
 int age;
 int birthdate;
 int birthmonth;
 int birthyear;
 int empno;
 int salary;
 char ch;

public:
void getempdata()
{
 clrscr();
 ch=' ';
 cout<<"\n Enter employee first name :";
 gets(fname);
 cout<<"\n Enter employee last name :";
 gets(lname);
 cout<<"\n Enter employee age :";
 cin>>age;
 cout<<"\n Enter employee birth date :";
 cin>>birthdate;
 cout<<"\n Enter employee birth month :";
 cin>>birthmonth;
 cout<<"\n Enter employee birth year :";
 cin>>birthyear;
 cout<<"\n Enter employee number :";
 cin>>empno;
 cout<<"\n Enter employee salary :";
 cin>>salary;
}

int getempno()//Have to use this in searching files.
{
 return empno;
}
void del();
void modify();
void display();
}emp,empdisplay;//empdisplay is especially for display purposes

void putempdata()
{
 emp.getempdata();
 fo.open("EmployeeData.Txt",ios::out | ios::binary);
 fo.write((char*)&emp,sizeof(employee));
 clrscr();
 cout<<"Storing Data";
 delay(3500);
 management();
}


void employee::modify()
{
 clrscr();
 cout<<"Current Details :\t";
 cout<<endl<<"Emp. No.:"<<empno;
 cout<<endl<<"Name :"<<endl;
 puts(fname);
 puts(lname);
 cout<<endl<<"Age :"<<age;
 cout<<endl<<"Salary :"<<salary;
 delay(3500);
 cout<<endl<<"Enter new details";
 getempdata();


}

void employee::del()
{
clrscr();
 int en;
 char ch;
 cout<<"\nEnter the employee number whose information is to be displayed";
 cin>>en;
 if(en==empno)
 {
 cout<<"\n Employee first name :";
 puts(fname);
 cout<<"\n Employee last name :";
 puts(lname);
 cout<<"\n Employee age :";
 cout<<age;
 cout<<"\n Employee birth date :";
 cout<<birthdate;
 cout<<"\n Employee birth month :";
 cout<<birthmonth;
 cout<<"\n Employee birth year :";
 cout<<birthyear;
 cout<<"\n Employee number :";
 cout<<empno;
 cout<<"\n Employee salary :";
 cout<<salary;
 cout<<"\n Are you sure you want to delete this record(y/n)";
 cin>>ch;
 if(ch=='y')
 {
 fi.open("EmployeeData.Txt",ios::in | ios::binary);
 fo.open("Temp.Txt",ios::out | ios::binary);
 while(fi.read((char*)&emp,sizeof(employee)))
 if(en!=empno)
 fo.write((char*)&emp,sizeof(employee));
 fi.close();
 fo.close();
 remove("EmployeeData.Txt");
 rename("Temp.Txt","EmployeeData.Txt");
 }
 else
 management();
 }
 }
void employee::display()
{
 clrscr();
 int ch,en;
 cout<<"\nEnter the employee number whose information is to be displayed";
 cin>>en;
 if(en==empno)
 {
 cout<<"\n Employee first name :";
 puts(fname);
 cout<<"\n Employee last name :";
 puts(lname);
 cout<<"\n Employee age :";
 cout<<age;
 cout<<"\n Employee birth date :";
 cout<<birthdate;
 cout<<"\n Employee birth month :";
 cout<<birthmonth;
 cout<<"\n Employee birth year :";
 cout<<birthyear;
 cout<<"\n Employee number :";
 cout<<empno;
 cout<<"\n Employee salary :";
 cout<<salary;
 cout<<"\n Press 1 for going back to menu or 2 for exiting";
 cin>>ch;
 if(ch==1)
 management();
 else
 {
 clrscr();
 cout<<"Exiting System";
	   delay(3000);
	   exit(0);
 }
}
else
{
cout<<"Wrong Choice";
management();
}
}



class movie
{
 char moviename[70];
 int agerestriction;
 int timeslot;//0 for no timeslot, 1 for 11 am , 2 for 2 pm , 3 for 5 pm , 4 for 8 pm.
 int moviecode;
 float ticketprice;

public:

void getmoviedata()
{
clrscr();

cout<<"Enter movie code :";
cin>>moviecode;
cout<<endl<<"Enter movie name :";
gets(moviename);
cout<<endl<<"Enter age limit :";
cin>>agerestriction;
cout<<endl<<"Enter timeslot (1->11am,2->2pm,3->5pm,4->8pm) :";
cin>>timeslot;
cout<<"Enter ticket price :";
cin>>ticketprice;

}

void displaymoviedata();

void modifymoviedata();

int getmoviecode()
{
 return moviecode;
}



}mov,movdisplay;//movdisplay is especially for display purposes


void putmoviedata()
{
 mov.getmoviedata();
 fo.open("MovieData.Txt",ios::out | ios::binary);
 fo.write((char*)&mov,sizeof(movie));
 clrscr();
 cout<<"Storing Data";
 delay(3500);
 empaccess();
}


void movie::modifymoviedata()
{

 clrscr();
 cout<<"Current Details :\t";
 cout<<endl<<"Movie Code :"<<moviecode;
 cout<<endl<<"Movie Name :"<<endl;
 puts(moviename);
 cout<<endl<<"Age Restriction :"<<agerestriction;
 cout<<endl<<"Ticket Price :"<<ticketprice;
 switch(timeslot)
 {

 case 1:cout<<"Timeslot : 11 am";
	       break;
 case 2:cout<<"Timeslot : 2 pm";
	       break;
 case 3:cout<<"Timeslot : 5 pm";
	       break;
 case 4:cout<<"Timeslot : 8 pm";
	       break;
 case 0:cout<<"Timeslot : not available";
	       break;

 }

delay(3500);
cout<<endl<<"Enter new details";
getmoviedata();


}


void movie::displaymoviedata()
{

 clrscr();
 cout<<endl<<"Movie Code :"<<moviecode;
 cout<<endl<<"Movie Name :"<<endl;
 puts(moviename);
 cout<<endl<<"Age Restriction :"<<agerestriction;
 cout<<endl<<"Ticket Price :"<<ticketprice;
 switch(timeslot)
 {

 case 1:cout<<"Timeslot : 11 am";
	       break;
 case 2:cout<<"Timeslot : 2 pm";
	       break;
 case 3:cout<<"Timeslot : 5 pm";
	       break;
 case 4:cout<<"Timeslot : 8 pm";
	       break;
 case 0:cout<<"Timeslot : not available";
	       break;

 }


}



void firstmenu()
{

  char ans1='0';//For the first menu.


 while(ans1=='0')
 {
  cout<<"                   Welcome To Carpe Diem Cinemas       "<<endl;
  cout<<"                            Data Center            "<<endl;
  cout<<endl<<endl<<" 1.Management Access \n 2.Employee Access \n 3.Exit "<<endl;
  cout<<endl<<"Choose your entry point(1/2/3) :";
  cin>>ans1;
 }

 switch(ans1)
 {
  case '1':delay(3000);
	   clrscr();
	   management();
	   break;

  case '2':delay(3000);
	   clrscr();
	   empaccess();
	   break;

  case '3':clrscr();
	   delay(3000);
	   cout<<"Exiting System";
	   delay(3000);
	   exit(0);
	   break;
 }



}

void management()
{

 clrscr();
 char ans2='0';//For Second Menu
 while(ans2=='0')
 {
  cout<<endl<<" 1.Enter employee data of a new employee. \n 2.Delete employee data. \n 3.Modify employee data. \n 4.Display the employee data. \n 5.Back. \n";
  cout<<"Enter your choice(1/2/3/4) :";
  cin>>ans2;
 }

 switch(ans2)
 {
  case '1':clrscr();
	   putempdata();

	   break;
  case '2':char ans3='0';//for delete one or delete all.
	   while(ans3=='0')
	   {
	     clrscr();
	     cout<<" 1.Delete a particular employee data. \n 2.Truncate all data. \n 3.Back. \n";
	     cout<<"Enter your choice(1/2/3) :";
	     cin>>ans3;
	    }
	    switch(ans3)
	    {
	     case '1':clrscr();
		      emp.del();
		     /* cout<<"Enter employee number of the employee whose data you want to delete :";
		      int tempempno;
		      cin>>tempempno;
		      fi.open("EmployeeData.Txt",ios::in | ios::binary);
		      fo.open("Temp.Txt",ios::out | ios::binary);
		      char found='f';
		      char confirm='n';
		      while(!fi.eof())
		      {
		       fi.read((char*)&emp,sizeof(employee));
		       if(emp.getempno()==tempempno)
		      {
			emp.display();
			found='t';
			cout<<endl<<"Are you sure, you want to delete this record ?(y/n)..";
			cin>>confirm;

			if(confirm=='n')
			 fo.write((char*)&emp,sizeof(employee));
		       }
		       else
			fo.write((char*)&emp,sizeof(employee));
		      }
		      if(found=='f')
		      {
		       clrscr();
		       cout<<"Record not found.";
		      }
		      fi.close();
		      fo.close();
		      remove("EmployeeData.Txt");
		      rename("Temp.Txt","EmployeeData.Txt");
		      fio.open("EmployeeData.Txt",ios::in | ios::out | ios::binary);
		      fio.seekg(0);
		      cout<<endl<<" Now the file contains :"<<endl;
		      while(!fio.eof())//This part is not working!!!!!
		      {
		       fio.read((char*)&emp,sizeof(employee));
		       emp.display();
		      }
		      fio.close();
		      break;*/
	     case '2':fo.open("EmployeeData.Txt",ios::trunc);
		      fo.close();
		      clrscr();
		      cout<<"Deleting all records.";
		      delay(5000); //5 seconds
		      clrscr();
		      management();
		      break;
	     case '3':management();
		      break;

	     //Add default;


	   }
	   break;
  case '3':clrscr();
	   cout<<"Enter employee number of the employee whose data you want to modify :";
	   int tempempno;
	   cin>>tempempno;
	   fio.open("EmployeeData.Txt",ios::in | ios::out | ios::binary);
	   long pos;//for modifying data;
	   char found='f';
	   while(!fio.eof())
	   {
	     pos=fio.tellg();
	     fio.read((char*)&emp,sizeof(employee));

	     if(emp.getempno()==tempempno)
	     {
	      emp.modify();
	      fio.seekg(pos);
	      fio.write((char*)&emp,sizeof(employee));
	      found='t';
	      break;
	     }
	   }
	   if(found=='f')
	   {
	    clrscr();
	    cout<<"Record not found.";
	   }
	   fio.seekg(0);
	   cout<<endl<<" Now the file contains :"<<endl;
	   while(!fio.eof())//This part is not working!!!!!
	   {
	    fio.read((char*)&emp,sizeof(employee));
	    emp.display();
	   }
	   fio.close();

	   break;
  case '4':/*fio.open("EmployeeData.Txt",ios::in | ios::out | ios::binary);
	   fio.seekg(0);
	   clrscr();
	   while(!fio.eof())//This part is not working!!!!!
	   {
	    fio.read((char*)&emp,sizeof(employee));
	    emp.display();
	   }
	   fio.close();*/
	   clrscr();
	   emp.display();

	   break;
  case '5':delay(2000);
	   clrscr();
	   firstmenu();
	   break;
 }


}




void empaccess()
{

clrscr();

char ans4='0';//for third menu
while(ans4=='0')
{
 cout<<endl<<" 1.Enter a new movie in database. \n 2.Remove a movie from database. \n 3.Modify movie data. \n 4.Back. \n";
 cout<<"Enter your choice (1/2/3/4):";
 cin>>ans4;
}

 switch(ans4)
 {
  case '1':clrscr();
	   putmoviedata();
	   break;

  case '2':char ans5='0';//for delete one or delete all.
	   while(ans5=='0')
	   {
	     clrscr();
	     cout<<" 1.Delete a particular movie record. \n 2.Truncate all data. \n 3.Back. \n";
	     cout<<"Enter your choice(1/2/3) :";
	     cin>>ans5;
	    }
	    switch(ans5)
	    {
	     case '1':clrscr();
		      cout<<"Enter movie code of the movie whose data you want to delete :";
		      int tempmoviecode;
		      cin>>tempmoviecode;
		      fi.open("MovieData.Txt",ios::in | ios::binary);
		      fo.open("Temp1.Txt",ios::out | ios::binary);
		      char found='f';
		      char confirm='n';
		      while(!fi.eof())
		      {

		       fi.read((char*)&mov,sizeof(movie));

		       if(mov.getmoviecode()==tempmoviecode)
		       {
			mov.displaymoviedata();


			found='t';
			cout<<endl<<"Are you sure, you want to delete this record ?(y/n)..";
			cin>>confirm;

			if(confirm=='n')
			 fo.write((char*)&mov,sizeof(movie));
		       }
		       else
			fo.write((char*)&mov,sizeof(movie));
		      }
			      if(found=='f')
		      {
		       clrscr();
		       cout<<"Record not found.";
		      }
		      fi.close();
		      fo.close();
		      remove("MovieData.Txt");
		      rename("Temp1.Txt","MovieData.Txt");
		      fio.open("MovieData.Txt",ios::in | ios::out | ios::binary);
		      fio.seekg(0);
		      cout<<endl<<" Now the file contains :"<<endl;
		      while(!fio.eof())//This part is not working!!!!!
		      {
		       fio.read((char*)&mov,sizeof(movie));
		       mov.displaymoviedata();
		      }
		      fio.close();
		      break;
	     case '2':fo.open("MovieData.Txt",ios::trunc);
		      fo.close();
		      clrscr();
		      cout<<"Deleting all records.";
		      delay(5000); //5 seconds
		      clrscr();
		      empaccess();
		      break;
	     case '3':empaccess();
		      break;

	     //Add default;


	   }
	   break;

  case '3':clrscr();
	   cout<<"Enter movie code of the movie whose data you want to modify :";
	   int tempmoviecode;
	   cin>>tempmoviecode;
	   fio.open("MovieData.Txt",ios::in | ios::out | ios::binary);
	   long pos;//for modifying data;
	   char found='f';
	   while(!fio.eof())
	   {
	     pos=fio.tellg();
	     fio.read((char*)&mov,sizeof(movie));

	     if(mov.getmoviecode()==tempmoviecode)
	     {
	      mov.modifymoviedata();
	      fio.seekg(pos);
	      fio.write((char*)&mov,sizeof(movie));
	      found='t';
	      break;
	     }
	   }
	   if(found=='f')
	   {
	    clrscr();
	    cout<<"Record not found.";
	   }
	   fio.seekg(0);
	   cout<<endl<<" Now the file contains :"<<endl;
	   while(!fio.eof())//This part is not working!!!!!
	   {
	    fio.read((char*)&mov,sizeof(movie));
	    mov.displaymoviedata();
	   }
	   fio.close();

	   break;

  case '4':delay(2000);
	   clrscr();
	   firstmenu();
	   break;

 }


}




void main()
{
 clrscr();

  fo.open("EmployeeData.Txt",ios::out | ios::binary);
  fo.close();
  firstmenu();

 getch();
}