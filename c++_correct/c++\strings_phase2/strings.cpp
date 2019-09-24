#include <string.h>
#include "stringsH.h"
#include <iostream>
#include <cstdio>
#include <cctype>

string_t::string_t()
{
	createString(0);
}

string_t::string_t(char* str)
{
	createString(str);

}

string_t::~string_t()
{
	delete[] str1;
}


string_t& string_t::operator=(const string_t& str)
{
	if(this!=&str) 
	{
		delete[] str1;
		createString(str.str1);
	}
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

void string_t::getString(char* str)/*const char *string_t::getString() const*/
{
	if(str) str=str1;
}

int string_t::cmprStr(const string_t& str)
{
	int res = strcmp(this->str1,str.str1);
	if(res<0) return 1;
	else if(res>0) return 2;
	else return 0;
	/*res==?0
	:res>0?1
	:2*/
}

void string_t::printName()
{
	printf("%s",str1);
}


void string_t::createString(char* str)
{
	if(str==0)
	{
		str1=new char[16];
		str1[0]='\0';
	}
	else
	{
		int strLen=strlen(str);
		str1=new char[strLen+1];
		strcpy(str1,str);
	}
}

char* catStr(const char* first,const char* second)
{
	char* newStr;
	if(first==0) createString(first);
	if(second==0) createString(second);
	int len1=strlen(first);
	int len2=strlen(second);
	int totalLen=len1+len2+1;
	newStr = new char[totalLen];
	strcat(str1,first);
	strcat(str1,second);
}

void string_t::operator+=(char* str)
{
	char* tempStr;
	int totalLen=strlen(this->str1)+strlen(str)+1;
	tempStr = new char[strlen(this->str1)+1];
	strcpy(tempStr,str1);
	delete[] this->str1;
	this->str1 = new char[totalLen];
	this->str1=catStr(tempStr,str);
}

void string_t::operator+=(const string_t& str)
{
	char* tempStr;
	int totalLen=strlen(this->str1)+strlen(str)+1;
	tempStr=new char[strlen(this->str1)+1];
	strcpy(tempStr,str1);
	delete[] this->str1;
	this->str1 = new char[totalLen];
	this->str1=catStr(tempStr,str);
}


void string_t::prepend(char* str)
{
	operator+=(str);
}

void string_t::prepend(const string_t& str)
{
	operator+=(str.str1);
}



bool string_t::operator<=(const string_t& str)
{
	int res;
	bool retVal;
	res = cmprStr(str);
	if(res==0||res<0)
		retVal = true;
	else retVal = false;

	return retVal;
}

bool string_t::operator>=(const string_t& str)
{
	int res;
	bool retVal;
	res = cmprStr(str);
	if(res==0||res>0)
		retVal = true;
	else retVal = false;
	return retVal;
}

bool string_t::operator==(const string_t& str)
{
	int res;
	bool retVal;
	res = cmprStr(str);
	if(res==0)
		retVal = true;
	else retVal = false;
	return retVal;
}

bool string_t::operator!=(const string_t& str)
{
	int res;
	bool retVal;
	res = cmprStr(str);
	if(res>0||res<0)
		retVal = true;
	retVal = false;
	return retVal;
	}

bool string_t::operator>(const string_t& str)
{
	int res;
	bool retVal;
	res = cmprStr(str);
	if(res>0)
		retVal=true;
	else retVal = false;
	return retVal;
}

bool string_t::operator<(const string_t& str)
{
	int res;
	bool retVal;
	res = cmprStr(str);
	if(res<0)
		retVal = true;
	else retVal = false;
	return retVal;
}

int string_t::contains(char *str)
{
	char* place;
	res = cmprStr(str);
	if(place==NULL) return 0;
	else return 1;
}

void string_t::convertUpper()
{
	int i=0;
	for(i=0;i<=strlen(this->str1);i++)
	{
		this->str1[i]=toupper(this->str1[i]);
	}
		
}

void string_t::convertLower()
{
	int i=0;
	for(i=0;i<=strlen(this->str1);i++)
	{
		this->str1[i]=tolower(str1[i]);
	}
}

char& string_t::operator[](size_t index)
{
	int len=strlen(this->str1);
	//because index is size_t, its can't be negative!
	return (index<len)?this->str1[index]:this->str1[len];

}

char string_t::operator[](size_t index) const
{
	int len=strlen(this->str1);
	return (index<len)?this->str1[index]:this->str1[len];
}

/*
std::ostream& string_t::operator<<(std::ostream &out, string_t& str)
{
	out<<str_t.str1;
	return out;
}

std::istream& string_t::operator>>(std::istream &in)
{
	char tempStr[1024];
	cin>>tempStr;
	setString(tempStr);
	return in;
}
*/