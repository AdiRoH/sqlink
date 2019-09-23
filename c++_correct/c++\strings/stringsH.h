#ifndef stringsH
#define stringsH

	#include <iostream>
	#include <string.h>



	class string_t{
		public:

			~string_t();                                      //DTOR

			string_t();                                       //default CTOR
			string_t(char* str);                              //CTOR from "const char*"
			string_t(const string_t& st);                     //copy CTOR

			string_t& operator=(string_t& str);
        //assignment oerator

			int lenStr();                                     //function 'length'
			void setString(const char* str);                  //function 'setString'
			void getString(const char* str);                  //function 'getString'
			int cmprStr(const string_t& str);	        	  //function compare            
			void printName(const char* str); 				  //function print

		private:
			char *str1;
			void createString(char* str);
	};

#endif



