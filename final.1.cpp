
                                                  // PROGRAM TO CREATE STUDENT RESULT MANAGEMENT SYSTEM
#include<conio.h>
#include<iostream>
#include<cstdlib>
#include<fstream>
using namespace std;

// defination of class.........
class student
{
 private:
 string s_name,m_name,f_name,c_name,cr_name,roll_no,rgln,dd,mm,yy,grade,result;
 float per;
 int cg,dbms,coil,mlt,cd,sum;
 public:
       void menu();
       void insert();
       void display();
       void deleted();
};

// defination of menu function.........
void student::menu()
{   start:
	system("cls");
	int choice;
	char x;
    
	cout<<"\n\n\t\t\t\t-------------------------------------"<<endl;
	cout<<"\t\t\t\t |    STUDENT MANAGEMENT SYSTEM    | "<<endl;
    cout<<"\t\t\t\t-------------------------------------"<<endl;	
    cout<<"\t\t\t\t 1. Enter New Record "<<endl;
    cout<<"\t\t\t\t 2. display Record "<<endl;
    cout<<"\t\t\t\t 3. Delete Record "<<endl;
    cout<<"\t\t\t\t 4. Exit "<<endl;
    
    cout<<"\t\t\t\t-------------------------------------"<<endl;
    cout<<"\t\t\t\t  Choose Option : [ 1 / 2 / 3 / 4 ]"<<endl;
    cout<<"\t\t\t\t-------------------------------------"<<endl;
    cout<<" --> Please Enter Your Choice : ";
    cin>>choice;
    
    switch(choice)
    {
    	case 1:
    	do
    	{
    		insert();
    		cout<<"\n--> Add New Record (y/n)";
    		cin>>x;
		}while(x=='Y'||x=='y');
    	break;
		
	    case 2:
	   	display();
	   	break;
	   	
	   	case 3:
	   		deleted();
	   		break;
	   		
		case 4:
			exit(0);
		default:
			cout<<"\n-->Invalid Choice..!! Please Try Again "<<endl;
			
	}
	getch();
    goto start;
}

// defination of insert function... to add student records.......
void student::insert()
{
   fstream file;
   system("cls");
   cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;	
   cout<<"\t\t\t\t\t\t | Add Student Details |"<<endl;
   cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;
   
   cout<<"\t\t\t--> Enter Your Name : ";
   cin>>s_name;
   cout<<"\t\t\t--> Enter Mother Name : ";
   cin>>m_name;
   cout<<"\t\t\t--> Enter Father Name : ";
   cin>>f_name;
   cout<<"\t\t\t--> Enter collage Name : ";
   cin>>c_name;
   cout<<"\t\t\t--> Enter Course Name : ";
   cin>>cr_name;
   cout<<"\t\t\t--> Enter Roll Number  : ";
   cin>>roll_no;
   cout<<"\t\t\t--> Enter Regulation : ";
   cin>>rgln;
   cout<<"\t\t\t--> Enter Birth Date (DD/MM/YY) : ";
   cin>>dd>>mm>>yy;
   
   cout<<"\t\t\t-----------------------------------------------"<<endl;	
   cout<<"\t\t\t\t Enter Your Marks Subject Wise "<<endl;
   cout<<"\t\t\t-----------------------------------------------"<<endl;	
   cout<<"\t\t\t--> CG  : ";
   cin>>cg;
   cout<<"\t\t\t--> DBMS  : ";
   cin>>dbms;
   cout<<"\t\t\t--> COIL  : ";
   cin>>coil;
   cout<<"\t\t\t--> MLT  : ";
   cin>>mlt;
   cout<<"\t\t\t--> CD  : ";
   cin>>cd;
   
// calculate total marks, percentage and grade..........
   sum=cg+dbms+coil+mlt+cd;
   per=sum/5;
   if(per>=80)
   {
   	 grade="A";
   	 result="PASS";
   }
   else if(per>=60)
   {
   	grade="B";
   	result="PASS";
   }
   else if(per>=35)
   {
   	grade="C";
   	result="PASS";
   }
   else
   {
   	grade="-";
   	result="FAIL";
   }
   
 // creating a file STUDENTRESULT.TXT to store the records of stuednts........
   file.open("studentresult.txt",ios::out | ios::app);
   file<<" "<<s_name<<" "<<f_name<<" "<<m_name<<" "<<c_name<<" "<<cr_name<<" "<<roll_no<<" "<<rgln<<" "<<dd<<" "<<mm<<" "<<yy<<" "<<cg<<" "<<dbms<<" "<<coil<<" "<<mlt<<" "<<cd<<" "<<sum<<" "<<per<<" "<<grade<<" "<<result<<"\n";
   file.close();
    
}

