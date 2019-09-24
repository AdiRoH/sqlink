#include "stringsH.h"
#include <iostream>

void printMenu(int* opt);

int main()
{
	int opt;
	char *str1,*strAppend,*str2;
	size_t length1,length2;
	std::cout<<"insert a length of a string\n";
	std::cin>>length1;
	str1=new char[length1+1];
	std::cout<<"insert a string\n";
	std::cin>>str1;
	string_t st1(str1);
	std::cout<<"insert a length of a string\n";
	std::cin>>length2;
	str2=new char[length2+1];
	std::cout<<"insert a string\n";
	std::cin>>str2;
	string_t st2(str2);

	while(1)
	{
		printMenu(&opt);
		if(opt<0)
			break;
		switch(opt)
		{
			case 9://convert to upper case
			{	
				st1.convertLower();
				st1.printName();
				std::cout<<"\n";
				break;
			}

			case 10://convert to lower case
			{
				st1.convertUpper();
				st1.printName();
				std::cout<<"\n";
				break;
			}

			case 11://prepand with char*
			{
				size_t lenAppend;
				char* strAppend;
				std::cout<<"insert length of str\n";
				std::cin>>lenAppend;
				strAppend=new char[lenAppend+1];
				std::cout<<"insert a string\n";
				std::cin>>strAppend;
				st1.prepend(strAppend);
				st1.printName();
				break;
			}

			case 12://prepand with string_t&
			{
				/*prepend(st2.str1); how 2 call the function*/
				break;
			}

			case 13://catenation operand
			{
				break;
			}

			case 14://<
			{
				if(st1<st2)
				{
					std::cout<<"str1<str2\n";
				}
				else
				{
					std::cout<<"str1>str2\n";
				}
				break;
			}

			case 15://>
			{
				if(st1>st2)
				{
					std::cout<<"str1>str2\n";
				}
				else{
					std::cout<<"str2>str1\n";
				}
				break;
			}

			case 16://==
			{
				if(st1==st2)
				{
					std::cout<<"the strings are equal\n";
				}
				else
				{
					std::cout<<"the strings areen't equal\n";
				}
				break;
			}

			case 17://!=
			{
				if(st1!=st2)
				{
					std::cout<<"the strings are diffrent\n";
				}
				else
				{
					std::cout<<"the strings are equal\n";
				}
				break;
			}

			case 18: //>=
			{
				if(st1>=st2)
				{
					std::cout<<"str1<=str2\n";
				}
				else{
					std::cout<<"str1<str2\n";
				}
				break;
			}

			case 19: //<=
			{
				if(st1<=st2)
				{
					std::cout<<"str1<=str2\n";
				}
				else
				{
					std::cout<<"str1>str2\n";
				}
				break;
			}

			case 20:
			{
				contains(str2);
				break;
			}

			case 21:
			{
				size_t index;
				std::cout<<"insert index\n";
				std::cin>>index;
				char ch=[](index);
				break;
			}

			case 22:
			{
				break;
			}

			case 23:
			{
				break;
			}
		}
		
	}
	

	return 0;
}

void printMenu(int* opt)
{
	std::cout<<"Insert an option:\n\n";
	std::cout<<"9: \tconvert string to lower case\n\n";
	std::cout<<"10: \tconvert string to upper case\n\n";
	std::cout<<"11: \tprepand with char*\n\n";
	std::cout<<"12: \tprepand with &\n\n";
	std::cout<<"13: \tcatenation operator\n\n";
	std::cout<<"14: \t<\n\n";
	std::cout<<"15: \t>\n\n";
	std::cout<<"16: \t==\n\n";
	std::cout<<"17: \t!=\n\n";
	std::cout<<"18: \t>=\n\n";
	std::cout<<"19: \t<=\n\n";
	std::cout<<"20: \tfind substring in string\n\n";
	std::cout<<"21: \tsubscript\n\n";
	std::cout<<"22: \t<<\n\n";
	std::cout<<"23: \t>>\n\n";

	std::cin>>*opt;
}

