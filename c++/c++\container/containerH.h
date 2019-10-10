#ifndef containerH
#define containerH

	#include <cstddef>
	#include <typeinfo>
	#include <vector>
	#include <list>
	
	template <class T,class containerT>
	class  tContainer_t 
	{

		//destruxtor is virtual, should be empty
		//reference can't return NULL, only pointer can
		//const func() only when return only to member in private
		public:
			virtual ~tContainer_t();
			inline bool isEmpty()const;
			inline tContainer_t(){;};
			inline size_t numOfElement()const;
			inline void insertElemEnd(const T& el);
			inline T& firstElem();
			inline T& lastElem();
			inline T* findElem(const T& el);
			const T& removeElem(const T& el);//remove specific element
			inline void removeAllElems();
			inline void removeDelExactElem(const T& el);
			inline void removeDelAllElem();
			inline T& operator[](size_t idx) const;
			// copy is forbidden-no copy constructor and no =operator*/

		private:
			containerT con;	
			typedef typename containerT::iterator iter_t;
	};


	template <class T,class containerT>
	class findExactElem
	{
		public:
			findExactElem(const T &val) : m_val(val){}
			bool operator()(const T& param)const{return (param==m_val);};
		private:
			T m_val;

	};

	template <class T,class containerT>
	inline bool tContainer_t<T,containerT>::isEmpty() const
	{
		return(con.empty());
	}


	template <class T,class containerT>
	inline void tContainer_t<T,containerT>::insertElemEnd(const T& el)
	{
		con.insert(con.size()-1,el);
	}

	template <class T,class containerT>
	inline size_t tContainer_t<T,containerT>::numOfElement() const
	{
		return con.size();
	}

	template <class T,class containerT>
	inline T& tContainer_t<T,containerT>::firstElem()
	{
		if(isEmpty()) return 0;
		else return con[0];
	}

	template <class T,class containerT>
	inline T& tContainer_t<T,containerT>::lastElem()
	{
		if(isEmpty()) return 0;
		else return con[con.size()-1];
	}


	template <class T,class containerT>
	inline T* tContainer_t<T,containerT>::findElem(const T& el)
	{
		iter_t it= find_if(this->con.begin(),this->con.end(),findExactElem<T,containerT>::findExactElem(el));
		return (it!=con.end())? it:0;
	}


	template <class T,class containerT>
	inline T& tContainer_t<T,containerT>::operator[](size_t idx) const
	{
		if(idx>this->con.size()) 
			throw("index exceeding");

		if(typeid(containerT)==typeid(std::vector<T*>))
			return (*(std::vector<T*>*)&con) [idx];

		else if(typeid(containerT*)==typeid(std::list<T*>*))
		{
			iter_t it = con.begin();
			std::advance(it, idx);
			return (T*)*it;
		}	
	}


	template <class T,class containerT>
	inline const T& tContainer_t<T,containerT>::removeElem(const T& el)//"private func"
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
	inline void tContainer_t<T,containerT>::removeAllElems()
	{
		con.erase(con.begin(),con.begin()+con.size()-1);
	}

	template <class T,class containerT>
	inline void tContainer_t<T,containerT>::removeDelExactElem(const T& el)
	{
		T val;
		&val = removeElem(el);
		delete val;
	}

	template <class T,class containerT>
	inline void tContainer_t<T,containerT>::removeDelAllElem()
	{
		this->con.clear();
	}
#endif