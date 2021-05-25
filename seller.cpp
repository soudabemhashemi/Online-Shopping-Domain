#include "seller.hpp"

Seller::Seller(std::string email, std::string username, std::string password, int id, std::string type):User(email, username, password, id, type){}

void Seller::set_offers(int product_id, float unit_price, int amount, int offer_id, User* admin){
    Offer *new_offer=new Offer(product_id, unit_price, amount, offer_id);
    offers.push_back(new_offer);
    ((Admin*) admin)->give_offer(new_offer);
    std::cout<<DONE<<std::endl;
}

void Seller::display_offers(){
    cout<<"productId | offerId | offerUnitPrice | offerAmount"<<endl;
    for(int i=0; i<offers.size(); i++)
       offers[i]->print_info();
}

bool Seller::is_valid_offer(int product_id, std::string forwhat){
    for(int i=0; i<offers.size(); i++)
        if(offers[i]->get_product_id() == product_id){
           if(forwhat=="set offer") throw Bad_request();
           return true;
        }
   return false;
}

bool Seller::is_valid_offer(int offer_id){
    for(int i=0; i<offers.size(); i++)
        if(offers[i]->get_id() == offer_id)
           return true;
   return false;
}

void Seller::change_your_offer(int offer_id, float offer_unit_price, int offer_amount){
    bool found=false;
    for(int i=0; i<offers.size(); i++)
        if(offers[i]->get_id() == offer_id){
           offers[i]->update(offer_unit_price, offer_amount);
           found=true;
        }
    if(found==false) throw Bad_request();
}

void Seller::display_this_product(std::string name, int product_id){
    for(int i=0; i<offers.size(); i++)
       if(offers[i]->get_product_id() == product_id) 
          offers[i]->print_info(name);
}

void Seller::increase_balance(float m){
     balance.push_back(balance[balance.size()-1]+m);
}

Sale* Seller::set_discount_for_seller(int offer_id, float discount_percent, int discount_number, std::string code){
    for(int i=0; i<offers.size(); i++)
      if(offers[i]->get_id()==offer_id){
          Sale* discount=new Sale(offers[i], discount_percent, discount_number, code);
          return discount;
      }
    throw Find_path();
}










