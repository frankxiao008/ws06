//Workshop 6-Sale.cpp
//Name:		Saihong Xiao
//Student ID:	140777178
//Email:		sxiao15@myseneca.ca
//



#include <iostream>
#include <fstream>
#include <iomanip>
#include "Sale.h"
#include "iProduct.h"



extern int FW;

namespace sict {
	
	Sale::Sale() :product {} {

	}

	//constructor
	//
	Sale::Sale(const char* filename ) {
		std::ifstream file(filename);
		if (!file)
			throw std::string("*** Failed to open file ") + std::string(filename) + std::string("***");
		bool keepreading = true;
		do {
			iProduct* p = readRecord(file);
			if (p)
				product.push_back(std::move(p));
			else
				keepreading = false;
		} while (keepreading);

	}


	Sale::~Sale() {
		for (auto i : product)
			delete i;
	}

	//new display
	//
	void Sale::display(std::ostream& os)const {
		double total=0.0;
		os << std::fixed << std::setprecision(2);
		os << std::setw(FW) << "Product No" << std::setw(FW) << "Cost" << "Taxable" << std::endl;
		for (auto i : product ) {
					
				total += i->price();
				os << *i << std::endl;
			  
		};	

		os << std::setw(FW) << "Total"  <<std::setprecision(2) <<std::setw(FW) <<total << std::endl;
		os.unsetf(std::ios::fixed);

	}
}