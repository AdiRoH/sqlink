#include "virtIO_H.h"
#include "asciiO_H.h"

#include <iostream>
using namespace std;

void printMenu();


int main()
{
	int opt;
	string mode,fileName;

	cout<<"insert name of file"<<endl;
	cin>>fileName;
	cout<<"insert mode"<<endl;
	cin>>mode;	
	asciiIO_t asc(fileName,mode);

	while(1)
	{
		printMenu();
		cin>>opt;
		switch(opt)
		{
			case 1:
			{
				cout<<"the path is: "<<endl;
				cout<<asc.getPath();
				break;
				break;
			}
			case 2:
			{
				cout<<"The access is: "<<endl;
				cout<<asc.getAccess();
				break;
			}
		}
	}
}

void printMenu()
{
	cout<<"choose an option"<<endl;
	cout<<"1:\tretrevie path"<<endl;
	cout<<"2:\tretrevie access"<<endl;
}