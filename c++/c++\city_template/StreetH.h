#ifndef StreetH
#define StreetH

#include "BuildingH.h"
#include <vector>

	template <class idStreet,class idBuild>

	
	class Street_t
	{
		public:
			~Street_t();                                                                       //DTOR
			Street_t();                                                                        //def CTOR
			Street_t<idStreet,idBuild>& operator=(const Street_t& st);                         //assign operator
			Street_t(const Street_t& st);                                                      //copy CTOR
			void setID(idStreet idSt);                                                         //setID
			const idStreet& getID() const;                                                     //getID
			bool AddBuilding2Street(const Build_t<idBuild>& build);                            //Add building to street
			Build_t<idBuild>& getBuilding(unsigned int idx);                                  //get building from street

		private:
			idStreet m_id;
			std::vector<Build_t<idBuild> > v;
	};
		
	template <class idStreet,class idBuild>
	Street_t<idStreet,idBuild>::~Street_t(){}


	template <class idStreet,class idBuild>
	Street_t<idStreet,idBuild>::Street_t(){}


	template <class idStreet,class idBuild>
	Street_t<idStreet,idBuild>& Street_t<idStreet,idBuild>::operator=(const Street_t& st)
	{
		if(st.m_id!=m_id) 
			m_id=st.m_id;
		return *this;
	}


	template <class idStreet,class idBuild>
	Street_t<idStreet,idBuild>::Street_t(const Street_t& st)
	{
		m_id = st->m_id;
	}


	template <class idStreet,class idBuild>
	void Street_t<idStreet,idBuild>::setID(idStreet idSt)
	{
		m_id = idSt;
	}


	template <class idStreet,class idBuild>
	const idStreet& Street_t<idStreet,idBuild>::getID() const
	{
		return m_id;
	}


	template <class idStreet,class idBuild>
	bool Street_t<idStreet,idBuild>::AddBuilding2Street(const Build_t<idBuild>& build)
	{
		v.push_back(build);
		return true;
	}


	template <class idStreet,class idBuild>
	Build_t<idBuild>& Street_t<idStreet,idBuild>::getBuilding(unsigned int idx) 
	{
		if(idx<v.size()) return v[idx];
		else throw("idx>amount of buildings");
	}

#endif