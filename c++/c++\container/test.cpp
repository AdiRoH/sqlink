#include "containerH.h"
#include <iostream>
#include <vector>
#include <list>

using namespace std;
int main()
{
	int i=0,j=0;
	tContainer_t <char,vector<char*> > str;
	tContainer_t <float,list<float*> > lst;
	char el[]="Adi";
	float f1=3.14;
	float* fPtr;
	fPtr = &f1; 
	

	cout<<"Does string Empty?"<<str.isEmpty()<<"\n";
	str = new char[6];
	for(i=0;i<6;i++)
	{
		str.insertElemEnd(el);
	}
	cout<<"The vector contains "<<str.numOfElement()<<"\n";


	cout<<"Does list Empty?"<<lst.isEmpty()<<"\n";	
	lst = new list[5];
/*
	for(i=0;i<5;i++)
	{
		lst.insertElemEnd(el);
	}
	cout<<"The list contains "<<lst.numOfElement()<<"\n";


	return 1;
}
*/