#include "virtIO_H.h"
#include "asciiO_H.h"
#include "binIOH.h"

#include <iostream>
using namespace std;

void printMenu();
void menuBin();
void menuAsc();
//==========================================================================================
int main()
{
	int optB,optA;
	char kindFile,mode[2];
	string fileName;
	virtIO_t *asc,*bin;



	while(1)
	{
		printMenu();
		cin>>kindFile;	
		if(kindFile=='b')
		{
			menuBin();
			cin>>optB;
			switch(optB)
			{
				case 1:
				{	
					cout<<"insert name of file"<<endl;
					cin>>fileName;
					cout<<"insert mode"<<endl;
					cin>>mode;	
					bin = new binIO_t(fileName,mode);
					break;
				}
				case 2:
				{
					cout<<"the path is: "<<endl;
					cout<<bin->getPath();
					break;
				}
				case 3:
				{
					cout<<"The access is: "<<endl;
					cout<<bin->getAccess();
					break;
				}
			}
		}

		else if(kindFile=='a')
		{
			menuAsc();
			cin>>optA;
			switch(optA)
			{
				case 1:
				{
					cout<<"the path is: "<<endl;
					cout<<asc->getPath();
					break;
				}

				case 2:
				{
					cout<<"The access is: "<<endl;
					cout<<asc->getAccess();
					break;
				}
			}
		}

		else break;
	}
}

//=============================================================================================
void printMenu()
{
	cout<<"choose binary/assci file[b/a]"<<endl;
}
//=============================================================================================
void menuAsc()
{
	cout<<"choose an option"<<endl;
	cout<<"1:\tinsert file and mode"<<endl;
	cout<<"2:\tretrevie path"<<endl;
	cout<<"3:\tretrevie access"<<endl;
}
//=============================================================================================
void menuBin()
{
	cout<<"choose an option"<<endl;
	cout<<"1:\tinsert file and mode"<<endl;
	cout<<"2:\tretrevie path"<<endl;
	cout<<"3:\tretrevie access"<<endl;
}

