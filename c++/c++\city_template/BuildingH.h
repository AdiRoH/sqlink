#ifndef BuildingH
#define BuildingH

	template <class idBuild>
	
	class Build_t
	{
		public:
			~Build_t();
			Build_t();
			Build_t(Build_t& const);
			&Built_t opertor=(const Built_t& build);
			void setID(idBuild idB);
			idBuild getID() const;

		private:
			idBuild id;
	};
		
	Bulild_t::~Build_t()
	{

	}

	Build_t::Build_t();
	{

	}


Built_t::Build_t(const Build_t&)
{
	return 
}

&Built_t Built_t::operator=(const Built_t& build)
{
	build->id=id;
	return build;
}

void Built_t::setID(idBuild idB)
{
	id=idB;
}

idBuild Built_t::getID() const
{
	return id;
}


#endif
