#include "Product.h"
Product::Product()
{
	name = "";
	price = 0;
	quantity = 0;
}
Product::Product(string pname, int pprice, int pquantity)
{
	name = pname;
	price = pprice;
	quantity = pquantity;
}
void Product::setproduct(string pname, int pprice, int pquantity)
{
	name = pname;
	price = pprice;
	quantity = pquantity;

}
string Product::getpname()
{
	return name;
}
int Product::getprice()
{
	return price;
}
int Product::getquantity()
{
	return quantity;
}