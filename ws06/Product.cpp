//Workshop 6-Product.cpp
//Name:		Saihong Xiao
//Student ID:	140777178
//Email:		sxiao15@myseneca.ca


#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include "Product.h"
#include "TaxableProduct.h"

extern int FW;


namespace sict {
	
	
	Product::Product() :productNum{ 0 }, itemPrice{0}{
		
	}

	Product::Product(const int num, const double p) {
		
		productNum= num;
		itemPrice = p;

	}

	double Product::price() const {
		return itemPrice;
	}


	bool Product::empty()const {
		return productNum == 0 ? true : false;
	}

	Product::~Product() {

	}
	//
	void Product::display(std::ostream& os) const {
		
	//	os << std::ios::fixed << std::setprecision(2);
		os << std::setw(FW) << productNum;
		os.setf(std::ios::fixed);
		os.precision(2); 
		os<<std::setw(FW) << itemPrice ;
	}

	std::ostream& operator<<(std::ostream& os, const iProduct& p) {
		p.display(os);
		return os;
	}


	iProduct* readRecord(std::ifstream & in) {
		iProduct* product = nullptr;
		unsigned no;
		double price;
		char tax;
		in >> no >> price;
		if (in.get() != '\n')
			in >> tax;
		else
			tax = ' ';
		if (in.good()) {
			if (tax !=  ' ')
				product = new TaxableProduct(no, price, tax);
			else
				product = new Product(no, price);
		}
		return product;
	}

}



