#include "AD_H.h"
#include <map>

bool AD_t::insertMeet(float begin,float end,string subject)
{
	Meet_t* meet=new Meet_t;
	if(m_meets.size()==1)
	{
		if(m_meets.begin()->first!=begin) 
		{
			insertInfoMeet(begin,end,subject,*meet);
			this->m_meets.erase(this->m_meets.begin());
			return true;	
		}
	}

	else
	{
		meetsType::iterator it = m_meets.begin();
	    for (it = m_meets.begin(); it!=(m_meets.end()); ++it) 
	    {
	     	if(it->second->getEnd()<begin && end<(++it)->first)
			{
				insertInfoMeet(begin,end,subject,*meet);
				return true;

			}
	     	
	    } 
	      
	}
	return false;
}

void AD_t::insertInfoMeet(float begin,float end,string subject,const Meet_t& meet)
{
	meet.setBegin(begin);
	meet.setEnd(end);
	meet.setSubject(subject);
	this->m_meets.insert(make_pair(begin,meet));
}

bool AD_t::remove(float begin)
{
	meetsType::iterator it;
	it=m_meets.find(begin);
	if(it!=m_meets.end())
	{
		m_meets.erase(it);
		return true; 
	}
	return false;
}