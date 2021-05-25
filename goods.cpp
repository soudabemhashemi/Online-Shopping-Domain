#include "goods.hpp"

std::string Goods::get_name(){
    return name;
}

int Goods::get_id(){
    return id;
}

void Goods::save_comment(std::string _comment, User* user){
    comment.push_back(_comment);
    whos_comment.push_back(user);
    std::cout<<DONE<<std::endl;
}

void Goods::show_your_comments(){
    cout<<name<<endl;
    for(int i=0; i<comment.size(); i++)
       cout<<whos_comment[i]->get_username()<<" | "<<comment[i]<<endl;
}
       
std::string Goods::get_type(){
    return type;
}

std::vector<std::string> Goods::get_tapic_of_property(){
    return property;
}
