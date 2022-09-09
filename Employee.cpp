#include "Employee.h"
#include <fstream>
#include <iostream>

using namespace std;
Employee::Employee()
{

}
   
 bool Employee::uniqe_ID(char key[])
    {
        fstream Employee;
        Employee.open("Employee.txt",ios::app|ios::out|ios::in);
        char a[20];
        while(!Employee.eof())
        {
            Employee.getline(a,20,'|');
            Employee.getline(name,20,'|');
            Employee.getline(salary,20,'|');
            if(strcmp(key,a)==0)
            {
                return true;
            }
        }
        Employee.close();
        return false;
    }
	void Employee::insert_Emp(){
	char ch;
        do
        {
            fstream Employee;
            Employee.open("Employee.txt",ios::app|ios::out|ios::in);id:
            cout<<" Enter EmployeeID "<<endl;
            cin>>id;
            if(uniqe_ID(id))
            {
                cout<<id<<" THIS ID IS AREADY FOUNDED "<<endl;
                goto id;
            }
            cout<<" Enter Employee Name "<<endl;
            cin>>name;
            cout<<" Enter Employee Salary "<<endl;
            cin>>salary;
            Employee.seekg(0,ios::end);
            int a=Employee.tellg();
            if(a==0)
            {
                Employee<<id<<"|"<<name<<"|"<<salary;
            }
            else
            {
                Employee<<"\n"<<id<<"|"<<name<<"|"<<salary;

            }
            Employee.close();
            cout<<" DO YOU WANT TO INSERT AGAIN !! ? (Y/N)\n";
            cin>>ch;
        }
        while(ch=='y'||ch=='Y');
}
void Employee::delete_Emp(){
  int i=0;
        char key[20];
        int flag=0;
        char ch;
        do
        {
            cout<<" ENTER ID NUMBER TO DELETE "<<endl;
            cin>>key;
            fstream Employee;
            fstream Employee1;
            Employee.open("Employee.txt",ios::app|ios::out|ios::in);
            Employee1.open("new_Employee.txt",ios::app|ios::out|ios::in);
            while(!Employee.eof())
            {
            Employee.getline(id,20,'|');
            Employee.getline(name,20,'|');
            Employee.getline(salary,20,'|');

                if(strcmp(key,id)==0)
                {
                    cout<<" FOUND & DELETED "<<endl;
                    flag=1;//true
                }
                else
                {
                    i++;
                    Employee1.seekg(0,ios::end);
                    int a=Employee1.tellg();
                    if(a==0)
                        Employee1<<id<<"|"<<name<<"|"<<salary;
                    else
                        Employee1<<"\n"<<id<<"|"<<name<<"|"<<salary;
                }
            }
            if(flag==0)
                cout<<" ID NUMBER NOT FOUND "<<endl;
            Employee.close();
            Employee1.close();
            remove("Employee.txt");
            rename("new_Employee.txt","Employee.txt");
            cout<<"DO YOU WANT TO DELETE BY ID AGAIN "<<endl;
            cin>>ch;

        }
        while(ch=='y'||ch=='Y');
}

void Employee::Update_Emp(){
	char key[20];
        char new_id[20];
        int flag=0;
        fstream Employee;
        fstream Employee1;
        Employee.open("Employee.txt",ios::app|ios::out|ios::in);
        Employee1.open("new_Employee.txt",ios::app|ios::out|ios::in);

        cout<<" ENTER ID Employee  TO UPDATE  "<<endl;
        cin>>key;

        while(!Employee.eof())
        {

            Employee.getline(id,20,'|');
            Employee.getline(name,20,'|');
            Employee.getline(salary,20,'|');
            if(strcmp(key,id)==0)
            {
                cout<<" ENTER NEW ID TO UPDATE  "<<endl;
                cin>>new_id;
                Employee1.seekg(0,ios::end);
                cout<<" Enter Employee Name "<<endl;
                cin>>name;
                cout<<" Enter Employee Salary "<<endl;
                cin>>salary;

                int a=Employee1.tellg();
                if(a==0)
                    Employee1<<new_id<<"|"<<name<<"|"<<salary;
                else
                    Employee1<<"\n"<<new_id<<"|"<<name<<"|"<salary;

                flag=1;
            }
            else
            {
                Employee1.seekg(0,ios::end);
                int a=Employee1.tellg();
                if(a==0)
                    Employee1<<id<<"|"<<name<<"|"<<salary;
                else
                    Employee1<<"\n"<<id<<"|"<<name<<"|"<<salary;
            }
        }//end while

        Employee1.close();
        Employee.close();
        remove("Employee.txt");
        rename("new_Employee.txt","Employee.txt");

}

Employee::~Employee()
{
}
