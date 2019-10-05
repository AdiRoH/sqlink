#include "car_t_H.h"
#include <string.h>
#include <string>

using namespace std;

long car_t::m_ID=0;

car_t::car_t()
{
	this->m_capacity = 1500;
	this->m_gear = manual;
	this->m_name = "private";
	this->m_ID++;
}

car_t::car_t(const car_t &old_car) 
{
	this->m_capacity = old_car.m_capacity;
	this->m_gear = old_car.m_gear;
	this->m_name = old_car.m_name;
	this->m_ID = old_car.m_ID;
}

car_t::car_t(const unsigned int capCC,const string carName,const unsigned long ID,string gearKind)
{
	this->m_capacity = capCC;
	m_name.assign(carName);
	this->m_ID = ID;
	if(gearKind=="Auto") m_gear=Auto; //1=Auto
}

