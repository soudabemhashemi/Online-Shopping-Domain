#ifndef __USER_HPP__
#define __USER_HPP__

#include<iostream>
#include <string>
#include "exception.hpp"
#include <vector>
#include "md5.hpp"
using namespace std;
class User{
	public:
                User(std::string email, std::string username, std::string password, int id, std::string type);
                bool is_email(std::string email);
                bool is_correct_password(std::string password);
                void set_offers(int product_id, float unit_price, int amount);
                void print_your_transaction(int count);
                std::string get_type();
                std::string get_username();
	protected:
		std::string mail;
                std::string username;
                std::string password;
                std::string type;
		int id;
		std::vector<float> balance;
};

#endif
