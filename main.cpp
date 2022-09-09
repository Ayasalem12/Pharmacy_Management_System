#include <iostream>
#include "Product.h"
#include <iomanip>
#include <stdlib.h>
#include "Employee.h"
#include "Bill.h"

using namespace std;

void Products()
{
	bool flag=true;
	while(flag)
	{
      cout<<"***************************"<<endl;
      cout<<" ADD    ==> press : 1  "<<endl;
      cout<<" View   ==> press : 2  "<<endl;
      cout<<" Search ==> press : 3  "<<endl;
      cout<<" Delete ==> press : 4  "<<endl;
      cout<<" Update ==> press : 5  "<<endl;
      cout<<" Exist  ==> press : 6  "<<endl;
    cout<<"***************************"<<endl<<endl<<endl;
      Product p;
here:
    int c;
    cout<<" Your Choice : ";
    cin>>c;
    switch(c)
    {
        case 1 :
          p.add_Product();
        break;
        case 2 :
        p.dispaly();
        break;
        case 3 :
        p.search_name();
        break;
        case 4 :
        p.delete_Product();
        break;
        case 5 :
        p.update();
        break;
        case 6 :
        cout << "Exiting ";
          
          break ;
        default:
        cout<<"\n Choose right number \n";
      }
       cout<<"\n if you want to continue the program press'y' \n";
       char f;
      cin>>f;
      if(f!='y')
     {
          flag=false;
     }
 }
	
}
 void Employees()
 {
 	bool flag=true;
	while(flag)
	{
      cout<<"***************************"<<endl;
      cout<<" ADD    ==> press : 1  "<<endl;
      cout<<" View   ==> press : 2  "<<endl;
      cout<<" Search ==> press : 3  "<<endl;
      cout<<" Delete ==> press : 4  "<<endl;
      cout<<" Update ==> press : 5  "<<endl;
      cout<<" Exist  ==> press : 6  "<<endl;
    cout<<"***************************"<<endl<<endl<<endl;
      	Employee E ;
here:
    int a;
    cout<<" Your Choice : ";
    cin>>a;
    switch(a)
    {
        case 1 :
        E.insert_Emp();
        break;
        case 2 :
        E.disPlay_Emp();
        break;
        case 3 :
        E.search_Emp();
        break;
        case 4 :
        E.delete_Emp();
        break;
        case 5 :
        E.Update_Emp();
        break;
        case 6 :
        cout << "Exiting ";
          
          break ;
        default:
        cout<<"\n Choose right number \n";
      }
       cout<<"\n if you want to continue the program press'y' \n";
       char f;
      cin>>f;
      if(f!='y')
     {
          flag=false;
     }
 }
 }
 void Bills(){
 	bool flag=true;
	while(flag)
	{
      cout<<"***************************"<<endl;
      cout<<" ADD_Bill    ==> press : 1  "<<endl;
      cout<<" Add_Product_Bill   ==> press : 2  "<<endl;
      cout<<" Exist  ==> press : 3 "<<endl;
    cout<<"***************************"<<endl<<endl<<endl;
      	Bill B ;
here:
    int a;
    cout<<" Your Choice : ";
    cin>>a;
    switch(a)
    {
        case 1 :
        B.Add_Bill();
        break;
        case 2 :
        B.Add_Product_Bill();
        break;
        case 3 :
        cout << "Exiting ";
          break ;
        default:
        cout<<"\n Choose right number \n";
      }
       cout<<"\n if you want to continue the program press'y' \n";
       char f;
      cin>>f;
      if(f!='y')
     {
          flag=false;
     }
 }
 	
 }

int main() {
	bool flag=true;
	while(flag)
	{
    cout <<"\n\n\t\t\t\t\t========================================"<<endl;
        cout <<"\t\t\t\t\t Hi -_-  WELCOME TO OUR PHARMACY SYSYTEM   "<<endl;
        cout <<"\t\t\t\t\t========================================"<<endl;
      cout<<"***************************"<<endl;
      cout<<" Product ==> press : 1  "<<endl;
      cout<<" Employee ==> press : 2  "<<endl;
      cout<<" Bill  ==> press : 3  "<<endl;
      cout<<" Exist ==> press : 4  "<<endl;
    cout<<"***************************"<<endl<<endl<<endl;
    int c;
    cout<<" Your Choice : ";
    cin>>c;
    switch(c)
    {
        case 1 :
         Products();
        break;
        case 2 :
        Employees();
        break;
        case 3 :
        Bills();
        break;
        case 4 :
        cout << "Exiting ";
          break ;
        default:
        cout<<"\n Choose right number \n";
      }
       cout<<"\n if you want to continue the program press'y' \n";
       char f;
      cin>>f;
      if(f!='y')
     {
          flag=false;
     }
 }
	return 0;
}
