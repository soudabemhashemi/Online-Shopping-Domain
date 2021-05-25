#include "car.hpp"

Car::Car(std::string _name, int _weight, int _num_of_seats, int _num_of_cylinders, int _engine_capacity,
           bool _reverse_parking_sensors, int _id, std::vector<std::string> _property){
     name=_name;
     weight=_weight;
     num_of_seats=_num_of_seats;
     num_of_cylinders=_num_of_cylinders;
     engine_capacity=_engine_capacity;
     reverse_parking_sensors=_reverse_parking_sensors;
     id=_id;
     type="car";
     for(int i=0; i<_property.size(); i++)
         property.push_back(_property[i]);
}

std::vector<std::string> Car::callect_properties(){
   std::vector<std::string> pro; 
   for(int i=0; i<property.size(); i++){
      std::string x=reverse_parking_sensors?"1":"0";
      if(property[i]=="Weight") pro.push_back(to_string(weight));
      else if(property[i]=="Num. of Seats") pro.push_back(to_string(num_of_seats));
      else if(property[i]=="Num. of Cylinders") pro.push_back(to_string(num_of_cylinders));
      else if(property[i]=="Engine Capacity") pro.push_back(to_string(engine_capacity));
      else if(property[i]=="Reverse Parking Sensors") pro.push_back(x);
   }
   return pro;
}









