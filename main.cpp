#include <iostream>
#include "readfile.hpp"
#include <string>
#include "define.hpp"

using namespace std;

int main(){
  Store friday_market(1);
  string command;
  User* user=friday_market.get_admin();
  while(getline(cin,command)){
    try{
    if(command.substr(0,4)== POST){
       if(command.find(IMPORTPRODUCTS)!= NOT_FOUND)
           operation_on_products(command, &friday_market, user);
       else if(command.find(LOGOUT)!= NOT_FOUND)
           user=logout_store_status(&friday_market);
       else if(command.find(SIGNUP)!= NOT_FOUND)
           user=signup_user(command, &friday_market);
       else if(command.find(LOGIN)!= NOT_FOUND)
           user=login_user(command, &friday_market);
       else if(command.find(" offer ")!= NOT_FOUND)
	   set_an_offer(command, user, &friday_market);
       else if(command.find(" changeOffer ")!= NOT_FOUND)
           change_offer(command, user);
       else if(command.find("comment ")!= NOT_FOUND)
           set_comment(command, &friday_market, user);
       else if(command.find("addToCart ")!= NOT_FOUND)
           add_offer_to_card(command, user, &friday_market);
       else if(command.find("submitCart")!= NOT_FOUND)
           ((Buyer*) user)->submit_packet(&friday_market);
        else if(command.find(" chargeWallet ")!= NOT_FOUND)
           charge_wallet(command, user);
        else if(command.find(" generateDiscountCode ")!= NOT_FOUND)
            cout<<friday_market.set_discount(command, user)<<endl;
        else throw Find_path();
    }
    else if(command.substr(0,3)== GET){
        if(command.find(" getProducts")!= NOT_FOUND)
           show_products(&friday_market, user);
       else if(command.find(" myOffers")!= NOT_FOUND)
           show_offers(user);
       else if(command.find(" wallet ")!= NOT_FOUND)
           print_balance(command, user);
       else if(command.find("offers")!= NOT_FOUND)
           see_sellers_offers(command, &friday_market, user);
       else if(command.find(" offersOnProduct ")!= NOT_FOUND)
           see_offers_on_product(command, &friday_market, user);
       else if(command.find("comments ")!= NOT_FOUND)
           show_comments(command, &friday_market);
       else if(command.find("compare ")!= NOT_FOUND)
           comparison(command, &friday_market);
       else if(command.find(" productDetail ")!= NOT_FOUND)
           friday_market.show_properties_of_product(command, user);
      else throw Find_path();
    }
    else throw Bad_request();
   }catch(exception& e){
     cout<<e.what();
   }
  }
  return 0;
}
