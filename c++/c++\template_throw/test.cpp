#include "ThrowH.h"

void func();

int main()
{
	try
	{
    	func();

	}catch(TException_t<float> Texc){

       	std::cout<<"the object is: "<<Texc.getVarThrow()<<"\n";
      	std::cout<<"from file: "<<Texc.getFileName()<<"\n";
        std::cout<<"from line: "<<Texc.getLineNum()<<"\n";
        std::cout<<"the message: "<<Texc.getMessage()<<"\n";
   
    }
  
}

void func(){
	string str = __FILE__;
	float i=5.5;
    
    throw TException_t<float> ("float was thrown",__FILE__,__LINE__,i);
}