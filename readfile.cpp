#include "readfile.hpp"

void readfile(string good, string path, Store* s){
    string row;
    ifstream read(path.c_str(),ios::in);
    if(read.good()){ 
       getline(read,row);
       vector<string> property=seprate_csv(row);
       while(getline(read,row)){
           vector<string> features=seprate_csv(row);
           s->add_products(good, features, property);
        }
        cout<<DONE<<endl;
    }
    else throw Find_path();	
 }

vector<string>  seprate_csv(string row){
     vector<string> features;
     while(true){
     int pos=row.find(DELIMITER);
     if(pos!=NOT_FOUND){
       if(row.substr(0,pos)!="Name")
          features.push_back(row.substr(0,pos));}
     else{
       if(row!="Name")
              features.push_back(row);
       break;
      }
     row.erase(0,pos+1);
  }
 return features;
 }



void operation_on_products(string command, Store* s, User* user){
   if(check_legal_for_import_product(command, user)){
   if(command.find(" mobile ")!= NOT_FOUND){
         string path=command.substr(command.find("filePath")+9);
         readfile("Mobile",path, s);
       }
       else if(command.find(" car ")!= NOT_FOUND){
         string path=command.substr(command.find("filePath")+9);
         readfile("Car",path, s);
       }
       else if(command.find(" tv ")!= NOT_FOUND){
         string path=command.substr(command.find("filePath")+9);
         readfile("Tv",path, s);
       }
   }
 }

User* logout_store_status(Store *s){
    return s->logout();
}

User* signup_user(string command, Store *s){
    if(check_legal_for_signup(command)){
       string type="buyer";
       int length=command.find("username")-command.find("email")-7;
       string email=command.substr(command.find("email")+6, length);
       length=command.find("password")-command.find("username")-10;
       string username=command.substr(command.find("username")+9, length);
       length=command.find("type")-command.find("password")-10;
       string password=command.substr(command.find("password")+9, length);
       if(command.find("type")!= NOT_FOUND){
           type=command.substr(command.find("type")+5);
       }
       User* user=NULL;
       user= s->signup(email, username, password, type);
       return user;
   }
}

User* login_user(string command, Store *s){
    int length=command.find("password")-command.find("email")-7;
    string email=command.substr(command.find("email")+6, length);
    string password=command.substr(command.find("password")+9);
    User* user=NULL;
    user= s->login(email, password);
    return user;
}

void show_products(Store* s, User* user){
     if(check_for_legal_show_products(user)){
         s->show_products();
      }
}

void set_an_offer(string command, User* seller, Store* s){
    if(check_legal_for_set_an_offer(command, seller)){
       int length=command.find("offerUnitPrice")-command.find("productId")-11;
       int product_id=stoi(command.substr(command.find("productId")+10, length));
       length=command.find("offerAmount")-command.find("offerUnitPrice")-15;
       float unit_price=stof(command.substr(command.find("offerUnitPrice")+14, length));
       int amount=stoi(command.substr(command.find("offerAmount")+12));
       if(s->is_valid_product_for(product_id, "set offer") && !((Seller*) seller)->is_valid_offer(product_id, "set offer")){
             int last_id=s->get_last_offer_id();
             ((Seller*) seller)->set_offers(product_id, unit_price, amount, last_id+1, s->get_admin());
             }
     }
}

void show_offers(User* user){
      if(user->get_type() == "seller")
           ((Seller*) user)->display_offers();
      else throw Permission();
}

void print_balance(string command, User* user){
   if(user->get_type()=="buyer" || user->get_type()=="seller" ){
       int count=stoi(command.substr(command.find("count")+5));
       user->print_your_transaction(count);
   }
   else throw Permission();
}

void see_sellers_offers(string command, Store* s, User* user){
   if(user->get_type()=="buyer" && command.find(" order ") == NOT_FOUND)  s->show_all_offers();
   else if(check_legal_input_for_see_sellers_offers(command, user)){
     string order;
     string field;
     if(command.find("ASCEND") != NOT_FOUND)
         order="ASCEND";
     else if(command.find("DESCEND") != NOT_FOUND)
         order="DESCEND";
     if(command.find("offerId") != NOT_FOUND)
         field="offerId";
     else if(command.find("offerPrice") != NOT_FOUND)
         field="offerPrice";
     s->show_offers(order, field);
    }
    else throw Permission();
}

void change_offer(string command, User* seller){
    if(check_legal_to_change_offer(command, seller)){
       int length=command.find("offerUnitPrice")-command.find("offerId")-8;
       int offer_id=stoi(command.substr(command.find("offerId")+7, length));
       length=command.find("offerAmount")-command.find("offerUnitPrice")-15;
       float offer_unit_price=stof(command.substr(command.find("offerUnitPrice")+14, length));
       int offer_amount=stoi(command.substr(command.find("offerAmount")+11));
       ((Seller*) seller)->change_your_offer(offer_id, offer_unit_price, offer_amount);
   }
}

void see_offers_on_product(string command, Store* s, User* user){
    if(check_legal_to_see_offers_on_products(command, user)){
       int product_id=stoi(command.substr(command.find("productId")+9));
       s->print_offers_on_product(product_id);
    }
}

void set_comment(string command, Store *s, User* user){
    int length=command.find("comment")-command.find("productId")-10;
    int product_id=stoi(command.substr(command.find("productId")+9, length));
    command.erase(0, 14);
    string comment=command.substr(command.find("comment ")+8);
    s->set_comment_to_product(product_id, comment, user);
}

void show_comments(string command, Store *s){
      int product_id=stoi(command.substr(command.find("productId")+9));
      s->show_comments_on(product_id);
}

void add_offer_to_card(string command, User* buyer, Store *s){
    if(check_legal_to_add_offer_to_card(command, buyer)){
       int amount;
       string discount_code=NO_SALE;
       int length=command.find("amount")-command.find("offerId")-8;
       int offer_id=stoi(command.substr(command.find("offerId")+7, length));
       if(command.find("discountCode") != NOT_FOUND){
          length=command.find("discountCode")-command.find("amount")-7;
          amount=stoi(command.substr(command.find("amount")+6, length));
          discount_code=command.substr(command.find("discountCode")+12);
       }
       else amount=stoi(command.substr(command.find("amount")+6));
       if(s->has_discount_code(discount_code) && s->is_legal_amount(offer_id, amount))
            ((Buyer*) buyer)->add_offer_to_your_card(offer_id, amount, discount_code);
    }
}

void  charge_wallet(string command, User* buyer){
    float amount=stof(command.substr(command.find("amount")+6));
    ((Buyer*) buyer)->charge_your_wallet(amount);
}

void comparison(string command, Store* s){
    int length=command.find("productId1")-command.find("productId2")-11;
    int id1=stoi(command.substr(command.find("productId1")+10, length));
    int id2=stoi(command.substr(command.find("productId2")+10));
    s->compare(id1, id2);
}
