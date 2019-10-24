#include "virtIO_H.h"
#include "asciiO_H.h"
#include "binIOH.h"

#include <iostream>
using namespace std;

void printMenu();
void menu();

//==========================================================================================

int main()
{
	char opt,kindFile;
	char* mode=new char[2];
	string fileName;
	virtIO_t *file=0;
	long pose;

	printMenu();
	cin>>kindFile;	
	cout<<"insert name of file"<<endl<<"insert mode"<<endl;//
	cin>>fileName>>mode;

	if(kindFile=='b')
		file=new binIO_t(fileName,mode);
	else if(kindFile=='a')
		file=new asciiIO_t(fileName,mode);
	

	while(1)
	{ 
		
		

		
		menu();
		cin>>opt;
		switch(opt)
		{
			case 'r':
			{	
				int i;
				int &refI=i;
				float f;
				
				file->open();
				virtIO_t& vi = file->operator>>(refI);  
				file->close();
				break;
			}

			case 'w':
			{
				int i=5;
				file->open();
				//<< i  << ' ' << f; 
				virtIO_t& vi = file->operator<<(i);//<file->operator<<(' ')<<file->operator;
				file->close();
				break;
			}

			case 'R':
			{
				int i;
				binIO_t* bPtr=dynamic_cast<binIO_t*>(file);
				if(bPtr!=0)
				{
					bPtr->open();
					bPtr->operator<<((void*)&i),sizeof(int);
					bPtr->close();
				}
				break;
			}

			case 'W':
			{
				int i;
				cout<<"insert a number"<<endl;
				binIO_t* bPtr=dynamic_cast<binIO_t*>(file);
				if(bPtr!=0)
				{
					bPtr->open();
					bPtr->operator>>((void*)&i),sizeof(int);
					bPtr->close();
				}
				break;
			}

			case 'g':
			{
				cout<<"The position is: "<<endl;
				cout<<file->getPose()<<endl;
				break;
			}
			case 's':
			{
				cout<<"insert a position"<<endl;
				cin>>pose;
				file->setPose(pose);
				break;
			}

			case 'p':
			{
				cout<<"The path is: "<<endl;
				cout<<file->getPath()<<endl;
				break;
			}

			case 'a':
			{
				cout<<"The mode is: "<<endl;
				cout<<file->getAccess()<<endl;
				break;
			}

			case 'l':
			{
				cout<<"The length is: "<<endl;
				cout<<file->lengthOfFile()<<endl;
				break;
			}
			case 'b':
			{
				continue;
			}
		
		}

		
	}
}

//=============================================================================================
void printMenu()
{
	cout<<"choose binary/assci file[b/a]"<<endl;
}
//=============================================================================================
void menu()
{
	cout<<"choose an option"<<endl;
	cout << "read(r) || write(w) || readBin(R) || writeBin(W) || get pos(g) || set pos(s) || get access(a) || get Path(p) || get length(l) || back(b)? " << endl;

}

