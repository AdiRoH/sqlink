
#ifndef stringsH
#define stringsH

	#include <iostream>
	#include <string.h>



	class string_t{
		public:
			
			~string_t();                                //DTOR

			string_t();                                 //default CTOR
			string_t(char* str);                        //CTOR from "const char*"
			string_t(const string_t& str);              //copy CTOR

			string_t& operator=(const string_t& str); 		//assignment operator

			int lenStr();                               //function 'length'
			void setString(const char* str);                  //function 'setString'
			void getString(char* str);                  //function 'getString'
			int cmprStr(const string_t& str);	       	//function compare            
			void printName(); 			   			 	//function print


			void convertUpper();
			void convertLower();

			void prepend(char* str);
			void prepend(const string_t& str);

			void operator+=(const string_t& str);
			void operator+=(char* str);

			bool operator<=(const string_t& str);//const
			bool operator>=(const string_t& str);
			bool operator==(const string_t& str);
			bool operator!=(const string_t& str);
			bool operator<(const string_t& str);
			bool operator>(const string_t& str);

			int contains(char *str);

			char& operator[](size_t index);//better way
			//char operator[](size_t index) const; how 2 implement?
			/*
			std::ostream& string_t::operator<<(std::ostream &out, string_t& str);
			std::istream& string_t::operator>>(std::istream &in);
			*/


	private:
		char *str1;
		void createString(char* str);
		char* catStr(const char* first,const char* second);

	};

#endif



//operators//consts
//only function outside the private can be const