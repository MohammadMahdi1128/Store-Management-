#include<iostream>
#include<cstdio>
#include<string>
#include<iomanip>
#include<fstream>
#include"Person.h"
#include"Product.h"

using namespace std;
                                               /*              PLEASE CHECK THE PATHS
												THERE ARE 2 PATHS TO CORRECT IN THIS CODE FILE */
bool login(int);
void dealer_option(int);
void employee_option(int);
void costumer_option(int);

int main()
{
    int x,y=0;
	cout << "DONE BY:\n";
	cout << "\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	cout << "\tAli Saleh ID:6097\n\tMohammad Mahdi Kassem ID:6200\n";
	cout << "\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";

mainmenu://///////////////////////////////////////////////////STORE MENU//////////////////////////////////////////////

	cout <<  "\t\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~\n";
	cout  << "\t\t\t\t\t\tWELCOME TO STORE MENU\n";    
	cout <<  "\t\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~\n\n";
	
	cout << "\t1.Dealer \t 2.Employee \t 3.Costumer\t 4.Exit\n\n ";
	do {
		cout  << "Enter your option number:\n\n " << endl;
		cin >> x;
		cin.clear();
		cin.ignore(100, '\n');
	} while (x > 4 || x <= 0);
	switch (x)
	{
	case 1:             ///////////////////////////////////////dealer
		if (!login(1))
			goto mainmenu;
		y = 0;
	    do
		{
			if (y != 4)
				system("cls");
			
			cout << "\t\t\t\t\t\tHELLO TO DEALER MENU\n";
			cout << "\t\t\t\t\t\t--------------------\n\n";
			cout << "\t1.Refill \t 2.Add new item\t 3.Delete \t 4.Display Stock \t 5.Back to main menu\n\n ";
			do {
				cout << "Enter your option number\n\n " << endl;
				cin >> y;
				cin.clear();
				cin.ignore(100, '\n');
			} while (y > 5 || y <= 0);
			if (y == 5)
			{
				system("cls");
				goto mainmenu;
			}
			dealer_option(y);
		} while (1);
		break;
	case 2:            ///////////////////////////////////////employee
		if (!login(2))
			goto mainmenu;
		y = 0;
		do
		{
			if (y != 3)
				system("cls");
			cout << "\t\t\t\t\t\tHELLO TO EMPLOYEE MENU\n";
			cout << "\t\t\t\t\t\t----------------------\n\n";
			cout << "\t1.Refill \t 2.Delete \t 3.Display Stock \t 4.Back to main menu\n\n ";
			do {
				cout << "Enter your option number\n\n " << endl;
				cin >> y;
				cin.clear();
				cin.ignore(100, '\n');
			} while (y > 4 || y <= 0);
			if (y == 4)
			{
				system("cls");
				goto mainmenu;
			}
			employee_option(y);
			
		} while (1);
		break;
	case 3:            ///////////////////////////////////////customer
		y = 0;
		do
		{
			if (y != 1)
				system("cls");
			cout << "\t\t\t\t\t\tHELLO TO CUSTOMER MENU\n";
			cout << "\t\t\t\t\t\t----------------------\n\n";
			cout << "\t 1.Display Stock \t2.Purchase\t 3.Back to main menu\n\n ";
			do {
				cout << "Enter your option number\n\n " << endl;
				cin >> y;
				cin.clear();
				cin.ignore(100, '\n');
			} while (y > 3 || y <= 0);
			if (y == 3)
			{
				system("cls");
				goto mainmenu;
			}
			costumer_option(y);
		
		} while (1);
		break;

	}
	return 0;
}

/////////////////////////////////////// /////////////////////////////////////// ///////////////////////////////////////


/////////////////////////////////////// /////////////////////////////////////// ///////////////////////////////////////

bool login(int x)
{
	system("cls");
	fstream userf;
	if(x==1)
		userf.open("C:\\Users\\User\\Desktop\\Dealer.txt", ios::in);     /* Dealer file's path */
	else
		userf.open("C:\\Users\\User\\Desktop\\Employee.txt", ios::in);   /* Employee file's path */
	Person D;
	system("cls");
		return D.check(userf);
}

void dealer_option(int x) ///////////////////////////////////////dealer options
{
	Product p;
	int q = -1;
	switch (x)
	{ 
	case 1:                                                    //Refill 
		p.set_name();
		
		while (1)
		{
			cout << "enter the product quantity\n\n";
			cin >> q;
			cin.clear();
			cin.ignore(100, '\n');
			if (q >= 0)
				break;
			else
				cout << "****Unvalid QUANTITY****\n\n";
		}
		if (p.Refill(q)==0)
		{
			cin;
			cin.clear();
			cin.ignore(100, '\n');
		}
		break;
	case 2:                                                   //Add new item
		p.set_name();
		if (!p.search())
		{
			p.set_quantity();
			p.set_price();
			p.Add();
		}
		else
			cout << "\t****This item already exist in stock****\n\n";
		cin;
		cin.clear();
		cin.ignore(100, '\n');
		break;
	case 3:                                                   //Delete
		p.set_name();
		p.Delete();
		cin;
		cin.clear();
		cin.ignore(100, '\n');
		break;
	case 4:                                                   //Display Stock
		p.display();
		break;
	}

}

void employee_option(int x) ///////////////////////////////////////employee options
{
	Product p;
	int q = -1;
	switch (x)
	{
	case 1:                                                   //Refill
		p.set_name();
		
		while (1)
		{
			cout << "enter the product quantity\n\n";
			cin >> q;
			cin.clear();
			cin.ignore(100, '\n');
			if (q >= 0)
				break;
			else
				cout << "****Unvalid QUANTITY****\n\n";
		}
		if (p.Refill(q) == 0)
		{
			cin;
			cin.clear();
			cin.ignore(100, '\n');
		}
		break;
	case 2:                                                      //Delete
		p.set_name();
		p.Delete();
		cin;
		cin.clear();
		cin.ignore(100, '\n');
		break;
	case 3:                                                      //Display Stock
		p.display();
		break;

	}
}

void costumer_option(int x) ///////////////////////////////////////costumer options
{
	Product p;
	int q = -1;
	switch (x)
	{
	case 1:                                                       //Display Stock
		p.display();
		break;
	case 2:                                                       //Purchase
		p.set_name();
		
		while (1)
		{
			cout << "enter the product quantity\n\n";
			cin >> q;
			cin.clear();
			cin.ignore(100, '\n');
			if (q >= 0)
				break;
			else
				cout << "****Unvalid QUANTITY****\n\n";
		}
		cout << "THE TOTAL PRICE IS:"<< p.Refill(-q)<<" $"<<"\n\n";
			cin;
			cin.clear();
			cin.ignore(100, '\n');
		break;
	}
}