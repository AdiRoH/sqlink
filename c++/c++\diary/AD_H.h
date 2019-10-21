#ifndef AD_H
#define AD_H

	#include <map>
	#include "meetH.h"
	using namespace std;

	class AD_t
	{
	public:
		~AD_t(){clearAD();}

		AD_t(){}
		AD_t(const AD_t& ad);
		const AD_t& operator=(const AD_t& ad);
		bool insertMeet(const float& begin,const float& end,const string& subject);
		bool remove(const float& begin);
		Meet_t* findMeet(const float& begin) const;
		void clearAD();

	private:
		typedef map<float,Meet_t*> meetsType;
		meetsType m_meets;
		void insertInfoMeet(meetsType::iterator it,const float& begin,const float& end,const string& subject,Meet_t* meet);
	};

#endif