#ifndef AD_H
#define AD_H

	#include <map>
	#include "meetH.h"
	using namespace std;

	class AD_t
	{
	public:
		AD_t()
		{
			Meet_t* meet = new Meet_t;
			m_meets.insert(make_pair(NULL,meet)); 
		}

		~AD_t(){m_meets.clear();}
		bool insertMeet(float begin,float end,string subject);
		bool
		 remove(float begin)
		{
			meetsType::iterator it;
			it=m_meets.find(begin);
			if(it!=m_meets.end())
			{
				m_meets.erase (it)
				return true; 
			}
			return false;
		}

	private:
		typedef map<float,Meet_t*> meetsType;
		meetsType m_meets;
		void insertInfoMeet(float begin,float end,string subject,const Meet_t& meet);
	};

#endif