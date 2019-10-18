#include "AD_H.h"
#include <map>

bool AD_t::insertMeet(float begin,float end,string subject)
{
	Meet_t* meet=new Meet_t;
	if(m_meets.size()==1)
	{
		if(m_meets.begin()->first!=begin) 
		{
			insertInfoMeet(begin,end,subject,meet);
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
				insertInfoMeet(begin,end,subject,meet);
				return true;
			}	
	    } 
	      
	}
	return false;
}

void AD_t::insertInfoMeet(float begin,float end,string subject,Meet_t* meet)
{
	if(!meet) return;
	meet->setBegin(begin);
	meet->setEnd(end);
	meet->setSubject(subject);
	this->m_meets.insert(make_pair(begin,meet));
}

bool AD_t::remove(float begin)
{
	if(findMeet(begin))
	{
		m_meets.erase(begin);
		return true; 
	}
	return false;
}

bool AD_t::findMeet(float begin)
{
	meetsType::iterator it;
	it=this->m_meets.find(begin);
	return(it==this->m_meets.end())?false:true;
}

void AD_t::clearAD()
{
	meetsType::iterator it;
	for(it=this->m_meets.begin();it!=this->m_meets.end();++it)
	{
		delete it->second;
		m_meets.erase(it);
	}
}