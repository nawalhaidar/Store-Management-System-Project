#include "Customer.h"
#include "Person.h"
#include"Dealer.h"
#include<fstream>
using namespace std;

string find_person(string username, string filepath);
Product find_product(string name);

void Customer::purchase(Product P, int qnty)
{
	ifstream indata;
	ofstream temp;
	string n;
	int pr, qt;
	indata.open("C:\\Users\\LENOVO\\Desktop\\Products.txt");
	temp.open("C:\\Users\\LENOVO\\Desktop\\temp.txt");
	indata >> n >> pr >> qt;

	while (!indata.eof())
	{
		if (n == P.getpname())
		{
			if (P.getquantity() >= qnty)
			{
				cout << "Total price to be paid:" << P.getprice() * qnty << endl;
				Dealer d;
				d.refill(P, -1 * qnty);		
			}

			else
			{
				cout << "Insufficient stock" << endl;
				cout << "The available stock is: " << P.getquantity() << endl;
				indata.close();
				temp.close();
				break;

			}
		}
		indata >> n >> pr >> qt;
	}
}

void Customer::create_account() { 
	cout << "Enter your username: ";
	string username;
	cin >> username;
	while (find_person(username, "C:\\Users\\LENOVO\\Desktop\\Customers.txt") != "") {
		cout << "Username already exists. Please enter another username." << endl;
		cin >> username;
	}
	string password;
	cout << "Enter a password: ";
	cin >> password;
	while (password.length() < 8) {
		cout << "Passwords must be of atleast 8 characters. Please enter a new password" << endl;
		cin >> password;
	}
	ifstream indata;
	ofstream temp;
	string name, pass;
	indata.open("C:\\Users\\LENOVO\\Desktop\\Customers.txt");
	temp.open("C:\\Users\\LENOVO\\Desktop\\temp.txt");
	indata >> name >> pass;
	while (!indata.eof()) {
		temp << name << " " << pass << endl;
		indata >> name >> pass;
	}
	temp << username << " " << password << endl;
	indata.close();
	temp.close();

	ifstream tem;
	ofstream outdata;
	tem.open("C:\\Users\\LENOVO\\Desktop\\temp.txt");
	outdata.open("C:\\Users\\LENOVO\\Desktop\\Customers.txt");
	tem >> name >> pass;
	while (!tem.eof()) {
		outdata << name << "\t" << pass << endl;
		tem >> name >> pass;
	}
	tem.close();
	outdata.close();
}


