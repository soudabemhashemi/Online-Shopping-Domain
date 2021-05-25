#include "sale.hpp"


Sale::Sale(Offer* _offer, int _discount_percent, int _discount_number, std::string _code){
    offer=_offer;
    discount_percent=_discount_percent; 
    discount_number=_discount_number;
    code+_code;
}

std::string Sale::get_code(){
   return code;
}

int Sale::get_percent(){
   return discount_percent;
}
               
Offer* Sale::get_offer(){
   return offer;
}
