#ifndef __SELLER_HPP__
#define __SELLER_HPP__

#include<iostream>
#include "user.hpp"
#include <vector>
#include "offer.hpp"
#include "admin.hpp"
#include "sale.hpp"
#include "define.hpp"

class Seller: public User{
	public:
		Seller(std::string email, std::string username, std::string password, int id, std::string type);
	        void set_offers(int product_id, float unit_price, int amount, int offer_id, User* admin);
		void display_offers();
                bool is_valid_offer(int product_id, std::string forwhat);
                bool is_valid_offer(int offer_id);
                void change_your_offer(int offer_id, float offer_unit_price, int offer_amount);
                void display_this_product(std::string name, int product_id);
                void increase_balance(float m);
                Sale* set_discount_for_seller(int offer_id, float discount_percent, int discount_number, std::string code);
	private:
		std::vector<Offer*> offers;
};

#endif
