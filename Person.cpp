#include "Person.h"
#include <string>
#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;

string find_person(string username, string filepath);

Person::Person()
{
    username = " ";
    password = " ";
}
Person::Person(string username, string password)
{
    this->username = username;
    this->password = password;
}
void Person::set(string username, string password)
{
    this->username = username;
    this->password = password;

}
string Person::getname()
{
    return username;
}
string Person::getpass()
{
    return password;
}

void Person::display()
{
    int price, quantity;
    string name;
    ifstream indata;
    indata.open("C:\\Users\\LENOVO\\Desktop\\Products.txt");
    cout << "Product Name\t" << "Price\t" << "Quantity" << endl;
    indata >> name >> price >> quantity;
    while (!indata.eof())
    {
        cout << left << setw(12) << name << "\t";
        cout << left << setw(4) << price << "$" << "\t";
        cout << left << setw(8) << quantity << "\t" << endl;
        indata >> name >> price >> quantity;
    }
}

void Person::login(string filepath) {

    cout << "Please Enter your login credentials" << endl;
    cout << "Username: ";
    string username;
    cin >> username;
    string password = find_person(username, filepath);
    while (password == "") {
        cout << endl;
        cout << "Username not found. Please enter a valid username" << endl;
        cout << "Username: ";
        cin >> username;
        password = find_person(username, filepath);
    }
    cout << "Password: ";
    string pass;
    cin >> pass;
    while (pass != password) {
        cout << endl;
        cout << "Incorrect password. Please try again" << endl;
        cout << "Password: ";
        cin >> pass;
    }

}
