#include "AD_H.h"
#include <map>

bool AD_t::insertMeet(const float& begin,const float& end,const string& subject)
{
	Meet_t* meet=new Meet_t;
	meetsType::iterator it = m_meets.begin();
	Meet_t* m=findMeet(begin);
	if(m!=NULL||end<=begin) return false;
	if(m_meets.empty()) 
	{
		insertInfoMeet(it,begin,end,subject,meet);
		return true;	
	}
	if(m_meets.size()==1)
	{
		if(m_meets.begin()->first<begin) 
		{
			insertInfoMeet((++it),begin,end,subject,meet);
			return true;	
		}
		else
		{
			insertInfoMeet(it,begin,end,subject,meet);
			return true;
		}
	}

	else
	{
	    for (it = m_meets.begin(); it!=(m_meets.end()); ++it) 
	    {
	     	if(it->second->getEnd()<begin && end<(++it)->first)
			{
				insertInfoMeet(it,begin,end,subject,meet);
				return true;
			}	
	    } 
	      
	}
	return false;
}

AD_t::AD_t(const AD_t& ad)
{
	meetsType::const_iterator it;
	for(it=ad.m_meets.begin();it!=ad.m_meets.end();it++)
	{
		Meet_t* newMeet = new Meet_t(*(it->second));
		this->m_meets.insert(make_pair(newMeet->getBegin(),newMeet));
	}
}

const AD_t& AD_t::operator=(const AD_t& ad)
{
	if(&ad==this) return *this;
	meetsType::const_iterator it;
	for(it=ad.m_meets.begin();it!=ad.m_meets.end();it++)
	{
		Meet_t* newMeet = new Meet_t(*(it->second));
		this->m_meets.insert(make_pair(newMeet->getBegin(),newMeet));
	}
	return *this;
}

void AD_t::insertInfoMeet(meetsType::iterator it,const float& begin,const float& end,const string& subject,Meet_t* meet)
{
	if(!meet) return;
	meet->setBegin(begin);
	meet->setEnd(end);
	meet->setSubject(subject);
	this->m_meets.insert(it,make_pair(begin,meet));
}

bool AD_t::remove(const float& begin)
{
	if(findMeet(begin))
	{
		m_meets.erase(begin);
		return true; 
	}
	return false;
}

Meet_t* AD_t::findMeet(const float& begin) const
{
	if(m_meets.empty()) return NULL;
	else if(m_meets.size()==1) return (this->m_meets.begin()->second);
	meetsType::const_iterator it;
	it=this->m_meets.find(begin);
	return(it==this->m_meets.end())?NULL:(it->second);
}

void AD_t::clearAD()//should I use .clear()?
{
	meetsType::iterator it;
	if(!m_meets.empty())
	{
		for(it=this->m_meets.begin();it!=this->m_meets.end();++it)
		{
			delete it->second;
			//m_meets.erase(it);
		}
	}	
}