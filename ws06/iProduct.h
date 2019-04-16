//Workshop 6-iProduct.h
//Name:		Saihong Xiao
//Student ID:	140777178
//Email:		sxiao15@myseneca.ca
//


#ifndef SICT_IPRODUCT_H
#define SICT_IPRODUCT_H
#include <iostream>

namespace sict {
	class iProduct {
	public:
		virtual double price() const = 0;
		virtual void display(std::ostream& os) const = 0;
		virtual bool empty() const = 0;
		virtual ~iProduct(){};

	};
	std::ostream& operator<<(std::ostream& os, const iProduct& p);

	iProduct* readRecord(std::ifstream & in);
	/*iProduct* readRecord(std::ifstream& file);*/

	//iProduct* readRecord(std::ifstream& in) {
	//	iProduct* pro = nullptr;

	//	unsigned no;
	//	double price;
	//	std::string tax;

	//	in >> no >> price;
	//	char code = file.get();
	//	if (code == ' ') {
	//		file >> code;
	//		if (code == 'H' || code == 'P') {
	//			pro = new TaxableProduct(num, cost, code);
	//		}
	//	}
	//	else {
	//		pro = new Product(num, cost);
	//	}

	//	return pro;
	//}




}
#endif



