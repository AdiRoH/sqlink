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
				prepend(st2); /*how to use??*/
				break;
			}

			case 13://catenation operand
			{
				prepend(str2);
				break;
			}

			case 14:
			{
				
				break;
			}

			case 15://<
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

			case 16://>
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

			case 17://==
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

			case 18://!=
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

			case 19: //>=
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

			case 20: //<=
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

			

			case 21://find substring in string
			{
				contains(st2);//how to use?
			}

			case 22://subscript operator
			{
				size_t index;
				std::cout<<"insert index\n";
				std::cin>>index;
				char ch=str2[index];
				break;
			}

			case 23://is case sensitive?
			{
				bool state;
				state = caseFlagStat();
				if(state)?std::cout<<"true\n":std::cout<<"false\n";
				break;
			}

			case 24://set case sensitive and return the previous one
			{
				bool user_flag,prev_flag;
				std::cout<<"insert a flag of case sensitive\n";
				std::cin>>user_flag;
				prev_flag = setCaseFlag(user_flag);
				std::cout<<"previous flag was:  "<<user_flag;
				break;
			}

			case 25://capacity of object
			{
				size_t cap;
				cap = stateCap();
				std::cout<<"capacity is : "<<cap;
				break;
			}

			case 26://set capacity
			{
				size_t user_cap,prev_cap;;
				std::cout<<"insert a capacity\n";
				std::cin>>user_cap;
				prev_cap = setCap(user_cap);
				std::cout<<"previous capacity is : "<<prev_cap;
				break;
			}

			case 27:
			{
				size_t idx;
				char ch;
				std::cout<<"insert a char\n";
				std::cin>>ch;
				idx = firstIdxContains(ch);
				std::cout<<"the cahr is in index\n"<<idx;
				break;
			}
			case 28:
			{
				size_t idx;
				char ch;
				std::cout<<"insert a char\n";
				std::cin>>ch;
				idx = lastIdxContains(ch);
				std::cout<<"the cahr is in index\n"<<idx;
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
	std::cout<<"13: \tappend with char\n\n";
	std::cout<<"14: \tappend with string_t&\n\n";
	std::cout<<"15: \t<\n\n";
	std::cout<<"16: \t>\n\n";
	std::cout<<"17: \t==\n\n";
	std::cout<<"18: \t!=\n\n";
	std::cout<<"19: \t>=\n\n";
	std::cout<<"20: \t<=\n\n";
	std::cout<<"21: \tfind substring in string\n\n";
	std::cout<<"22: \tsubscript\n\n";
	std::cout<<"23: \tis case sensitive or not\n\n";
	std::cout<<"24: \tset case sensitive state, return previous state\n\n";
	std::cout<<"25: \tcapacity of objects\n\n";
	std::cout<<"26: \tcurrent capacity of objects+updating the capacity\n\n";
	std::cout<<"27: \tindex of first occurrence of some character in strings\n\n";
	std::cout<<"28: \tindex of last occurrence of some character in strings\n\n";
	std::cout<<"29: \treturn specific substring\n\n";
	std::cout<<"30: \tcount number of objects\n\n";


	std::cin>>*opt;
}

