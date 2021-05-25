#ifndef __GOODS_HPP__
#define __GOODS_HPP__

#include <iostream>
#include <string>
#include <vector>
#include "user.hpp"
#include "define.hpp"

#define DELIMITER ','
#define NOT_FOUND -1

class Goods{
	public:
	        std::string get_name();
                int get_id();
                std::string get_type();
                void save_comment(std::string comment, User* user);
                void show_your_comments();
                virtual std::vector<std::string> callect_properties(){}
                std::vector<std::string> get_tapic_of_property();
	protected:
		std::string name;
                int id;
                std::string type;
                std::vector<std::string > comment;
                std::vector<User* > whos_comment;
		std::vector<std::string > property;
};

#endif
