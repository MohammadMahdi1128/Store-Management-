#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>
#include"Product.h"

using namespace std;
                                              /*                  PLEASE CHECK THE PATHS 
											    THERE ARE 8 PATHS TO CORRECT IN THIS IMPLEMENTATION FILE */
Product::Product()
{
	name = '\0';
	quantity = 0;
	price = 0;
}
void Product::set_name()
{
	cout << " enter the product name\n\n ";
	cin >> name ;
	cin.clear();
	cin.ignore(100, '\n');
}
void Product::set_price()
{
	while (1)
	{
		cout << " enter the product price in $\n\n ";
		price = -1;
		cin >> price;
		cin.clear();
		cin.ignore(100, '\n');
		if (price > 0)
			break;
		else
			cout << "****Unvalid PRICE****\n\n";
	}
	
}
void Product::set_quantity()
{
	while (1)
	{
		cout << " enter the product quantity\n\n ";
		quantity = -1;
		cin >> quantity;
		cin.clear();
		cin.ignore(100, '\n');
		if (quantity >= 0)
			break;
		else
			cout << "****Unvalid QUANTITY****\n\n";
	}
}

bool Product::search()

{

	fstream stock;
	string pn;
	double p;
	int q;
	stock.open("C:\\Users\\User\\Desktop\\Stock.txt", ios::in);    /* Stock file's path */
	if (stock.is_open())
	{
		while (stock >> pn >> q >> p)
		{
			if (pn == name)
			{
				stock.close();
				quantity = q;
				price = p;
				return 1;
			}

		}
		
	}
	stock.close();
	return 0;
}
	void Product :: Delete()
	{
		
		fstream stock;
		fstream temp;
		string pn;
		int q;
		double p;
		if (search())
		{
			stock.open("C:\\Users\\User\\Desktop\\Stock.txt", ios::in);      /* Stock file's path */
			temp.open("C:\\Users\\User\\Desktop\\temp.txt", ios::out);       /* temp stock file's path */
			if (stock.is_open() && temp.is_open())
			{
				while (stock>> pn >> q >> p)
				{
					if (pn != name)
						temp << pn << "\t" << q << "\t" << p << '\n';
				}
				stock.close();
				temp.close();
				stock.open("C:\\Users\\User\\Desktop\\Stock.txt", ios::out);
				temp.open("C:\\Users\\User\\Desktop\\temp.txt", ios::in);
				while (temp >> pn >> q >> p)
					stock << pn << '\t' << q << '\t' << p << '\n';
				stock.close();
				temp.close();
				temp.open("C:\\Users\\User\\Desktop\\temp.txt", ios::out);
				temp.close();
			}

		}
		else cout << " ****The product already not in stock****\n\n";
		
	}
	double Product::Refill(int q)
	{
		if(search())
		{
			if ((-q) > quantity)
			{
				cout << " ****SORRY NO enough quantity****\n\n";
				return 0;
			}
			Delete();
			quantity += q;
			Add();
			return (-q) * price;
		}
		cout << " ****The product not in stock****\n\n";
		return 0;
	}
	void Product::Add()
	{
		fstream stock;
		stock.open("C:\\Users\\User\\Desktop\\Stock.txt", ios::app);
		stock << name << "\t\t" << quantity << "\t\t" << price << '\n';
		stock.close();
	}
	void Product::display()
	{
		fstream stock;
		stock.open("C:\\Users\\User\\Desktop\\Stock.txt", ios::in);
		cout << "Product Name\tquantity\tPrice\n";
		while (stock  >> name >> quantity >> price)
		{
			cout << name << "\t\t" << quantity << "\t\t" << price <<" $" << '\n';

		}
		stock.close();
	}