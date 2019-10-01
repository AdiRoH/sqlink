#include "memManageH.h"
#include "memPageH.h"

//should I always write a default constructor?

memPage_t::memPage_t(size_t size)
{
	this->defSize=pow(2, ceil(log(size)/log(2)));
	numOfbytes = 0;
	page = new char[defSize];
}

size_t memPage_t::getCurrPage()
{
	return this->page[numOfbytes];
}

void memPage_t::setCurrPage(const size_t idx)
{
	if(idx<=defSize)
	{
		this->page[numOfbytes] = idx;
		return true;
	}
	else return false;
}

bool memPage_t::readFromCurrPose(void* info,unsigned int InfoSize)
{
	if(info==0) return false;
	if(InfoSize==1) 
	{
		this->page[numOfbytes] = *(char*)info;
		return true;
	}
	else
	{
		//think about this
	}
}

bool memManage_t::readFromUserPose(void* info,unsigned int InfoSize,size_t pose)
{
	if(info==0) return false;
	if(InfoSize==1) 
	{
		this->page[pose] = *(char*)info;
		return true;
	}
	else
	{
		//think about this
	}
}



bool memManager_t::writeFromCurrPose(void* info,unsigned int InfoSize)
{
	if(info==0) return false;
	if(InfoSize==1) 
	{
		*(char*)info = this->page[numOfbytes];
		return true;
	}
	else
	{
		//think about this
	}

}

bool memManager_t::writeFromUserPose(void* info,unsigned int InfoSize,size_t pose)
{
	if(info==0) return false;
	if(InfoSize==1) 
	{
		*(char*)info = this->page[pose];
		return true;
	}
	else
	{
		//think about this
	}

}









