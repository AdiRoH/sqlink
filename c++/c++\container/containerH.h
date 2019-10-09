#ifndef containerH
#define containerH

	#include <cstddef>
	
	template <class T,class containerT>
	class  tContainer_t 
	{
		public:
			~tContainer_t();
			tContainer_t(){;};
			inline bool isEmpty()const;
			inline size_t numOfElement()const;
			inline void insertElemEnd(const T& el);
			inline T& firstElem();
			inline T& lastElem();
			T* findElem(const T& el);
			const T& removeElem(const T& el);//remove specific element
			void removeAllElems();
			void removeDelExactElem(const T& el);
			void removeDelAllElem();
			T& operator[](size_t idx) const;
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
		return(this->con.empty());
	}


	template <class T,class containerT>
	inline void tContainer_t<T,containerT>::insertElemEnd(const T& el)
	{
		this->con.insert(con.size()-1,el);
	}

	template <class T,class containerT>
	inline size_t tContainer_t<T,containerT>::numOfElement() const
	{
		return this->con.size();
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


#endif