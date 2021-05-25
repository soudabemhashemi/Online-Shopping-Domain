#include "validation.hpp"

bool check_legal_for_signup(string command){
   if(command.find(" username ")!= NOT_FOUND && command.find(" email ")!= NOT_FOUND 
                                                     && command.find(" password ")!= NOT_FOUND)
       return true;
   else throw Bad_request();
}

bool check_legal_for_import_product(string command, User* user){
      if(user==0 || user->get_type()!="admin") 
          throw Permission();
      if(command.find(" type ")!= NOT_FOUND && command.find(" filePath ")!= NOT_FOUND)
          return true;
   else throw Bad_request();
}

bool check_legal_input_for_see_sellers_offers(string command, User* user){
     if(user==0 || user->get_type()!="admin") 
          throw Permission();
     if(command.find(" order ")!= NOT_FOUND && command.find(" field ")!= NOT_FOUND)
          return true;
   else throw Bad_request();
}

bool check_for_legal_show_products(User* user){
    if(user->get_type()=="seller" || user->get_type()=="buyer")
         return true;
     else throw Permission();
}

bool check_legal_for_set_an_offer(string command, User* user){
     if(user==0 || user->get_type()!="seller") 
          throw Permission();
     if(command.find(" productId ")!= NOT_FOUND && command.find(" offerUnitPrice ")!= NOT_FOUND 
                     && command.find(" offerAmount ")!= NOT_FOUND){
          return true;}
     else throw Bad_request();
}

bool check_legal_to_change_offer(string command, User* user){
    if(user==0 || user->get_type()!="seller") 
          throw Permission();
     if(command.find(" offerId ")!= NOT_FOUND && command.find(" offerUnitPrice ")!= NOT_FOUND 
                     && command.find(" offerAmount ")!= NOT_FOUND)
          return true;
   else throw Bad_request();
}

bool check_legal_to_set_discount(string command, User* user){
   if(user==0 || user->get_type()!="seller") 
          throw Permission();
     if(command.find(" offerId ")!= NOT_FOUND && command.find(" discountPercent ")!= NOT_FOUND 
                     && command.find(" discountNumber ")!= NOT_FOUND)
          return true;
   else throw Bad_request();
}

bool check_legal_to_see_offers_on_products(string command, User* user){
    if(user==0 || user->get_type()!="buyer") 
          throw Permission();
     if(command.find(" productId ")!= NOT_FOUND)
          return true;
   else throw Bad_request();
}

bool check_legal_to_add_offer_to_card(string command, User* user){
      if(user==0 || user->get_type()!="buyer") 
          throw Permission();
     if(command.find(" offerId ")!= NOT_FOUND && command.find(" amount ")!= NOT_FOUND)
          return true;
     else throw Bad_request();
}
