#ifndef __TV_HPP__
#define __TV_HPP__

#include "goods.hpp"

class Tv: public Goods{
	public:
               Tv(std::string name, int screen_size, std::string screen_type, std::string resolution, bool _3D, bool HDR, int id, std::vector<std::string> _property);
               std::vector<std::string> callect_properties();
	private:
		int screen_size;
		std::string screen_type;
		std::string resolution;
		bool _3D;
		bool HDR;
};

#endif
