#include "Person.h"
#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>

using namespace std;

Person::Person()
{
    username = '\0';
    password = '\0';
}
void Person::set_username()
	{
		cout << " enter your username\n\n ";
		cin >> username;
	}
	void Person::set_password()
	{
		cout << "enter your password\n\n ";
		cin >> password;
	}
	bool Person::check(fstream &user)
	{


		string n;
		string p;
		set_username();
		if (user.is_open())
		{
			while (user >> n >> p)
			{
				if (n == username)
				{
					set_password();
					if (p != password)
					{
						cout << "****Unvalid Password****\n\n";
						user.close();
						return 0;
					}
					user.close();
					return 1;

				
				}
			}
			cout << "****Unvalid Username****\n\n";
		}else
		cout << "****Username file not founded please check the file path in (store.cpp)****\n\n";
		user.close();
		return 0;
	}