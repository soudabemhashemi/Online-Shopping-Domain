#ifndef __MOBILE_HPP__
#define __MOBILE_HPP__

#include "goods.hpp"
#include <string>

using namespace std;

class Mobile: public Goods{
  public:
    Mobile(string name, int weight, float CPU_frequency, int memory, int RAM ,float display_size, 
            int camera_resolution, string operating_system, int id, std::vector<std::string> property);
    std::vector<std::string> callect_properties();
  private:
    int weight;
    float CPU_frequency;
    int memory;
    int RAM;
    float display_size;
    int camera_resolution;
    string operating_system;
};

#endif
