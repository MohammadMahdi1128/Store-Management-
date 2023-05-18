#ifndef PRODUCT_H
#define PRODUCT_H

#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>

using namespace std;

class Product
{
	string name;
	double price;
	int quantity;

public:
	Product();
	void set_name();
	void set_price();
	void set_quantity();
	bool search();
	void Add();
	void Delete();
	double Refill(int);
	void display();
	
	
};
#endif