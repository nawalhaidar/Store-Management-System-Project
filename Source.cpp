// Store Management System Project
// Presented to Dr. Rida EL Chall
// Done by:
// Ward Batsh #6078
// Nawal Haidar #6106
// Nour Al Dandachly #6085


#include<fstream>
#include<iostream>
#include"Customer.h"
#include"Dealer.h"
#include"Employee.h"
#include"Person.h"
#include"Product.h"

using namespace std;

string find_person(string username, string filepath);
Product find_product(string name);
void CustomerOptions();
void EmployeeOptions();
void DealerOptions();


int main() {
	Customer cus;
	Employee emp;
	Dealer deal;
	int x = -1, y;
	cout << "Hello! Welcome to WNN Mart!" << endl
		<< "Please enter the corresponding number" << endl
		<< "You are a:" << endl
		<< "1.Customer" << endl
		<< "2.Employee" << endl
		<< "3.Dealer" << endl;
	cin >> x;
	while (x < 1 || x>3)
	{
		cout << endl;
		cin.clear();
		cin.ignore(200, '\n');
		cout << "Please enter a valid number" << endl;
		cin >> x;
	}
	cout << endl;
	switch (x) {
	case 1://customer
		cout << "Do you already have an account?" << endl
			<< "1. Yes. I want to login" << endl
			<< "2. No. I want to create an account" << endl;
		y = -1;
		cin >> y;

		while (y < 1 || y>2)
		{
			cout << endl;
			cin.clear();
			cin.ignore(200, '\n');
			cout << "Please enter a valid number." << endl;
			cin >> y;
		}
		cout << endl;
		switch (y) {
		case 1://login
			cus.login("C:\\Users\\LENOVO\\Desktop\\Customers.txt");
			break;
		case 2://create account
			cus.create_account();
			break;
		}
		cout << endl;
		CustomerOptions();
		break;
	case 2://employee
		emp.login("C:\\Users\\LENOVO\\Desktop\\Employees.txt");
		cout << endl;
		EmployeeOptions();
		break;
		
	case 3://dealer
		deal.login("C:\\Users\\LENOVO\\Desktop\\Dealers.txt");
		cout << endl;
		DealerOptions();
		break;
	}
	return 0;
}


string find_person(string username, string filepath) {
	ifstream indata;
	string password = "";
	string n, p;
	indata.open(filepath);
	indata >> n >> p;
	while (!indata.eof()) {
		if (n == username) {
			password = p;
			break;
		}
		indata >> n >> p;
	}
	indata.close();
	return password;
}

Product find_product(string name) {
	ifstream indata;
	string n;
	int qt, pr;
	Product P;
	P.setproduct("", 0, 0);
	indata.open("C:\\Users\\LENOVO\\Desktop\\Products.txt");
	indata >> n >> pr >> qt;
	while (!indata.eof()) {
		if (n == name) {
			P.setproduct(n, pr, qt);
			break;
		}
		indata >> n >> pr >> qt;
	}
	return P;
}

void CustomerOptions() {
	Customer cus;
	Product P;
	string name;
	cout << "Choose an action" << endl
		<< "1. Display Products" << endl
		<< "2. Purchase a Product" << endl
		<< "3. Exit" << endl;
	int y = -1;
	cin >> y;

	while (y < 1 || y>3)
	{
		cin.clear();
		cin.ignore(200, '\n');
		cout << "Please enter a valid number:" << endl;
		cin >> y;
	}
	cout << endl;
	switch (y) {
	case 1://display
		cus.display();
		cout << endl;
		CustomerOptions();
		break;
	case 2://purchase
		cout << "Enter the name of the product that you want to purchase:"<<endl;
		cin >> name;
		P = find_product(name);
		while (P.getpname() == "") {
			cout << "Please enter a valid product:" << endl;
			cin >> name;
			P = find_product(name);
		}
		cout << "Enter the quantity you want to purchase: " << endl;
		int qt;
		cin >> qt;
		while (qt <= 0) {
			cout << "Quantity must be positive. Enter the quantity:" << endl; 
			cin >> qt;
		}
		cus.purchase(P, qt);
		cout << endl;
		CustomerOptions();
		break;
	case 3://exit
		cout << endl;
		cout << "Thank you for your visit!" << endl;
		return;
	}

}

void EmployeeOptions() {
	Employee emp;
	Product P;
	string name;
	cout << "Choose an action" << endl
		<< "1. Display Products" << endl
		<< "2. Refill a Product" << endl
		<< "3. Exit" << endl;
	int y = -1;
	cin >> y;

	while (y < 1 || y>3)
	{
		cin.clear();
		cin.ignore(200, '\n');
		cout << "Please enter a valid number:" << endl;
		cin >> y;
	}

	switch (y) {
	case 1://display
		emp.display();
		cout << endl;
		EmployeeOptions();
		break;
	case 2://refill
		cout << "Enter the name of the product that you want to refill:" << endl;
		cin >> name;
		P = find_product(name);
		while (P.getpname() == "") {
			cout << "Please enter a valid product:" << endl;
			cin >> name;
			P = find_product(name);
		}
		cout << "Enter the quantity you want to refill:" << endl;
		int qt;
		cin >> qt;
		emp.refill(P, qt);
		cout << endl;
		EmployeeOptions();
		break;
	case 3://exit
		cout << "Your effors are valued!" << endl;
		return;
	}

}

void DealerOptions() {
	Dealer deal;
	Product P;
	string name;
	cout << "Choose an action" << endl
		<< "1. Display Products" << endl
		<< "2. Refill a Product" << endl
		<< "3. Add a Product" << endl
		<< "4. Remove a Product" << endl
		<< "5. Exit" << endl;
	int y = -1;
	cin >> y;

	while (y < 1 || y>5)
	{
		cin.clear();
		cin.ignore(200, '\n');
		cout << "Please enter a valid number" << endl;
		cin >> y;
	}

	switch (y) {
	case 1://display
		deal.display();
		cout << endl;
		DealerOptions();
		break;
	case 2://refill
		cout << "Enter the name of the product that you want to refill:" << endl;
		cin >> name;
		P = find_product(name);
		while (P.getpname() == "") {
			cout << "Please enter a valid product." << endl;
			cin >> name;
			P = find_product(name);
		}
		cout << "Enter the quantity you want to refill: " << endl;
		int qt;
		cin >> qt;
		deal.refill(P, qt);
		cout << endl;
		DealerOptions();
		break;
	case 3://add
		cout << "Enter the name of the product that you want to add:" << endl;
		cin >> name;
		P = find_product(name);
		if (P.getpname() != "") {
			cout << "Product already found" << endl;
		}
		else {
			cout << "Enter the quantity you want to add: " << endl;
			int qt;
			cin >> qt;
			cout << "Enter the price: " ;
			int pr;
			cin >> pr;
			cin.clear();
			cin.ignore(200, '\n');
			P.setproduct(name, pr, qt);
			deal.add(P);
		}
		cout << endl;
		DealerOptions();
		break;
	case 4://remove
		cout << "Enter the name of the product that you want to remove:" << endl;
		cin >> name;
		P = find_product(name);
		while (P.getpname() == "") {
			cout << "Please enter a valid product:" << endl;
			cin >> name;
			P = find_product(name);
		}
		deal.remove(P);
		cout << endl;
		DealerOptions();
		break;
	case 5://exit
		cout << "Your effors are valued!" << endl;
		return;
	}

}
