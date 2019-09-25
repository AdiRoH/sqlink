
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

			int contains(const char *str,char* Place);

			char& operator[](size_t index);//better way
			char operator[](size_t index) const;/* how 2 implement?*/
			
			size_t firstIdxContains(const char ch);
			size_t lastIdxContains(const char ch);

			


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
			static bool caseFlagStat();
			static size_t setCap(size_t user_cap);
			static size_t stateCap();

	};
	std::ostream& operator<<(std::ostream &out, const string_t& str);
	std::istream& operator>>(std::istream &in, string_t& st);

	inline size_t string_t::lenStr()const
	{
		return (size_t)strlen(str1);
	}

	inline void string_t::convertUpper()
	{
		int i=0;
		for(i=0;i<=strlen(str1);i++)
		{
			str1[i]=toupper(str1[i]);
		}
			
	}

	inline void string_t::convertLower()
	{
		int i=0;
		for(i=0;i<=strlen(str1);i++)
		{
			str1[i]=tolower(str1[i]);
		}
	}

	inline void string_t::printName()
	{
		std::cout<<str1;
	}

#endif



//operators//consts
//only function outside the private can be const