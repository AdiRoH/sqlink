#ifndef memPoolH
#define memPoolH

	#include <vector>
	#include "memManageH"
	#include "memPageH"


	class memPool_t: public memManageH
	{
		public:
			~memPool_t();                                                //DTOR
			memPool_t();                                                 //CTOR of vector

			size_t getCurrPose();                                        //get current position in vector
			bool setCurrPose(size_t pose);                               //set current position in vector
			bool isPgEmpty();
			size_t actualPgSize();
			virtual bool readFromCurrPose(void* info,unsigned int InfoSize);     //read from current page
			virtual bool readFromUserPose(void* info,unsigned int InfoSize,size_t pose);
			virtual bool writeFromCurrPose(void* info,unsigned int InfoSize);
			virtual bool writeFromUserPose(void* info,unsigned int InfoSize,size_t pose);

		private:
			vector<Page_t*> v;
			size_t currPage;
			static size_t pageSize;
			static void setPageSize(size_t size);
			static getPageSize();
			static size_t getPageSize();
			void createPage();
	};

#endif