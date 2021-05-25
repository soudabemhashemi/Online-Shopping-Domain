#include "packet.hpp"

Packet::Packet(int _offer_id, int _amount, std::string _discount_code){
     offer_id=_offer_id;
     amount=_amount;
     discount_code=_discount_code;
     submitted=0;
}

void Packet::submiting(){
   submitted=1;
}

int Packet::get_offer_id(){
   return offer_id;
}

float Packet::calc(float price, float off){
      price -= price*(off/100);
      return amount*price;
}

