#ifndef BuildingH
#define BuildingH

	template <class idBuild>
	
	class Build_t
	{
		public:
			~Build_t();
			Build_t();
			Build_t(const Build_t& build);
			Build_t<idBuild> & operator=(const Build_t& build);
			void setID(idBuild idB);
			const idBuild& getID() const;

		private:
			idBuild m_id;
	};

	template <class idBuild>
	Build_t<idBuild>::~Build_t(){}

	template <class idBuild>
	Build_t<idBuild>::Build_t(){}

	template <class idBuild>
	Build_t<idBuild>::Build_t(const Build_t& build)
	{
		m_id=build->m_id;
	}

	template <class idBuild>
	Build_t<idBuild>& Build_t<idBuild>::operator=(const Build_t<idBuild>& build)//must tell the type idBuild
	{
		if (&build != this)
		{
			m_id=build.m_id;
		}
		return *this;
	}

	template <class idBuild>
	void Build_t<idBuild>::setID(idBuild idB)
	{
		m_id=idB;
	}

	template <class idBuild>
	const idBuild& Build_t<idBuild>::getID() const
	{
		return m_id;
	}


#endif
