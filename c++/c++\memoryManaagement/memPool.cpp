#include "memPoolH.h"
#include "vector"
#include <string.h>

size_t memPool_t::pageSize=1024;



void createPage()
{
	Page_t* pg = new page_t;
	v.insert(v.end(), pg);	
	currPage++;
}



bool setCurrPose(size_t pose)
{
	if(pose<=v.size())
	{
		this->currPage = pose;
		return true;
	}
	else return false;
}



bool readFromUserPose(void* info,unsigned int InfoSize,size_t pose)
{
	if(info==0||pose>currPage||InfoSize<1) return false;
	this->setCurrPose(pose);
	memcpy((char*)info, (char*)v[pose], InfoSize);
	currPage--;
	return true;
}


bool writeFromUserPose(void* info,unsigned int InfoSize,size_t pose)
{
	size_t reminder=0,middlePose=0;
	if(info==0||pose>currPage||InfoSize<1) return false;
	if(pageSize-pose>=InfoSize)
	{
		this->setCurrPose(pose);
		memcpy((char*)info, (char*)v[pose], InfoSize);
		currPage++;
	}
	else
	{
		reminder=InfoSize-(pageSize-pose);
		middlePose=InfoSize-reminder;
		memcpy((char*)info, (char*)v[pose], middlePose);
		memcpy((char*)info, (char*)v[middlePose+1], reminder);
		currPage++;
	}
	return true;
}


