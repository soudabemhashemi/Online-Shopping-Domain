#ifndef __SALE_HPP__
#define __SALE_HPP__
#include "offer.hpp"
#include <string>

class Sale{
	public:
		Sale(Offer* offer, int discount_percent, int discount_number, std::string code);
                std::string get_code();
                int get_percent();
                Offer* get_offer();
	private:
		Offer* offer;
		int discount_percent;
		int discount_number;
                std::string code;
};

#endif
