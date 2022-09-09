#ifndef PRODUCT_H
#define PRODUCT_H
#include<bits/stdc++.h>
#include <fstream>
#include <iostream>
using namespace std;
class Product
{
	private :
    char Id[20];
    char Name[20];
    char Amount[5];
    char Price[5];
	public:
		Product();
		void SetID(char); 
        char *GetID() ;
	    void SetName(char);
	    char* GetName();
	    void SetPrice(char);
	    char *GetPrice() ;
    	void SetAmount(char);
	    char *GetAmount() ;
	    void add_Product();
	    bool uniqe_id(char key[]);
	    void update();
	    void delete_Product();
	 void dispaly()
    {
        fstream Product;
        Product.open("Product.txt",ios::app|ios::out|ios::in);
        cout<<"PRODUCT ATTRIBUTES:\nID\tNAME\tAMOUNT\tPRICE\n";
        while(!Product.eof())
        {
            Product.getline(Id,20,'|');
            Product.getline(Name,20,'|');
            Product.getline(Amount,5,'|');
            Product.getline(Price,5,'|');
            cout<<Id<<"\t"<<Name<<"\t"<<Amount<<"\t"<<Price<<endl;
        }

        Product.close();
    }
    void search_name() 
    {
        int flag=0;
        char ch;
        char key[20];
        do
        {
            cout<<" ENTER NAME TO SEARCH ! "<<endl;
            cin>>key;
            fstream Product;
            Product.open("Product.txt",ios::app|ios::out|ios::in);

            while(!Product.eof())
            {
                Product.getline(Id,20,'|');
                Product.getline(Name,20,'|');
                Product.getline(Amount,5,'|');
                Product.getline(Price,5,'|');
                if(strcmp(key,Name)==0)
                {
                    cout<<Id<<"\t"<<Name<<"\t"<<Amount<<"\t"<<Price<<endl;
                    flag=1;
                }
            }
            if(flag==0)
                cout<<" Product NOT FOUND "<<endl;
            Product.close();
            cout<<" DO YOU WANT TO SEARCH AGAIN "<<endl;
            cin>>ch;
        }
        while(ch=='y'||ch=='Y');
    }
		~Product();

};

#endif
