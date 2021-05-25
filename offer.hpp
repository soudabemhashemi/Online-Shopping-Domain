#ifndef __OFFER_HPP__
#define __OFFER_HPP__

#include<iostream>
#include <string>
#include "define.hpp"

class Offer{
	public:
		Offer(int product_id, float unit_price, int amount, int offer_id);
                void print_info();
                void print_info(std::string name);
                int get_id();
                float get_price();
                int get_product_id();
                void update(float offer_unit_price, int offer_amount);
                bool have_that_amount(int amount);
          
	private:
		int product_id;
                int offer_id;
                float unit_price;
                int amount;
		
};

#endif
