#ifndef memPageH
#define memPageH

	class memPage_t: public memManager_t
	{
		public:
			~memPage_t();
			memPage_t(size_t size);      					                               //CTOR
			size_t getCurrPage();                                                          //get current position
			bool setCurrPage(const size_t idx);                                            //set current position
			virtual readFromCurrPose(void* info,unsigned int InfoSize);               //read from current position
			virtual readFromUserPose(void* info,unsigned int InfoSize,size_t pose);   //read from user position
			virtual writeFromCurrPose(void* info,unsigned int InfoSize);              //write from current position 
			virtual writeFromUserPose(void* info,unsigned int InfoSize,size_t pose);  //write from user position
			bool isEmpty();                                                                //is page is empty?
			bool isFull();                                                                 //is page is full?
			size_t actualSize();                                                           //return actual size of page

		private:
			size_t defSize;                                                                //default size of page, inseted by user
			size_t numOfbytes;                                                             //total amount of written bytes
			char* page;                                                                    //pointer to page (char because of bytes type)                    
			// correct default size to static
	};



#ifndef