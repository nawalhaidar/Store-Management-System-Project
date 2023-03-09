#pragma once
#include<iostream>
#include "Person.h"
#include"Product.h"
using namespace std;
class Customer : public Person
{
public:
	void purchase(Product, int);
	void create_account();
};

