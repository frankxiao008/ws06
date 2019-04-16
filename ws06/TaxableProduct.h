#pragma once

#ifndef SICT_TAX_H
#define SICT_TAX_H

#include "Product.h"

namespace sict {
	//const double HST = 0.13;
	//const double PST = 0.08;
	class TaxableProduct :public Product {
		enum  { HST, PST } tax;
		static double  rate[2];
	public:
		double price() const;
		void display(std::ostream& os)const;
		TaxableProduct(unsigned productnum, double productcost, char taxstatus);
	};


}

#endif
