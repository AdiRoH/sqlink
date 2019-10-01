#include "memPoolH.h"
#include "vector"

memPool_t::memPool_t()
{
	page_t* pg=new page_t;
	v.insert(v.end(), pg)
	currPage = 0;
}

size_t memPool_t::getCurrPose()
{
	return this->currPage;
}

bool memPool_t::setCurrPose(const size_t idx)
{
	if(idx<v.capacity)
	{
		this->currPage = idx;
		return true;
	}
	else return false;
}

bool memManage_t::readFromCurrPose(void* info,unsigned int InfoSize)
{
	if(info==0) return false;
	if(InfoSize==1) 
	{
		this->v[currPage] = *(char*)info;
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
