#ifndef __READFILE_HPP__
#define __READFILE_HPP__

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "validation.hpp"
#include "store.hpp"
#include "mobile.hpp"
#include "car.hpp"
#include "tv.hpp"
#include "seller.hpp"
#include "buyer.hpp"
#include "define.hpp"
class Store;
class Admin;

#define DELIMITER ','
#define NOT_FOUND -1

using namespace std;

void readfile(string good,string path, Store* s);
vector<string>  seprate_csv(string row);
void operation_on_products(string command, Store* s, User* user);
User* logout_store_status(Store* s);
User* signup_user(string command, Store *s);
User* login_user(string command, Store *s);
void show_products(Store* s, User* user);
void set_an_offer(string command, User* seller, Store* s);
void print_balance(string command, User* user);
void see_sellers_offers(string command, Store *s, User* user);
void change_offer(string command,User* seller);
void see_offers_on_product(string command, Store* s, User* user);
void set_comment(string command, Store *s, User* user);
void show_comments(string command, Store *s);
void add_offer_to_card(string command, User* buyer, Store *s);
void  charge_wallet(string command, User* buyer);
void comparison(string command, Store* s);
void show_offers(User* user);
#endif
