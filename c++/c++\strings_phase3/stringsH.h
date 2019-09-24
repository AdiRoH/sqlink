
#ifndef stringsH
#define stringsH

	#include <iostream>
	#include <string.h>



	class string_t{
		public:
			
			~string_t();                                //DTOR

			string_t();                                 //default CTOR
			string_t(const char* str);                        //CTOR from "const char*"
			string_t(const string_t& str);              //copy CTOR

			string_t& operator=(const string_t& str); 		//assignment operator

			inline size_t lenStr()const;                               //function 'length'
			inline void setString(const char* str);                  //function 'setString'
			inline const char* getString()const;                  //function 'getString'
			int cmprStr(const string_t& str);	       	//function compare            
			inline void printName(); 			   			 	//function print


			inline void convertUpper();
			inline void convertLower();

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
			char operator[](size_t index) const;/* how 2 implement?*/
			

			


	private:
			char *str1;
			void createString(char* str,size_t cap);
			char* catStr(const char* first,const char* second);

			static int numOfString_t;
			static size_t defCapacity;
			static bool caseSens;

			size_t calcCapacity(size_t cap);
			size_t capacity;

			static bool setCaseFlag(bool flag);
	};
	std::ostream& operator<<(std::ostream &out, const string_t& str);
	std::istream& operator>>(std::istream &in, string_t& st);

	
	
#endif



//operators//consts
//only function outside the private can be const