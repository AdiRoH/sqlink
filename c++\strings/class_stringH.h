#include <iostream>
#include <string.h>



class string_t{
	public:
		string_t();
		string_t(const char* str);
		//string_t(const string_t& st);
		~string_t();
		string_t& operator=(const string_t& str);
		int lenStr();
		void setString(const char* str);
		void getString(const char* str);
		int cmprStr(const char* str);
		void printName(const char* str); 

	private:
		char *str1;
};





