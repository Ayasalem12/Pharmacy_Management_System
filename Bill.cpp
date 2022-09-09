#include "Bill.h"

Bill::Bill()
{
}

bool Bill::uniqe_ID(char key[])
    {
        fstream Bill;
        Bill.open("Bill.txt",ios::app|ios::out|ios::in);
        char a[20];
        while(!Bill.eof())
        {
            Bill.getline(a,20,'|');
            Bill.getline(Total,20,'|');
            if(strcmp(key,a)==0)
            {
                return true;
            }
        }
        Bill.close();
        return false;
    }

void Bill::Add_Bill()
    {
        char ch;
        do
        {
            fstream Bill;
            fstream Bill1;
            
            Bill.open("Bill.txt",ios::app|ios::out|ios::in);id:
            Bill1.open("new_Employee.txt",ios::app|ios::out|ios::in);	
            cout<<" Enter Bill ID "<<endl;
            cin>>Bid;
            if(uniqe_ID(Bid))
            {
                cout<<Bid<<" THIS ID IS AREADY FOUNDED "<<endl;
                
            }
            cout<<" Enter Bill ID "<<endl;
            cin>>Bid;
            Bill.seekg(0,ios::end);
            int a=Bill.tellg();
            if(a==0)
            {
                Bill<<Bid;
            }
            else
            {
                Bill1<<"\n"<<Bid<<"|"<<Total;

            }
            Bill.close();
            cout<<" DO YOU WANT TO INSERT AGAIN !! ? (Y/N)\n";
            cin>>ch;
        }
        while(ch=='y'||ch=='Y');

	}
	void Bill::Add_Product_Bill(){
		char key[20];
        char new_id[20];
        int flag=0;
        fstream Bill;
        fstream Bill1;
        Bill.open("Bill.txt",ios::app|ios::out|ios::in);
        Bill1.open("new_Bill.txt",ios::app|ios::out|ios::in);

        cout<<" ENTER ID Bill  TO UPDATE  "<<endl;
        cin>>key;

        while(!Bill.eof())
        {

            Bill.getline(Bid,20,'|');
            Bill.getline(Total,20,'|');
            if(strcmp(key,Bid)==0)
            {
                cout<<" ENTER NEW ID TO UPDATE  "<<endl;
                cin>>new_id;
                Bill1.seekg(0,ios::end);
                cout<<" Enter Bill Total "<<endl;
                cin>>Total;
                int a=Bill1.tellg();
                if(a==0)
                    Bill1<<new_id<<"|"<<Total;
                else
                    Bill1<<"\n"<<new_id<<"|"<<Total;

                flag=1;
            }
            else
            {
                Bill1.seekg(0,ios::end);
                int a=Bill1.tellg();
                if(a==0)
                    Bill1<<Bid<<"|"<<Total;
                else
                    Bill1<<"\n"<<Bid<<"|"<<Total;
            }
        }//end while

        Bill1.close();
        Bill.close();
        remove("Bill.txt");
        rename("new_Bill.txt","Bill.txt");
	}

Bill::~Bill()
{
}
