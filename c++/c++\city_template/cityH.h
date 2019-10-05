#ifndef cityH
#define cityH

#include <vector>

	template <class idCity,class idStreet,class idBuild>

	class City_t
	{
		public:
			~City_t();
			City_t();
			City_t(const City_t& ct);
			City_t<idCity,idStreet,idBuild>& operator=(const City_t<idCity,idStreet,idBuild>& ct);

			void setCityID(idCity ct);
			const idCity& getCityID()const;
			bool AddStreet(const Street_t<idStreet,idBuild>& st);
			const Street_t<idStreet,idBuild>& getStreet(unsigned int idx) const;

		private:
			idCity m_id;
			std::vector<Street_t<idStreet,idBuild> > v;
			  
	};

	template <class idCity,class idStreet,class idBuild>
	City_t<idCity,idStreet,idBuild>::~City_t(){}

	template <class idCity,class idStreet,class idBuild>
	City_t<idCity,idStreet,idBuild>::City_t(){}

	template <class idCity,class idStreet,class idBuild>
	City_t<idCity,idStreet,idBuild>::City_t(const City_t& ct)
	{
		m_id = ct->m_id;
	}

	template <class idCity,class idStreet,class idBuild>
	City_t<idCity,idStreet,idBuild>& City_t<idCity,idStreet,idBuild>::operator=(const City_t<idCity,idStreet,idBuild>& ct)
	{
		if(ct.m_id!=m_id) m_id = ct.m_id;
		return *this;
	}

	template <class idCity,class idStreet,class idBuild>
	void City_t<idCity,idStreet,idBuild>::setCityID(idCity ct)
	{
		m_id=ct;
	}

	template <class idCity,class idStreet,class idBuild>
	const idCity& City_t<idCity,idStreet,idBuild>::getCityID()const
	{
		return m_id;
	}

	template <class idCity,class idStreet,class idBuild>
	bool City_t<idCity,idStreet,idBuild>::AddStreet(const Street_t<idStreet,idBuild>& st)
	{
		int i=0;
		for(i=0;i<v.size();i++)
		{
			if(v[i].getID()==st->m_id)
			{
				throw("is already found");
				return false;
			}
			v.push_back(st);
		}
	}

	template <class idCity,class idStreet,class idBuild>
	const Street_t<idStreet,idBuild>& City_t<idCity,idStreet,idBuild>::getStreet(unsigned int idx) const
	{
		if(idx<v.size()) return v[idx];
		else throw("idx>amount of street");
	}

#endif