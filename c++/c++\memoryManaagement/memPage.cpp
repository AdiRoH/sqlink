#include "memManageH.h"
#include "memPageH.h"
#include <string.h>


size_t memPage_t::defSize = 1024;



void memPage_t::createPage()
{
	if(page = 0)
	{
		numOfbytes=0;
		page=new char[defSize];
		page[0]='\0';
	}
}

bool memPage_t::setCurrPage(size_t idx)
{
	if(idx<=defSize)
	{
		this->numOfbytes = idx;
		return true;
	}
	else return false;
}



bool memPage_t::readFromUserPose(const void* info,unsigned int InfoSize,size_t pose)
{
	if(info==0||InfoSize<1||pose==0) return false;
	if(pose>numOfbytes) return false;
	this->setCurrPage(pose);
	memcpy((char*)info, page, InfoSize);
	numOfbytes--;
	return true;
}



bool memPage_t::writeFromUserPose(const void* info,unsigned int InfoSize,size_t pose)
{
	if(info==0||InfoSize<1||pose>defSize||(pose+InfoSize)>defSize) return false;
	this->setCurrPage(pose);
	memcpy(page,(char*)info,InfoSize);
	numOfbytes++;
	return true;
}


bool memPage_t::readFromCurrPose(const void* info,unsigned int InfoSize)
{
	return readFromUserPose(info,InfoSize,numOfbytes);	
}

bool memPage_t::writeFromCurrPose(const void* info,unsigned int InfoSize)
{
	return this->writeFromUserPose(info,InfoSize,numOfbytes);
}

