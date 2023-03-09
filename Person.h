#pragma once
#include <string>
#include<iostream>
using namespace std;

class Person
{
	string username, password;
public:
	Person();
	Person(string, string);
	void set(string, string);
	string getname();
	string getpass();
	void display();
	void login(string filepath);

};