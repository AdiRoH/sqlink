#ifndef car_t_H
#define car_t_H

	class car_t
	{
		public:
			inline ~car_t();//deleting also static private variable?
			inline car_t(const car_t &old_car);
			car_t();
			car_t(const unsigned int capCC,const char* carName,const unsigned long ID);
			inline car_t& operator=(const car_t& car);
			inline void getName(const char* carName);//assignment value- is the value is const?
			inline bool operator<(const car_t& car);//diffrent between operators of two objects and 2 fields
			bool operator==(const car_t& car);
			

		private:
			unsigned int capacity;
			char* name;
			const static char* gear;//how to allocate static variable?
			static long ID;
			void createCar();
			static void setGear(const char* carGear);
			static const char* getGear();
	};

	inline car_t::~car_t()
	{
		ID--;
		delete[] name;
	}

	inline car_t::car_t(const car_t &old_car) 
	{
		capacity = old_car.capacity;
	} 

	inline void car_t::getName(const char* carName)
	{
		name = (char*)carName;
	}

	inline bool car_t::operator<(const car_t& car) 
	{
		return car.capacity<capacity;
	}

	inline car_t& car_t::operator=(const car_t& car) 
	{
	    capacity=car.capacity;
	}

#endif

