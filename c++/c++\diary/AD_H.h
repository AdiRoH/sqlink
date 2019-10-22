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
		bool insertMeet(const float& begin,const float& end,const string& subject);
		bool remove(const float& begin);
		Meet_t* findMeet(const float& begin) const;
		void clearAD();
		//transfer copy CTOR ans = operator to private;
	private:
		//typedef map<float,Meet_t*> meetsType;
		//meetsType m_meets;
		 map<float,Meet_t*> m_meets
		typedef typename meetsType::iterator it;//added later
		void insertInfoMeet(meetsType::iterator it,const float& begin,const float& end,const string& subject,Meet_t* meet);
		AD_t(const AD_t& ad){};
		AD_t& operator=(const AD_t& ad){};
		//= doesn't return const
	};

//when returning data member by reference, we need return it by const
//here, Meet_t doesn't a data-member!
#endif