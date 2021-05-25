#ifndef __BUYER_HPP__
#define __BUYER_HPP__

#include "user.hpp"
#include "packet.hpp"
#include "store.hpp"
#include "define.hpp"
class Store;

class Buyer: public User{
	public:
		Buyer(std::string email, std::string username, std::string password, int id, std::string type);
		void add_offer_to_your_card(int offer_id, int amount, std::string discount_code);
		void submit_packet(Store* s);
                void charge_your_wallet(float amount);
	private:
		std::vector<Packet* > card;
};

#endif
