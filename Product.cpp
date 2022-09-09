#include "Product.h"
#include <fstream>
Product::Product()
{
}

bool Product::uniqe_id(char key[])
    {
        fstream Product;
        Product.open("Product.txt",ios::app|ios::out|ios::in);
        char a[20];
        while(!Product.eof())
        {
            Product.getline(a,20,'|');
            Product.getline(Name,20,'|');
            Product.getline(Amount,20,'|');
            Product.getline(Price,20,'|');
            if(strcmp(key,a)==0)
            {
                return true;
            }
        }
        Product.close();
        return false;
    }


    void Product::add_Product()
    {
        char ch;
        do
        {
            fstream Product;
            Product.open("Product.txt",ios::app|ios::out|ios::in);id:
            cout<<" Enter Product ID "<<endl;
            cin>>Id;
            if(uniqe_id(Id))
            {
                cout<<Id<<" THIS ID IS AREADY FOUNDED "<<endl;
                goto id;
            }
            cout<<" Enter Product Name "<<endl;
            cin>>Name;
            cout<<" Enter Product Amount "<<endl;
            cin>>Amount;
            cout<<" Enter Product Price "<<endl;
            cin>>Price;
            Product.seekg(0,ios::end);
            int a=Product.tellg();
            if(a==0)
            {
                Product<<Id<<"|"<<Name<<"|"<<Amount<<"|"<<Price;
            }
            else
            {
                Product<<"\n"<<Id<<"|"<<Name<<"|"<<Amount<<"|"<<Price;

            }
            Product.close();
            cout<<" DO YOU WANT TO INSERT AGAIN !! ? (Y/N)\n";
            cin>>ch;
        }
        while(ch=='y'||ch=='Y');
    }
    void Product::delete_Product() 
    {
        int i=0;
        char key[20];
        int flag=0;
        char ch;
        do
        {
            cout<<" ENTER ID NUMBER TO DELETE "<<endl;
            cin>>key;
            fstream Product;
            fstream Product1;
            Product.open("Product.txt",ios::app|ios::out|ios::in);
            Product1.open("new_Product.txt",ios::app|ios::out|ios::in);
            while(!Product.eof())
            {
                Product.getline(Id,20,'|');
                Product.getline(Name,20,'|');
                Product.getline(Amount,20,'|');
                Product.getline(Price,20,'|');
                if(strcmp(key,Id)==0)
                {
                    cout<<" FOUND & DELETED "<<endl;
                    flag=1;//true
                }
                else
                {
                    i++;
                    Product1.seekg(0,ios::end);
                    int a=Product1.tellg();
                    if(a==0)
                        Product1<<Id<<"|"<<Name<<"|"<<Amount<<"|"<<Price;
                    else
                        Product1<<"\n"<<Id<<"|"<<Name<<"|"<<Amount<<"|"<<Price;
                }
            }
            if(flag==0)
                cout<<" ID NUMBER NOT FOUND "<<endl;
            Product.close();
            Product1.close();
            remove("Product.txt");
            rename("new_Product.txt","Product.txt");
            cout<<"DO YOU WANT TO DELETE BY ID AGAIN "<<endl;
            cin>>ch;

        }
        while(ch=='y'||ch=='Y');
    }
void Product::update()
    {

        char key[20];
        char new_id[20];
        int flag=0;
        fstream Product;
        fstream Product1;
        Product.open("Product.txt",ios::app|ios::out|ios::in);
        Product1.open("new_Product.txt",ios::app|ios::out|ios::in);

        cout<<" ENTER ID Product  TO UPDATE  "<<endl;
        cin>>key;

        while(!Product.eof())
        {

            Product.getline(Id,20,'|');
            Product.getline(Name,20,'|');
            Product.getline(Amount,20,'|');
            Product.getline(Price,20,'|');
            if(strcmp(key,Id)==0)
            {
                cout<<" ENTER NEW ID TO UPDATE  "<<endl;
                cin>>new_id;
                Product1.seekg(0,ios::end);
                cout<<" Enter Product Name "<<endl;
                cin>>Name;
                cout<<" Enter Product Amount "<<endl;
                cin>>Amount;
                cout<<" Enter Product Price "<<endl;
                cin>>Price;

                int a=Product1.tellg();
                if(a==0)
                    Product1<<new_id<<"|"<<Name<<"|"<<Amount<<"|"<<Price;
                else
                    Product1<<"\n"<<new_id<<"|"<<Name<<"|"<<Amount<<"|"<<Price;

                flag=1;
            }
            else
            {
                Product1.seekg(0,ios::end);
                int a=Product1.tellg();
                if(a==0)
                    Product1<<Id<<"|"<<Name<<"|"<<Amount<<"|"<<Price;
                else
                    Product1<<"\n"<<Id<<"|"<<Name<<"|"<<Amount<<"|"<<Price;
            }
        }//end while

        Product1.close();
        Product.close();
        remove("Product.txt");
        rename("new_Product.txt","Product.txt");

    }

Product::~Product()
{
}
