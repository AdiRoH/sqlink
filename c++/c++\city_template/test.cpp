#include "BuildingH.h"
#include "StreetH.h"
#include "cityH.h"
#include <iostream>
#include <stdlib.h>

void printMainMenu(int* opt);
void printMenu_Build(int* opt);
void printMenu_Street(int* opt);
void printMenu_City(int* opt);

int main()
{
	int opt=1,buildOpt=1,streetOpt=1,cityOpt=1,idNumSet,idNumGet,idNumStreet,idNumStreet2,buildingNum,idNumCity,idNumCity2,ctNum,IDbuild;
	unsigned int idx,idxCT;
	Build_t<int> bd;
	Build_t<int> bd2;
	Street_t<int,int> st1,st2;
	City_t<int,int,int> ct1,ct2;

	while(opt>0)
	{
		printMainMenu(&opt);
		switch(opt)
		{
			case 1:
				{
					printMenu_Build(&buildOpt);
					switch(buildOpt)
					{
						case 1:
						{
							std::cout<<"set a new ID number to a building\n";
							std::cin>>idNumSet;
							bd.setID(idNumSet);
							std::cout<<"the id is: "<<bd.getID();
							break;
						}

						case 2:
						{
							std::cout<<"insert a new ID number\n";
							bd2=bd;
							std::cout<<"the id is: "<<bd2.getID()<<"\n";
							break;
						}

						case 3:
						{
							idNumGet=bd2.getID();
							std::cout<<"the id number is: "<<idNumGet<<"\n";
							break;
						}
					}
					break;
				}
			case 2:
				{
					printMenu_Street(&streetOpt);
					switch(streetOpt)
					{
						case 1:
							{
								std::cout<<"set a new ID number to a street\n";
								std::cin>>idNumStreet;
								st1.setID(idNumStreet);
								std::cout<<"the id is: "<<st1.getID()<<"\n";
								break;
							}

						case 2:
							{
								st2=st1;
								std::cout<<"the id is: "<<st2.getID()<<"\n";
								break;	
							}

						case 3:
							{
								idNumStreet2 = st1.getID();
								std::cout<<"The id number is: "<<idNumStreet2<<"\n";
								break;
							}
						case 4:
							{
								std::cout<<"insert a building number\n";
								std::cin>>buildingNum;
								bd.setID(buildingNum);
								/*st1.AddBuilding2Street(buildingNum);*/
								break;
							}	
						case 5:
							{
								
								std::cout<<"insert index\n";
								std::cin>>idx;
								/*st2.getBuilding(idx)*/;
								std::cout<<"the id is: "<<st2.getID()<<"\n";
								break;
							}
					}
					break;
				}
			case 3:
				{
					printMenu_City(&cityOpt);
					switch(cityOpt)
					{
						case 1:
							{
								std::cout<<"set a new ID number to a city\n";
								std::cin>>idNumCity;
								ct1.setCityID(idNumCity);
								std::cout<<"the id is: "<<ct1.getCityID()<<"\n";
								break;
							}

						case 2:
							{
								ct2=ct1;
								std::cout<<"the id is: "<<ct2.getCityID()<<"\n";
								break;	
							}

						case 3:
							{
								idNumCity2 = ct1.getCityID();
								std::cout<<"The id number is: "<<idNumCity2<<"\n";
								break;
							}

						case 4:
							{
								std::cout<<"insert a city number\n";
								std::cin>>ctNum;
								bd.setID(ctNum);
								/*bd.AddStreet(bd);*/
								break;
							}
						case 5:
							{
								std::cout<<"insert index\n";
								std::cin>>idxCT;
								/*IDbuild = st2.getBuilding(idxCT);*/
								/*std::cout<<"the id is: "<<IDbuild;*///not compiling
								/*std::cout<<<int,int>st2.getBuilding(idxCT);*/
								ct2.getStreet(idxCT) /*const*/; //wht not with const?
								break;
							}
					}

					break;
				}
		}
	}
}

void printMainMenu(int* opt)
{
	std::cout<<"choose option\n\n";
	std::cout<<"1:\tbuilding\n\n";
	std::cout<<"2:\tstreet\n\n";
	std::cout<<"3:\tcity\n\n";
	std::cin>>*opt;
}

void printMenu_Build(int* opt)
{
	std::cout<<"1:\tset id of building\n\n";
	std::cout<<"2:\tassign\n\n";
	std::cout<<"3:\tget id of building\n\n";
	std::cin>>*opt;
}

void printMenu_Street(int* opt)
{
	std::cout<<"1:\tset id of a building\n\n";
	std::cout<<"2:\tassign\n\n";
	std::cout<<"3:\tget id of street\n\n";
	std::cout<<"4:\tadd a building id to street\n\n";
	std::cout<<"5:\tget a building id\n\n";
	std::cin>>*opt;
}

void printMenu_City(int* opt)
{
	std::cout<<"1:\tset id of a city\n\n";
	std::cout<<"2:\tassign\n\n";
	std::cout<<"3:\tget id of city\n\n";
	std::cout<<"4:\tadd a street id to city\n\n";
	std::cout<<"5:\tget a street id\n\n";
	std::cin>>*opt;
}