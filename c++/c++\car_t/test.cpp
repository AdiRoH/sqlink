#include "car_t_H.h"
#include "busH.h"
#include "privateH.h"

#include <iostream>

int main()
{
	bus_t bus1(1500,"bus",1,Auto);
	bus_t bus2;
	bus2=bus1;
	bus1.accelarate();
	bus1.reduceSpeed();
	std::cout<<"type of car"<<bus1.getName()<<"\n"; 
	std::cout<<(bus1<bus2)<<"\n";

	Private_t pt(1500,"private",2,manual);
	Private_t pt1;
	pt1=pt;
	
	pt.setLineNum(15);
	pt.setSeatNum(30);
	std::cout<<pt.getSeatNum()<<"\n";
	std::cout<<pt.getLineNum()<<"\n";
	
	return 1;

}