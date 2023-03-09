#include "Dealer.h"
#include "Person.h"
#include<fstream>
using namespace std;
void Dealer::add(Product P)
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
		temp << n << " " << pr << " " << qt << endl;
		indata >> n >> pr >> qt;
	}
	temp << P.getpname() << " " << P.getprice() << " " << P.getquantity() << endl;
	indata.close();
	temp.close();
	ofstream idata;
	ifstream tem;
	idata.open("C:\\Users\\LENOVO\\Desktop\\Products.txt");
	tem.open("C:\\Users\\LENOVO\\Desktop\\temp.txt");
	tem >> n >> pr >> qt;
	while (!tem.eof())
	{
		idata << n << " " << pr << " " << qt << endl;
		tem >> n >> pr >> qt;
	}
	idata.close();
	tem.close();

}
void Dealer::refill(Product P, int qty)
{
	ifstream indata;
	ofstream temp;
	string n;
	int pr, qt, total;
	indata.open("C:\\Users\\LENOVO\\Desktop\\Products.txt");
	temp.open("C:\\Users\\LENOVO\\Desktop\\temp.txt");
	indata >> n >> pr >> qt;
	while (!indata.eof())
	{
		if (n == P.getpname())
			total = qt + qty;
		else
			total = qt;
		temp << n << " " << pr << " " << total << endl;
		indata >> n >> pr >> qt;
	}
	indata.close();
	temp.close();
	ofstream idata;
	ifstream tem;
	idata.open("C:\\Users\\LENOVO\\Desktop\\Products.txt");
	tem.open("C:\\Users\\LENOVO\\Desktop\\temp.txt");
	tem >> n >> pr >> total;
	while (!tem.eof())
	{
		idata << n << " " << pr << " " << total << endl;
		tem >> n >> pr >> total;
	}
	idata.close();
	tem.close();
}
void Dealer::remove(Product P)
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
		if(n!=P.getpname())
			temp << n << " " << pr << " " << qt << endl;
		indata >> n >> pr >> qt;
	}

	indata.close();
	temp.close();
	ofstream idata;
	ifstream tem;
	idata.open("C:\\Users\\LENOVO\\Desktop\\Products.txt");
	tem.open("C:\\Users\\LENOVO\\Desktop\\temp.txt");
	tem >> n >> pr >> qt;
	while (!tem.eof())
	{
		idata << n << " " << pr << " " << qt << endl;
		tem >> n >> pr >> qt;
	}
	idata.close();
	tem.close();
}


