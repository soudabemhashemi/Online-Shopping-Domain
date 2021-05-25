#include "mobile.hpp"

Mobile::Mobile(string _name, int _weight, float _CPU_frequency, int _memory, int _RAM ,float _display_size
              , int _camera_resolution, string _operating_system, int _id, std::vector<std::string> property1){
                       name=_name;
                       weight=_weight;
                       CPU_frequency=_CPU_frequency;
                       memory=_memory;
                       RAM=_RAM;
                       display_size=_display_size;
                       camera_resolution=_camera_resolution;
                       operating_system=_operating_system;
		       id=_id;
                       type="mobile";
		       for(int i=0; i<property1.size(); i++)
                             property.push_back(property1[i]);
}

std::vector<std::string> Mobile::callect_properties(){
   std::vector<std::string> pro;
   for(int i=0; i<property.size(); i++){
      if(property[i]=="Weight") pro.push_back(to_string(weight));
      else if(property[i]=="CPU Frequency") pro.push_back(to_string(CPU_frequency));
      else if(property[i]=="Built-in Memory") pro.push_back(to_string(memory));
      else if(property[i]=="RAM") pro.push_back(to_string(RAM));
      else if(property[i]=="Display Size") pro.push_back(to_string(display_size));
      else if(property[i]=="Camera Resolution") pro.push_back(to_string(camera_resolution));
      else if(property[i]=="Operating System") pro.push_back(operating_system);
   }
   return pro;
}

