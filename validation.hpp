#ifndef __VALIDATION_HPP__
#define __VALIDATION_HPP__

#include <string>
#include "exception.hpp"
#include "user.hpp"

#define NOT_FOUND -1

using namespace std;
bool check_legal_for_signup(string command);
bool check_legal_for_import_product(string command, User* user);
bool check_legal_input_for_see_sellers_offers(string command, User* user);
bool check_for_legal_show_products(User* user);
bool check_legal_for_set_an_offer(string command, User* user);
bool check_legal_to_change_offer(string command, User* user);
bool check_legal_to_set_discount(string command, User* user);
bool check_legal_to_see_offers_on_products(string command, User* user);
bool check_legal_to_add_offer_to_card(string command, User* user);
#endif
