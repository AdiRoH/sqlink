#ifndef bushH
#define bushH

	#include "car_t_H.h"

	class bus_t:public car_t
	{
		public:
			inline ~bus_t();
			inline bus_t();
			inline bus_t(const bus_t& bus);
			inline const bus_t& operator=(const bus_t& bus);
			inline const unsigned int& accelarate();
			inline const unsigned int& reduceSpeed();

		private:
			unsigned int speed;
				
	};

	inline bus_t::~bus_t(){}

	inline bus_t::bus_t()
	{
		speed=0;
	}


	inline bus_t::bus_t(const bus_t& bus)
	{
		speed=bus.speed;
	}


	inline const bus_t& bus_t::operator=(const bus_t& bus)
	{
		if(speed!=bus.speed)
			speed=bus.speed;
		return *this;
	}


	inline const unsigned int& bus_t::accelarate()
	{
		speed+=10;
		return speed;
	}

	inline const unsigned int& bus_t::reduceSpeed()
	{
		speed+=10;
		return speed;
	}

#endif