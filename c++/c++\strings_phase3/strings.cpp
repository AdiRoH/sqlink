#include <string.h>
#include "stringsH.h"
#include <iostream>
#include <cstdio>
#include <cctype>
#include <math.h>

int string_t::numOfString_t=0;
size_t string_t::defCapacity=8;
bool caseSens=true;

string_t::string_t()
{
	createString(0,defCapacity);
}

string_t::string_t(const char* str)
{
	size_t cap;
	cap=calcCapacity(lenStr());
	createString((char*)str,cap);

}

string_t::~string_t()
{
	--numOfString_t;
	delete[] str1;
}


string_t& string_t::operator=(const string_t& str)
{
	if(this!=&str) 
	{
		delete[] str1;
		size_t cap;
		cap=calcCapacity(lenStr());
		createString(this->str1,cap);
	}
	return *this;
}

size_t string_t::lenStr()const
{
	return (size_t)lenStr();
}

size_t calcCapacity(size_t cap)
{
	double* rightCap;
	rightCap= new double;
	*rightCap = (2^(int)((log2((double)(cap))+1)));
	return (size_t)*rightCap;
}                             


void string_t::setString(const char* str)
{
	if(str)
	{
		delete[] str1;
		str1=(char*)str;
	}
}

const char* string_t::getString()const
{
	return (const char*)this->str1;
}

int string_t::cmprStr(const string_t& str)
{
	int res;
	if(caseSens==false)
	{
		res = strcasecmp(this->str1,str.str1);
	}

	else{
		res = strcmp(this->str1,str.str1);
	} 
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


void string_t::createString(char* str,size_t cap)
{
	if(str==0)
	{
		++numOfString_t;
		str1=new char[cap];
		str1[0]='\0';
	}
	else
	{
		size_t strLen=lenStr();
		str1=new char[cap+1];
		strcpy(str1,str);
	}
}


char* string_t::catStr(const char* first,const char* second)
{
	char* newStr;
	if(first==0) createString((char*)first,defCapacity);
	if(second==0) createString((char*)second,defCapacity);
	int totalLen=strlen(first)+strlen(second)+1;
	newStr = new char[totalLen];
	strcat(str1,first);
	strcat(str1,second);
	return newStr;
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
	int totalLen=strlen(this->str1)+strlen(str.str1)+1;
	tempStr=new char[strlen(this->str1)+1];
	strcpy(tempStr,str1);
	delete[] this->str1;
	this->str1 = new char[totalLen];
	this->str1=catStr(tempStr,str.str1);
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
	place = strstr(str,this->str1);
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

char string_t::operator[](size_t index)const
{
	int len=strlen(this->str1);
	return (index<len)?this->str1[index]:this->str1[len];
}


std::ostream& operator<<(std::ostream &out, const string_t& str)
{
	out<<str.getString();
	return out;
}

std::istream& operator>>(std::istream &in,  string_t& st)
{
	char tempStr[512];
	in>>tempStr;
	st.setString(tempStr);
	return in;
}

bool setCaseFlag(bool flag)
{
	bool prevFlag=caseSens;
	caseSens=flag;
	return prevFlag;
}

bool caseFlagStat()
{
	return caseSens;
}