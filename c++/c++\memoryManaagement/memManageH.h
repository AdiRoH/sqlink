#ifndef memManageH
#define memManageH

	class memManager_t
	{
		public:

			virtual bool readFromCurrPose(void* info,unsigned int InfoSize);             			 //read from current position
			virtual bool readFromUserPose(void* info,unsigned int InfoSize,size_t pose);              //read from user position
			virtual bool writeFromCurrPose(void* info,unsigned int InfoSize);           			     //write from current position
			virtual bool writeFromUserPose(void* info,unsigned int InfoSize,size_t pose);           	 //write from user position

			

			writtenBytes();              		     //how many bytes are written, including: is memory is empty
		protected:
			
		private:
			memManager_t(memManager_t& mem);         //copy constructor

	};



#endif