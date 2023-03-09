#pragma once
#include"Person.h"
#include"Product.h"
#include <string>
#include<iostream>
using namespace std;

class Dealer : public Person
{
public:
	void add(Product);
	void refill(Product, int);
	void remove(Product);

};

