#include <iostream>
#include <string.h>
#include "class_stringH.h"
#include <cstdio>

string_t::string_t()
{
	str1=new char[5];
	strcpy(str1,"Aadi");
}

string_t::string_t(const char* str)
{
	int strLen = strlen(str);
	str1 = new char[strLen+1];
	strcpy(str1,str);
}

string_t::~string_t()
{
	delete[] str1;
}


string_t& string_t::operator=(const string_t& str)
{
	int strLen = strlen(str.str1);
	if(this!=&str) 
		delete[] str1;
		str1=new char[strLen+1];
		strcpy(str1,str.str1);
	return *this;
}


int string_t::lenStr()
{
	return strlen(str1);
}

void string_t::setString(const char* str)
{
	if(str)
	{
		delete[] str1;
		str1=(char*)str;
	}
}

void string_t::getString(const char* str)
{
	if(str) str=str1;
}

int string_t::cmprStr(const char* str)
{
	if(str) 
		return strcmp(str1,str);
}

void string_t::printName(const char* str)
{
	if(str1) printf("%s",str);
}



