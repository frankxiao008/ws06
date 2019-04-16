#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>
#include "TaxableProduct.h"

namespace sict {

	// tax rates for all products
	double TaxableProduct::rate[2]{ 0.13, 0.08 };


	//// constructor 
	//TaxableProduct::TaxableProduct(unsigned no, double price, char c) :
	//	Product(no, price) {
	//	switch (c) {
	//	case 'H': tax = HST; break;
	//	case 'P': tax = PST; break;
	//	default: throw "tax status undefined";
	//	}
	//}


	/*TaxableProduct::TaxableProduct(const int productnum, const double productcost, char taxstatus) :Product(productnum, productcost) {
		taxtype = taxstatus;
	}
*/


	//double TaxableProduct::price() const {
	//	double taxrate = taxtype == 'H' ? HST : PST;
	//	return Product::price()*(1 + taxrate);
	//}

	double TaxableProduct :: price() const {
		return Product::price()*(1.0 + rate[tax]);
	}
	


	void TaxableProduct::display(std::ostream& os) const {
		Product::display(os);
		os << (tax == HST ? " HST" : (tax == PST ? " PST" : ""));
	}
		//	TaxableProduct(unsigned productnum, double productcost, char taxstatus);
	sict::TaxableProduct::TaxableProduct(unsigned productnum,  double productcost, char taxstatus) :
	Product(productnum, productcost){
		switch (taxstatus) {
		case 'H': tax = HST; break;
		case 'P': tax = PST; break;
		default: throw "tax status undefined";
		
		}
	}


	//void TaxableProduct::display(std::ostream& os) const {
	//	Product::display(os);
	//	os << " " << (taxtype == 'H' ? "HST" : "PST");
	//}



	
}
