#include "user.hpp"

User::User(std::string email, std::string _username, std::string _password, int _id, std::string _type){
    mail=email;
    username=_username;
    string hashed_password = md5(_password);
    password=hashed_password;
    id=_id;
    balance.push_back(0);
    type=_type;
  }

bool User::is_email(std::string email){
    if(email==mail)
       return true;
    else
       return false;
}

bool User::is_correct_password(std::string _password){
    if(md5(_password)==password)
       return true;
    else{
      throw Bad_request();
      return false;
      }
}

void User::set_offers(int product_id, float unit_price, int amount){}

void User::print_your_transaction(int count){
    cout<<"credit"<<endl;
    int i=balance.size()-1;
    int c=0; 
    while(true){
        cout<<balance[i]<<endl;
        i--;
        c++;
        if(i==-1 || c==count) break;
   }
}

std::string User::get_type(){
     return type;
}

std::string User::get_username(){
     return username;
}
