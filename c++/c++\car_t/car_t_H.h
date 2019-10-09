#ifndef car_t_H
#define car_t_H
	
	#include <string>
	#include <string.h>

	using namespace std; 

	class car_t
	{
		public:                                                                              //Auto or manual gear
			inline ~car_t();                                                                  //DTOR
			car_t();                                                                		  //CTOR
			car_t(const car_t& old_car);                                                      //copy CTOR		                                                                          
			car_t(const unsigned int capCC,const string carName,const unsigned long ID,string gearKind);      //CTOR      
			inline const car_t& operator=(const car_t& car);                                  //assign operator 
			const string getName() const;
			inline bool operator<(const car_t& car);
			inline bool operator==(const car_t& car);
			enum gear{manual,Auto};

		private:
			 
			unsigned int m_capacity;
			gear m_gear;
			string m_name;
			static long m_ID;

			void createCar();
			inline static void setGear(const string& carGear);
			inline static string& getGear();
	};

	inline car_t::~car_t()
	{
		m_ID=0;
	} 

	inline const string car_t::getName() const
	{
		return m_name;
	}

	inline bool car_t::operator<(const car_t& car) 
	{
		return car.m_capacity<m_capacity;
	}

	inline const car_t& car_t::operator=(const car_t& car) 
	{
		if(car.m_capacity != m_capacity)
	    	m_capacity = car.m_capacity;
	    return *this;
	}

	inline void car_t::setGear(const string& carGear)
	{
		if(carGear=="Auto")
			m_gear=Auto; //1=Auto
	}

	inline string& car_t::getGear() 
	{
		return (m_gear==manual)?"manual":"automatic";
	}


	inline bool car_t::operator==(const car_t& car)
	{
		bool res;
		(car.m_name==this->m_name)?res = true:res = false;
		return res;
	}

#endif

