#ifndef __CAR_HPP__
#define __CAR_HPP__

#include "goods.hpp"

class Car: public Goods{
	public:
              Car(std::string name, int weight, int num_of_seats, int num_of_cylinders, int engine_capacity, bool reverse_parking_sensors,
                     int id, std::vector<std::string> property);
              std::vector<std::string> callect_properties();
	private:
		int weight;
		int num_of_seats;
		int num_of_cylinders;
		int engine_capacity;
		bool reverse_parking_sensors;
};

#endif
