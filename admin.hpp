#ifndef __READFILE_HPP__
#define __READFILE_HPP__
#include <vector>
#include "offer.hpp"
#include "user.hpp"
#include <bits/stdc++.h>
#include "packet.hpp"
#include "store.hpp"
class Store;

class Admin: public User{
	public:
		Admin(std::string email, std::string username, std::string password, int id, std::string type);
                int whats_last_offer_id();
                void give_offer(Offer* o);
                void show_offers_in_order(std::string order, std::string field);
		void show_offers_in_order();
                bool check_request(int offer_id, int amount);
                float calculate_money(std::vector<Packet*> card, Store* s);
                bool check_amount_of_offers(int offer_id, int amount);
                void increase_seller_balance(std::vector<Packet*> card, float money, Store* s);
	private:
		std::vector<Offer*> all_offers;
};

#endif
