#include "memManageH.h"
#include "memPageH.h"
#include "string.h"

//should I always write a default constructor?- no. we aren't going to solve futural bugs

memPage_t::~memPage_t()
{
	if(page!=0) delete[]page;
}

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
	setCurrPage(numOfbytes);
	memcpy((char*)info, (char*)page, InfoSize);
	numOfbytes--;
	return true;
	
}

bool memManage_t::readFromUserPose(void* info,unsigned int InfoSize,size_t pose)
{
	if(info==0) return false;
	if(pose>numOfbytes) return false;
	setCurrPage(pose);
	memcpy((char*)info, (char*)page, InfoSize);
	numOfbytes--;
	return true;
}

bool memManager_t::writeFromCurrPose(void* info,unsigned int InfoSize)
{
	//insert that Info size< free space
	if(info==0) return false;
	setCurrPage(numOfbytes);
	memcpy((char*)page,(char*)info,InfoSize);
	numOfbytes++;
	return true;
}

bool memManager_t::writeFromUserPose(void* info,unsigned int InfoSize,size_t pose)
{
	//insert that Info size< free space
	if(info==0||numOfbytes<pose) return false;
	setCurrPage(pose);
	memcpy((char*)page,(char*)info,InfoSize);
	numOfbytes++;
	return true;
}

bool isEmpty()
{
	(numOfbytes==0) ? return true:return false;
}

bool isFull() 
{
	(numOfbytes==defSize) ? return true:return false;
}

size_t actualSize()
{
	return getCurrPage();
}




