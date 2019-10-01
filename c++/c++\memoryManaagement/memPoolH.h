#ifndef memPoolH
#define memPoolH

	#include <vector>
	#include "memManageH"
	#include "memPageH"


	class memPool_t: public memManageH
	{
		public:
			memPool_t();               //constructor of vector

			size_t getCurrPose(); 
			bool setCurrPose(const size_t idx);

		private:
			vector<Page_t*> v;
			size_t currPage;
	};

#endif