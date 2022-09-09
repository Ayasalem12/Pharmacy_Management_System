//#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include<bits/stdc++.h>
#include <fstream>
#include <iostream>
using namespace std;
class Employee
{
		private:
		char id[20];
        char name[20];
        char salary[20];
	public:
		Employee();
		~Employee();
		void SetId(char);
		void SetName(char);
		void SetSalary(char);
		char *getId();
		char *getName();
		char *getSalary();
		void insert_Emp();
		void delete_Emp();
		void Update_Emp();
		bool uniqe_ID(char key[]);
 void disPlay_Emp(){
	    fstream Employee;
        Employee.open("Employee.txt",ios::app|ios::out|ios::in);
        cout<<"Employee ATTRIBUTES:\nID\tNAME\tSaraly\n";
        while(!Employee.eof())
        {
            Employee.getline(id,20,'|');
            Employee.getline(name,20,'|');
            Employee.getline(salary,20,'|');
            cout<<id<<"\t"<<name<<"\t"<<salary<<endl;
        }

        Employee.close();
	  }
void search_Emp() 
    {
        int flag=0;
        char ch;
        char key[20];
        do
        {
            cout<<" ENTER NAME TO SEARCH ! "<<endl;
            cin>>key;
            fstream Employee;
            Employee.open("Employee.txt",ios::app|ios::out|ios::in);

            while(!Employee.eof())
            {
            Employee.getline(id,20,'|');
            Employee.getline(name,20,'|');
            Employee.getline(salary,20,'|');
            
                if(strcmp(key,name)==0)
                {
                    cout<<id<<"\t"<<name<<"\t"<<salary<<endl;
                    flag=1;
                }
            }
            if(flag==0)
                cout<<" Employee NOT FOUND "<<endl;
            Employee.close();
            cout<<" DO YOU WANT TO SEARCH AGAIN "<<endl;
            cin>>ch;
        }
        while(ch=='y'||ch=='Y');
		}

};


