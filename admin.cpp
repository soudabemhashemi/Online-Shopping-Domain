#include "admin.hpp"

Admin::Admin(std::string email, std::string username, std::string password, int id, std::string type):User(email, username, password, id, type){}

int Admin::whats_last_offer_id(){
    return all_offers.size();
}

void Admin::give_offer(Offer* o){
   all_offers.push_back(o);
}
std::vector<Offer* > order_ascend_offerId(std::vector<Offer* > a){
    std::vector<int> id;
    std::vector<Offer* > b(a.size());
    for(int i=0; i<a.size(); i++)
       id.push_back( a[i]->get_id() );
    sort(id.begin() , id.end() );
    for(int i=0; i<id.size(); i++)
       for(int j=0; j<a.size(); j++)
          if(a[j]->get_id() == id[i])
             b[i]=a[j];
    return b;
}

std::vector<Offer* > order_descend_offerId(std::vector<Offer* > a){
    std::vector<int> id;
    std::vector<Offer* > b(a.size());
    for(int i=0; i<a.size(); i++)
       id.push_back( a[i]->get_id() );
    sort(id.begin() , id.end() , greater<int>() );
    for(int i=0; i<id.size(); i++)
       for(int j=0; j<a.size(); j++)
          if(a[j]->get_id() == id[i])
             b[i]=a[j];
    return b;
}

std::vector<Offer* > order_ascend_offerPrice(std::vector<Offer* > a){
    std::vector<float> price;
    std::vector<Offer* > b(a.size());
    for(int i=0; i<a.size(); i++)
       price.push_back( a[i]->get_price() );
    sort(price.begin() , price.end() );
    for(int i=0; i<price.size(); i++)
       for(int j=0; j<a.size(); j++)
          if(a[j]->get_price() == price[i])
             b[i]=a[j];
    return b;
}

std::vector<Offer* > order_descend_offerPrice(std::vector<Offer* > a){
    std::vector<float> price;
    std::vector<Offer* > b( a.size() );
    for(int i=0; i<a.size(); i++)
       price.push_back( a[i]->get_price() );
    sort(price.begin() , price.end() , greater<float>() );
    for(int i=0; i<price.size(); i++)
       for(int j=0; j<a.size(); j++)
          if(a[j]->get_price() == price[i])
             b[i]=a[j];
    return b;
}

void print_vector(std::vector<Offer* > new_order){
    cout<<"productId | offerId | offerUnitPrice | offerAmount"<<endl;
    for(int i=0; i<new_order.size(); i++)
       new_order[i]->print_info();
}

void Admin::show_offers_in_order(std::string order, std::string field){
     std::vector<Offer* > new_order;
     if(order=="ASCEND" && field=="offerId")
         new_order=order_ascend_offerId(all_offers);
     if(order=="DESCEND" && field=="offerId")
         new_order=order_descend_offerId(all_offers);
     if(order=="ASCEND" && field=="offerPrice")
         new_order=order_ascend_offerPrice(all_offers);
     if(order=="DESCEND" && field=="offerPrice")
         new_order=order_descend_offerPrice(all_offers);
     print_vector(new_order);
}

void Admin::show_offers_in_order(){
   print_vector(all_offers);
}
        
bool Admin::check_request(int offer_id, int amount){ cout<<"hello\n";
    for(int i=0; i<all_offers.size(); i++)
       if(all_offers[i]->get_id() == offer_id)
          if(all_offers[i]->have_that_amount(amount))
              return true;
    throw Bad_request();
}

float Admin::calculate_money(std::vector<Packet*> card, Store* s){
     float m;
     float off=0;
     for(int i=0; i<card.size(); i++)
        for(int j=0; j<all_offers.size(); j++)
            if(card[i]->get_offer_id() == all_offers[j]->get_id() ){
                off=s->how_percent_off(all_offers[j]);
                m=card[i]->calc(all_offers[j]->get_price(), off);
                return m;
            }
}

bool Admin::check_amount_of_offers(int offer_id, int amount){
    for(int i=0; i<all_offers.size(); i++)
       if(all_offers[i]->get_id() == offer_id && all_offers[i]->have_that_amount(amount))
           return true;
    throw Bad_request();
}


void Admin::increase_seller_balance(std::vector<Packet*> card, float money, Store* s){
   for(int i=0; i<card.size(); i++)
        for(int j=0; j<all_offers.size(); j++)
            if(card[i]->get_offer_id() == all_offers[j]->get_id() )
                    s->increase_seller_balance(all_offers[j], money);
}
