#include <string>
#include <iostream>
#include "meetH.h"
#include "AD_H.h"

using namespace std;

void printMenu();

int main()
{
	int opt;
	float begin,end;
	Meet_t* meetP;
	string subject;
	AD_t AD;

	while(1)
	{
		printMenu();
		cin>>opt;

		switch(opt)
		{
			case 1:
			{
				cout<<"insert a begin hour!\n";
				cin>>begin;
				cout<<"insert end hour\n";
				cin>>end;
				cout<<"insert a subject of meeting\n";
				cin>>subject;
				if(AD.insertMeet(begin,end,subject)==false)
					cout<<"Error! meeting wasn't insert\n";
				break;
			}
			case 2:
			{
				cout<<"insert begin time to find appointment";
				cin>>begin;
				meetP = AD.findMeet(begin);
				if(meetP==0) cout<<"meeting wasn't found\n";
				else
				{
					cout<<"begin hour: "<<meetP->getBegin()<<endl;
					cout<<"end hour: "<<meetP->getEnd()<<endl;
					cout<<"subject hour: "<<meetP->getSubject()<<endl;
				}
				break;
			}
			case 3:
			{
				cout<<"insert begin time to remove the apointment\n";
				cin>>begin;
				(AD.remove(begin))?cout<<("meet was remove\n"):cout<<("meet wasn't remove\n");
				break;
			}
			case 4:
			{
				AD.clearAD();
				cout<<"AD was erase\n";
				break;
			}
			default:
			break;
		}
	}
	return 1;
}


void printMenu()
{
	cout<<"Choose option\n";
	cout<<"1:\tinsert appointment"<<endl;
	cout<<"2:\tfind appointment"<<endl;
	cout<<"3:\tremove apointment"<<endl;
	cout<<"4:\tclear AD"<<endl;
}