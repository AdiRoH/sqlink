#include <string>
#include "meetH.h"
using namespace std;

bool Meet_t::setBegin(const float& begin)
{
	if(isValidHour(begin))
	{
		m_begin = begin;
		return true;
	}
	else return false;
}

bool Meet_t::setEnd(const float& end)
{
	if(isValidHour(end))
	{
		m_end = end;
		return true;
	}
	else return false;
}

/*
Meet_t& Meet_t::operator=(const Meet_t& meet)
{
	this->m_begin = meet.getBegin();
	this->m_end = meet.getEnd();
	this->m_subject = meet.getSubject();
	return *this;
}

Meet_t::Meet_t(const Meet_t& meet)
{
	this->m_begin = meet.getBegin();
	this->m_end = meet.getEnd();
	this->m_subject = meet.getSubject();
}
*/