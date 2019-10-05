#ifndef memManageH
#define memManageH

	#include <cstdio> //because of size_t

	class memManager_t
	{
		public:

			~memManager_t(){}
			memManager_t(){}
			const memManager_t& operator=(const memManager_t&);
			virtual bool readFromCurrPose(void* info,unsigned int InfoSize);             			 //read from current position
			virtual bool readFromUserPose(void* info,unsigned int InfoSize,size_t pose);              //read from user position
			virtual bool writeFromCurrPose(void* info,unsigned int InfoSize);           			     //write from current position
			virtual bool writeFromUserPose(void* info,unsigned int InfoSize,size_t pose);           	 //write from user position

			bool setPose(size_t pose);
			size_t getPose();
			bool isEmpty()const;
			size_t actualSize();
			
		private:
			memManager_t(const memManager_t& mem);         //copy constructor

	};



#endif