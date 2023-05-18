#ifndef PERSON_H
#define PERSON_H


#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>
#include "Product.h"
using namespace std;
class Person
{
    string username;
	string password;
public:
    Person();
    void set_username();
    void set_password();
    bool check(fstream&);
};

#endif