#ifndef __PACKET_HPP__
#define __PACKET_HPP__

#include <string>

class Packet{
	public:
		Packet(int offer_id, int amount, std::string discount_code);
                void submiting();
                int get_offer_id();
                float calc(float price, float off);
	private:
		int offer_id;
                int amount;
		std::string discount_code;
                bool submitted;
};

#endif
