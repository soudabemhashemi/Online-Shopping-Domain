#include "buyer.hpp"

Buyer::Buyer(std::string email, std::string username, std::string password, int id, std::string type):User(email, username, password, id, type){}

void Buyer::add_offer_to_your_card(int offer_id, int amount, std::string discount_code){
     Packet *new_packet=new Packet(offer_id, amount, discount_code);
     card.push_back(new_packet);
     cout<<DONE<<endl;
}

void Buyer::submit_packet(Store* s){
     float money=((Admin*) s->get_admin()) ->calculate_money(card, s);
     if(money <= balance[balance.size()-1] ){
        for(int i=0; i<card.size(); i++)
           card[i]->submiting();
        balance.push_back(balance[balance.size()-1]-money);
        ((Admin*) s->get_admin()) ->increase_seller_balance(card, money, s);
        cout<<DONE<<endl;
     }
      else throw Bad_request();
}

void Buyer::charge_your_wallet(float amount){
   if(amount > 0){
       balance.push_back(balance[balance.size()-1]+amount);
       cout<<DONE<<endl;
    }
    else throw Bad_request();
}
