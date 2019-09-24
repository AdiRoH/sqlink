#include <string.h>
#include "stringsH.h"
#include <cstdio>

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


string_t& string_t::operator=(string_t& str)
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

void string_t::getString(const char* str)
{
	if(str) str=str1;
}

int string_t::cmprStr(const string_t& str)
{
	return strcmp(str1,str.str1);
}

void string_t::printName(const char* str)
{
	if(str) printf("%s",str);
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


void string_t::prepend1(char* str)
{
	this+=str;
}

void string_t::prepend2(char* string_t& str1)
{
	this+=;
}

string_t& string_t::operator+=(string_t &str)
{
	srcat(str.str1,str1);
	return *this;	
}

bool operator<=(char* str)
{
	int res;
	res=strcmp(str,str1);
	if(res==0||res<0)
		true;
	else return false;
}

bool operator>=(char* str)
{
	int res;
	res=strcmp(str,str1);
	if(res==0||res>0)
		true;
	else return false;
}

bool operator==(char* str)
{
	int res;
	res=strcmp(str,str1);
	if(res==0)
		true;
	else return false;
}

bool operator!=(char* str)
{
	int res;
	res=strcmp(str,str1);
	if(res>0||res<0)
		true;
	else return false;
}

bool operator>(char* str)
{
	int res;
	res=strcmp(str,str1);
	if(res>0)
		true;
	else return false;
}

bool operator<(char* str)
{
	int res;
	res=strcmp(str,str1);
	if(res<0)
		true;
	else return false;
}


void operator+=(char* str)
{
	strcat(str,str1);
	str1+=str;
}

int contains(char *str)
{
	char* place;
	place = strstr(str1,str);
	if(place==NULL) return 0;
	else return 1;
}