#include "containerH.h"
#include <vector>
#include <list>
#include <typeinfo>

#include <cstddef>
using namespace std;

template <class T,class containerT>
tContainer_t<T,containerT>::~tContainer_t()
{
	int i=0;
	if(!this->con.isEmpty())
	{
		for(i=0;i<this->con.size();i++)
			delete this->con[i];
	}
}


template <class T,class containerT>
T* tContainer_t<T,containerT>::findElem(const T& el)
{
	iter_t it= find_if(this->con.begin(),this->con.end(),findExactElem<T,containerT>::findExactElem(el));
	if(it!=con.end())
	{
		T* res = *it;
		return res;
	}
	else return 0;
}


template <class T,class containerT>
T& tContainer_t<T,containerT>::operator[](size_t idx) const
{
	if(idx>this->con.size()) 
		throw("index exceeding");

	if(typeid(this->con)==typeid(std::vector<T>))
		return this->con[idx];

	else if(typeid(this->con)==typeid(std::list<T>))
	{
		iter_t it = con.begin();
		std::advance(it, idx);
		return (T*)*it;
	}	
}


template <class T,class containerT>
const T& tContainer_t<T,containerT>::removeElem(const T& el)//"private func"
{
	T val;
	val= findElem(el);
	if(!val)
	{
		con.erase(val); 
		return &val;
	}
	else throw("container doesn't contain this");
}

template <class T,class containerT>
void tContainer_t<T,containerT>::removeAllElems()
{
	con.erase(con.begin(),con.begin()+con.size()-1);
}

template <class T,class containerT>
void tContainer_t<T,containerT>::removeDelExactElem(const T& el)
{
	T val;
	&val = removeElem(el);
	delete val;
}

template <class T,class containerT>
void tContainer_t<T,containerT>::removeDelAllElem()
{
	this->con.clear();
}