// defination of display function........
void student::display()
{
	system("cls");
	fstream file;
	
   cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;	
   cout<<"\t\t\t\t\t\t | Student Result Table |"<<endl;
   cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;
   
   file.open("studentresult.txt",ios::in);
   if(!file)
   {
      cout<<"\n\t\t\t No Data Is Found ......";
	  file.close();	
   
   }
   else
   {
   	   file>>s_name>>f_name>>m_name>>c_name>>cr_name>>roll_no>>rgln>>dd>>mm>>yy>>cg>>dbms>>coil>>mlt>>cd>>sum>>per>>grade>>result;
   	   while(!file.eof())
   	   {
   	   	
   	   	
   		 cout<<"\n\n\t CLASS  : "<<cr_name<<endl;
   		 cout<<"\t COLLAGE  : "<<c_name<<endl;
   		 
   		 
   		 cout<<"\n\n\t STUDENT'S NAME : "<<s_name;
   		 cout<<"\t\t\t\t\t ROLL NO : "<<roll_no<<endl;
   		 cout<<"\n\t MOTHER'S NAME : "<<m_name;
   		 cout<<"\t\t\t\t\t DATE OF BIRTH : "<<dd<<" / "<<mm<<" / "<<yy<<endl;
   		 cout<<"\n\t FATHER'S NAME : "<<f_name;
   		 cout<<"\t\t\t\t\t Regulation : "<<rgln<<endl;
   		 
   		 cout<<"\n\t+----------------------------------------------------------------------------------------+";               //whole structure of the result table........
   		 cout<<"\n\t|   Subject Name      |\t  Marks Obtained  |\tOut-Of   |  Percentage   |\tGrade    |";
   		 cout<<"\n\t+----------------------------------------------------------------------------------------+";
   		 cout<<"\n\t|\t CG           |\t     "<<cg<<"           |\t"<<100 <<"\t |"<<"\t\t |"<<"\t\t |"<<endl;
   		 cout<<"\t| \t DBMS         |\t     "<<dbms<<"           |\t"<<100 <<"\t |"<<"\t\t |"<<"\t\t |"<<endl;
   		 cout<<"\t| \t COIL         |\t     "<<coil<<"           |\t"<<100 <<"\t |"<<"\t"<<per<<"%\t |\t"<<grade<<"\t |"<<endl;
   		 cout<<"\t| \t MLT          |\t     "<<mlt<<"           |\t"<<100 <<"\t |"<<"\t\t |"<<"\t\t |"<<endl;
   		 cout<<"\t| \t CD           |\t     "<<cd<<"           |\t"<<100 <<"\t |"<<"\t\t |"<<"\t\t |"<<endl;
   		 cout<<"\t+----------------------------------------------------------------------------------------+";
   		 cout<<"\n\t\t\t\t Total - "<<sum<<"\t\t\t RESULT - "<<result<<endl;
   	
   		cout<<"\n\n\t Dated : ";
   		cout<<"\t\t\t\t\t\t   Principle Signatures : "<<endl;
   		
   		cout<<"\n\n\t-----------------------------------------------------------------------------------------------------";
   		
   		file>>s_name>>f_name>>m_name>>c_name>>cr_name>>roll_no>>rgln>>dd>>mm>>yy>>cg>>dbms>>coil>>mlt>>cd>>sum>>per>>grade>>result;
	   }	   
   }
     file.close();	
}

// defination of delete function...........
void student::deleted()
{
	system("cls");
	fstream file,file1;
	string rollno;
	int found=0;
	cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;	
   cout<<"\t\t\t\t\t\t | Delete Student Record |"<<endl;
   cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;
   
   
    file.open("studentresult.txt",ios::in);
    if(!file)
    {
        cout<<"\n\t\t\t No Data Is Found ......";
	  file.close();	
				
	}
	else
	{
		cout<<"\n\t\t\t--> Enter Roll No. Of Student Which You Want To delete The Data : ";
		cin>>rollno;
		file1.open("temp.txt",ios::out | ios::app);
		
		file>>s_name>>f_name>>m_name>>c_name>>cr_name>>roll_no>>rgln>>dd>>mm>>yy>>cg>>dbms>>coil>>mlt>>cd>>sum>>per>>grade>>result;
		while(!file.eof())
		{
			if(rollno!=roll_no)
			{
				 file1<<" "<<s_name<<" "<<f_name<<" "<<m_name<<" "<<c_name<<" "<<cr_name<<" "<<roll_no<<" "<<rgln<<" "<<dd<<" "<<mm<<" "<<yy<<" "<<cg<<" "<<dbms<<" "<<coil<<" "<<mlt<<" "<<cd<<" "<<sum<<" "<<per<<" "<<grade<<" "<<result<<"\n";
				 
			}
			else
			{  found++;
			   cout<<"\n\t\t\t Record Is Successfully Deleted.....";
			   	
			}	
			
			file>>s_name>>f_name>>m_name>>c_name>>cr_name>>roll_no>>rgln>>dd>>mm>>yy>>cg>>dbms>>coil>>mlt>>cd>>sum>>per>>grade>>result;
		}
		if(found==0)
		{
			cout<<"\n\t\t\t Student Roll Number Is Not found...!!! ";
		}
		file.close();
		file1.close();
		
		remove("studentresult.txt");
		rename("temp.txt","studentresult.txt");
	}
		
}

// defination of main function..........
int main()
{    
    student s;              
    s.menu();                
    
	getch();
	return (0);
}

