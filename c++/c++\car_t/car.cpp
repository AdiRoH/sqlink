#include "car_t_H.h"
#include <string.h>

const char* car_t::gear="manual";
long car_t::ID=0;

car_t::car_t()
{
	createCar();
	this->capacity = 1500;
	this->name = "shevrolet";
	this->ID++;
}

car_t::car_t(const unsigned int capCC,const char* carName,const unsigned long carID)
{
	if(this->capacity==0 || this->name==0 || this->ID==0)
		createCar();
	this->capacity = capCC;
	strcpy(this->name,carName);
	this->ID = carID;
}

void car_t::createCar()
{
	if(this->capacity == 0)
		this->capacity=new unsigned int;
	if(this->name == 0)
		this->name=new char[20];
	if(this->ID == 0)
		this->ID=new unsigned long;
}

void car_t::setGear(const char* carGear)
{
	this->gear = carGear;
}

const char* car_t::getGear()
{
	return this->gear;
}

bool operator==(const car_t& car)
{
	bool res;
	(car->capacity==this->capacity)?res = true:res = false;
	return res;
}