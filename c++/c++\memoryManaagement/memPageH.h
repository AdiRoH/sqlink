#ifndef memPageH
#define memPageH

	#include "memManageH.h"
	#include <cstdio> //because of size_t
	#include <math.h> //because log() func

	class memPage_t: public memManager_t
	{
		public:
			virtual inline ~memPage_t();                                                       //DTOR

			inline memPage_t();                                                                //def CTOR
			/*memPage_t(const memPage_t& memP);*/                                       //copy CTOR is forbidden
			const memPage_t& operator=(const memPage_t&);                               //= operator

			inline memPage_t(size_t size);                                                     //CTOR

			inline const size_t getCurrPage() const;                                                          //get current position
			bool setCurrPage(size_t idx);                                            //set current position
			virtual bool readFromCurrPose(const void* info,unsigned int InfoSize);               //read from current position
			virtual bool readFromUserPose(const void* info,unsigned int InfoSize,size_t pose);   //read from user position
			virtual bool writeFromCurrPose(const void* info,unsigned int InfoSize);              //write from current position 
			virtual bool writeFromUserPose(const void* info,unsigned int InfoSize,size_t pose);  //write from user position
			inline bool isEmpty() const;                                                                //is page is empty?
			inline bool isFull() const;                                                                 //is page is full?
			inline const size_t& actualSize() const;                                                           //return actual size of page

		private:
			static size_t defSize;                                                         //default size of page, inseted by user
			size_t numOfbytes;                                                             //total amount of written bytes
			char* page;   
			void createPage() ;                                                                 //pointer to page (char because of bytes type)
			static void setDefSize(size_t defS);                                                                                      
			static size_t getDefSize();
	};


	inline memPage_t::~memPage_t()
	{
		if(page!=0) delete[]page;
	}

	inline memPage_t::memPage_t()
	{
		createPage();
	}

	inline memPage_t::memPage_t(size_t size)
	{
		setDefSize(size);
		createPage();
	}

	inline const size_t memPage_t::getCurrPage() const
	{
		return this->numOfbytes;
	}

	inline bool memPage_t::isEmpty() const
	{
		return (numOfbytes==0);
	}

	inline bool memPage_t::isFull() const 
	{
		return (numOfbytes==defSize);
	}

	inline const size_t& memPage_t::actualSize() const
	{
		return getCurrPage();
	}

	inline void memPage_t::setDefSize(size_t defS)  
	{
		defSize = pow(2, ceil(log(defS)/log(2)));
	}   

	inline size_t memPage_t::getDefSize() 
	{
		return defSize;
	}



#endif