#include "store.hpp"

Store::Store(bool _status){
    status=_status;
    admin=new Admin("admin@gmail.com", "admin", "admin", 0, "admin");
}
   
User* Store::logout(){
     if(status) {
         status=0;
         cout<<DONE<<endl;
         return NULL;
     }
     else throw Permission();
}

void Store::just_change_status(){
   if(status)
     status=0;
   else
     status=1;
}

User* Store::signup(std::string email, std::string username, std::string password, std::string type){
    if(!check_valid_email(email,"logout")){
       User *new_user=NULL;
       if(type=="buyer")
           new_user=new Buyer(email, username, password, users.size()+1, "buyer");
       if(type=="seller")
           new_user=new Seller(email, username, password, users.size()+1, "seller");
       cout<<DONE<<endl;
       users.push_back(new_user);
       just_change_status();
       return new_user;
     }
}

void Store::add_products(std::string good, std::vector<std::string> features, std::vector<std::string> property){
       Goods *m=NULL;
       if(good=="Mobile")
            m=new Mobile(features[0],stoi(features[1]),stof(features[2]),stoi(features[3]),stoi(features[4]),
                              stof(features[5]),stoi(features[6]),features[7], products.size()+1, property);
       else if(good=="Car")
            m=new Car(features[0],stoi(features[1]),stoi(features[2]),stoi(features[3]),stoi(features[4]),stoi(features[5]), products.size()+1, property);
       else  if(good=="Tv")
            m=new Tv(features[0],stoi(features[1]),features[2],features[3],stoi(features[4]),stoi(features[5]), products.size()+1, property);
       products.push_back(m); 
}


bool Store::check_valid_email(std::string email, std::string s){
    for(int i=0; i<users.size(); i++)
       if(users[i]->is_email(email) || admin->is_email(email)){
           if(s=="logout") throw Bad_request();
               return true;
        }
    if(s=="login") throw Bad_request();
    return false;
}

User* Store::login(std::string email, std::string password){
    if(check_valid_email(email, "login")){
      for(int i=0; i<users.size(); i++)
        if(users[i]->is_email(email))
           if(users[i]->is_correct_password(password)){
              just_change_status();
              cout<<DONE<<endl;
              return users[i];
           }
       if(admin->is_email(email) && admin->is_correct_password(password)){
              just_change_status();
              cout<<DONE<<endl;
              return admin;
         }
    }
}

void Store::show_products(){
    cout<<"productId | productName"<<endl;
    for(int i=0; i<products.size(); i++)
       cout<<products[i]->get_id()<<" | "<<products[i]->get_name()<<endl;
}

bool Store::is_valid_product_for(int product_id, std::string for_what){
    for(int i=0; i<products.size(); i++)
       if(products[i]->get_id() == product_id)
          return true;
    if(for_what=="set offer") throw Bad_request();
    if(for_what=="see offer") throw Find_path();
}

int Store::get_last_offer_id(){
    return ((Admin*) admin)->whats_last_offer_id();
}

User* Store::get_admin(){
   return admin;
}

void Store::show_offers(std::string order, std::string field){
    ((Admin*) admin)->show_offers_in_order(order, field);
}

void Store::show_all_offers(){
    ((Admin*) admin)->show_offers_in_order();
}

void Store::print_offers_on_product(int product_id){
    if(is_valid_product_for(product_id, "see offer")){
       string name;
       cout<<"productId | productName | offerId | offerUnitPrice | offerAmount"<<endl;
       for(int i=0; i<products.size(); i++)
          if(products[i]->get_id() == product_id)
             name=products[i]->get_name();
       for(int i=0; i<users.size(); i++)
         if(users[i]->get_type() == "seller")
            if(((Seller*) users[i])->is_valid_offer(product_id,"see offer"))
               ((Seller*) users[i])->display_this_product(name, product_id);
     }
}

void Store::set_comment_to_product(int product_id, std::string comment, User* user){
      bool found=false;
      for(int i=0; i<products.size(); i++)
         if(products[i]->get_id() == product_id){
            found=true;
            products[i]->save_comment(comment, user);
         }
      if(found==false) throw Find_path();
}

void Store::show_comments_on(int product_id){
    for(int i=0; i<products.size(); i++)
       if(products[i]->get_id() == product_id)
          products[i]->show_your_comments();
}

void Store::increase_seller_balance(Offer* offer, float m){
     for(int i=0; i<users.size(); i++)
        if(users[i]->get_type() == "seller" && ((Seller*) users[i]) ->is_valid_offer(offer->get_id() ))
            ((Seller*) users[i]) ->increase_balance(m);
}

void Store::compare(int id1, int id2){
    for(int i=0; i<products.size(); i++)
       for(int j=0; j<products.size(); j++)
          if(products[i]->get_id() == id1 && products[j]->get_id() == id2)
             if(products[i]->get_type() == products[j]->get_type());
}

std::string make_random_string(){
    char alphabet[MAX]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    string res="";
    for (int i=0; i<DISCOUNT_CODE_LEN; i++)
       res=res+alphabet[rand() % MAX];
   return res;
}

std::string Store::set_discount(std::string command, User* user){
     if(check_legal_to_set_discount(command, user)){
       std::string code;
       while(true){
         srand(time(NULL));
         code=make_random_string();
         if(is_unic_code(code)) break;
       }
        int length=command.find("discountPercent")-command.find("offerId")-8;
        int offer_id=stoi(command.substr(command.find("offerId")+7, length));
        length=command.find("discountNumber")-command.find("discountPercent")-16;
        float discount_percent=stof(command.substr(command.find("discountPercent")+15, length));
        int discount_number=stoi(command.substr(command.find("discountNumber")+14));
        Sale* s=((Seller*) user)->set_discount_for_seller(offer_id, discount_percent, discount_number, code);
        sales.push_back(s);
        return code;
    }
}

bool Store::is_unic_code(std::string code){
   for(int i=0; i<sales.size(); i++)
     if(sales[i]->get_code() == code)
       return false;
  return true;
}

void print(std::vector<std::string> pro, std::vector<std::string> topic_pro){
   for(int i=0; i<pro.size(); i++)
     cout<<topic_pro[i]<<": "<<pro[i]<<endl;
}

void Store::show_properties_of_product(std::string command, User* user){
   if(check_legal_to_see_offers_on_products(command,user)){
      std::vector<std::string> pro;
      std::vector<std::string> topic_pro;
      int product_id=stoi(command.substr(command.find("productId")+9));
      for(int i=0; i<products.size(); i++)
        if(products[i]->get_id()==product_id){
           cout<<products[i]->get_name()<<endl;
           pro=products[i]->callect_properties();
           topic_pro=products[i]->get_tapic_of_property();
        }
        print(pro, topic_pro);
    }
}

bool Store::has_discount_code(std::string discount_code){
    if(sales.size()==0) return true;
    for(int i=0; i<sales.size(); i++)
      if(sales[i]->get_code() == discount_code)
         return true;
    throw Bad_request();
}

bool Store::is_legal_amount(int offer_id, int amount){
    if(((Admin*) admin)->check_amount_of_offers(offer_id, amount))
       return true;
}

float Store::how_percent_off(Offer* offer){
    for(int i=0; i<sales.size(); i++)
      if(sales[i]->get_offer() == offer)
         return sales[i]->get_percent();
}

