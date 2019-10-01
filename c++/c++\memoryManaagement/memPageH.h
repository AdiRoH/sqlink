#ifndef memPageH
#define memPageH

	class memPage_t: public memManager_t
	{
		public:
			void insertDefSize(size_t size);    //insert default size of bytes. floor/ceil to power of 2
			memPage_t();      					//CTOR
			
			bool empty();                       //is page is empty?
			bool Full();                        //is page is full?
			size_t actualSize();                //actual size of written bytes(=pos);
			size_t capPage();                   //capacity of page


			size_t getCurrPage();                                                  //get current position
			bool setCurrPage(const size_t idx);                                    //set current position
			memManager_t.readFromCurrPose(void* info,unsigned int InfoSize);       //read from current position
			memManager_t.readFromUserPose(void* info,unsigned int InfoSize,size_t pose);


		private:
			size_t defSize;
			size_t numOfbytes;
			char* page;

	};



#ifndef