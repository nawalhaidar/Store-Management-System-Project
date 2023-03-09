#pragma once
#include<iostream>
#include <string>
using namespace std;
class Product
{
	string name;
	int price;
	int quantity;
public:
	Product();
	Product(string, int, int);
	void setproduct(string, int, int);
	string getpname();
	int getprice();
	int getquantity();

};

