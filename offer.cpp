#include "offer.hpp"

Offer::Offer(int _product_id, float _unit_price, int _amount, int _offer_id){
     product_id=_product_id;
     unit_price=_unit_price;
     amount=_amount;
     offer_id=_offer_id;
}

void Offer::print_info(){
    std::cout<<product_id<<" | "<<offer_id<<" | "<<unit_price<<" | "<<amount<<std::endl;
}

void Offer::print_info(std::string name){
    std::cout<<product_id<<" | "<<name<<" | "<<offer_id<<" | "<<unit_price<<" | "<<amount<<std::endl;
}

int Offer::get_id(){
    return offer_id;
}

bool Offer::have_that_amount(int _amount){
   if(amount >= _amount)
       return true;
   else false;
}

float Offer::get_price(){
   return unit_price;
}

int Offer::get_product_id(){
    return product_id;
}

void Offer::update(float offer_unit_price, int offer_amount){
    unit_price=offer_unit_price;
    amount=offer_amount;
    std::cout<<DONE<<std::endl;
}


