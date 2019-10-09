#ifndef memPoolH
#define memPoolH

	#include <vector>
	#include "memManageH.h"
	#include "memPageH.h"


	class memPool_t: public memManageH
	{
		public:
			inline ~memPool_t();                                                //DTOR
			inline memPool_t();                                                 //CTOR of vector
			memPool_t(const memPool_t&);
			const memPool_t& operator=(const memPool_t&);

			inline const size_t getCurrPose()const;                                        //get current position in vector
			bool setCurrPose(size_t pose);                               //set current position in vector
			inline bool isPgEmpty() const;
			inline size_t actualPgSize() const;
			virtual bool readFromCurrPose(const void* info,unsigned int InfoSize);     //read from current page
			virtual bool readFromUserPose(const void* info,unsigned int InfoSize,size_t pose);
			virtual bool writeFromCurrPose(const void* info,unsigned int InfoSize);
			bool writeFromUserPose(const void* info,unsigned int InfoSize,size_t pose);

		private:
			vector<Page_t*> v;
			size_t currPage;
			static size_t pageSize;
			static inline void setPageSize(size_t size);
			static inline size_t getPageSize() const;
			void createPage();
	};

	inline memPool_t::memPool_t()
	{
		createPage();
	}
	
	inline const size_t getCurrPose() const
	{
		return currPage;
	}

	inline memPool_t::~memPool_t();
	{
		 int i;
	     for(i=0;i<v.size();i++){
	     	delete v[i];
	}


	inline void setPageSize(size_t size)
	{
		this->pageSize=pow(2, ceil(log(size)/log(2)));
	}

	inline size_t getPageSize()
	{
		return this->pageSize;
	}

	inline bool isPgEmpty() const
	{
		return (v[1]==0||v.size()==1);
	}

	inline size_t actualPgSize() const
	{
		return getCurrPose();
	}

	

#endif