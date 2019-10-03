#ifndef StreetH
#define StreetH

#include BuildingH.h
#include <vector>

	template <class idStreet,class idBuild>

	
	class Street_t
	{
		public:
			~Street_t();
			Street_t();
			&Street_t operator=(Street_t&);
			Street_t(Build_t& const);
			void setID(idBuild idB);
			idBuild getID() const;
			bool AddBuilding2Street(idStreet st,idBuild bld);
			&build_t getBuilding();

		private:
			idStreet id;
			void createBuild();
			std::vector<build_t<idBuild> > v;
	};
		
	street_t::~street_t()
	{

	}

	street_t::street_t()
	{

	}

	void street_t::createBuild()
	{
		
	}

	&Street_t street_t::operator=(Street_t&)
	{
		return (Street_t->id==id)//correct
	}

	Street_t::Street_t(const Build_t& build)
	{
		id = build->id;
	}

	void Street_t::setID(idBuild idB)
	{
		id = idB;
	}

	idBuild Street_t::getID() const
	{
		return id;
	}

	bool Street_t::AddBuilding2Street(idBuild bld)
	{
		build_t build;
		build->idBuild = bld;
		myvector.push_back(build);
	}

	&build_t street_t::getBuilding()
	{
		return v.end();
	}

#endif