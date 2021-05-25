#include "tv.hpp"

Tv::Tv(std::string _name, int _screen_size, std::string _screen_type, std::string _resolution, bool __3D, bool _HDR, int _id, std::vector<std::string> property1){
     name=_name;
     screen_size=_screen_size;
     screen_type=_screen_type;
     resolution=_resolution;
     _3D=__3D;
     HDR=_HDR;
     id=_id;
     type="tv";
     for(int i=0; i<property1.size(); i++)
        property.push_back(property1[i]);
}

std::vector<std::string> Tv::callect_properties(){
   std::vector<std::string> pro;
   for(int i=0; i<property.size(); i++){
      if(property[i]=="Screen Size") pro.push_back(to_string(screen_size));
      else if(property[i]=="Screen Type") pro.push_back(screen_type);
      else if(property[i]=="Resolution") pro.push_back(resolution);
      else if(property[i]=="3D") pro.push_back(to_string(_3D));
      else if(property[i]=="HDR") pro.push_back(to_string(HDR));
   }
   return pro;
}
