#include "class_stringH.h"
using namespace std;

int main()
{
	const char* str="Abc";
	int len;
	string_t st(str);
	st.printName(str);
	len=st.lenStr();
	st.~string_t();


	return 0;
}

//makeFile
//when new for char, does it includes '\0'?
