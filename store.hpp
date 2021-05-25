#ifndef __STORE_HPP__
#define __STORE_HPP__

#include <string>
#include<iostream>
#include <vector>
#include "goods.hpp"
#include "tv.hpp"
#include "mobile.hpp"
#include "car.hpp"
#include "sale.hpp"
class User;
#include "buyer.hpp"
#include "seller.hpp"
#include "offer.hpp"
#include "validation.hpp"
#include <bits/stdc++.h>
#include "define.hpp"

#define MAX 26
#define DISCOUNT_CODE_LEN 10

class Store{
	public:
                Store(bool status);
		User* signup(std::string email, std::string username, std::string password, std::string type);
		User* login(std::string email, std::string password);
                User* logout();
		void just_change_status();
                bool check_valid_email(std::string email, std::string s);
		void show_products();
                void add_products(std::string good, std::vector<std::string> features, std::vector<std::string> property);
                bool is_valid_product_for(int product_id, std::string for_what);
                int get_last_offer_id();
                User* get_admin();
                void show_offers(std::string order, std::string field);
                void show_all_offers();
                void print_offers_on_product(int product_id);
                void set_comment_to_product(int product_id, std::string comment, User* user);
                void show_comments_on(int product_id);
                void increase_seller_balance(Offer* offer, float m);
                void compare(int id1, int id2);
                std::string set_discount(std::string command, User* user);
                bool is_unic_code(std::string code);
                void show_properties_of_product(std::string command, User* user);
                bool has_discount_code(std::string discount_code);
                bool is_legal_amount(int offer_id, int amount);
                float how_percent_off(Offer* offer);
	private:
                User* admin;
                bool status;
                std::vector<User*> users;
		std::vector<Goods*> products;
                std::vector<Sale* > sales;
};

#endif
