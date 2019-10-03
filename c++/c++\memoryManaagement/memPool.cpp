#include "memPoolH.h"
#include "vector"

static size_t pageSize=1024;

memPool_t::memPool_t()
{
	currPage = 0;
	createPage();
}

void createPage()
{
	Page_t* pg = new page_t;
	v.insert(v.end(), pg);	
	currPage++;
}

memPool_t::~memPool_t();
{
	 int i;
     for(i=0;i<v.size();i++){
     	delete v[i];
}

size_t getCurrPose()
{
	return this->currPage;
}

bool setCurrPose(size_t pose)
{
	if(pose<=v.capacity())
	{
		this->currPage = pose;
		return true;
	}
	else return false;
}

bool readFromCurrPose(void* info,unsigned int InfoSize)
{
	if(info==0) return false;
	if(InfoSize>currPage) return false;
	setCurrPose(currPage);
	memcpy((char*)info, (char*)v[currPage], InfoSize);
	currPage--;
	return true;
}

bool readFromUserPose(void* info,unsigned int InfoSize,size_t pose)
{
	if(info==0) return false;
	if(pose>currPage) return false;
	if(InfoSize>currPage) return false;
	setCurrPose(pose);
	memcpy((char*)info, (char*)v[pose], InfoSize);
	currPage--;
	return true;
}

// allocateing new page when the previous is full

bool writeFromCurrPose(void* info,unsigned int InfoSize)
{
	size_t reminder=0,middlePose=0;
	if(info==0) return false;
	if(pageSize-currPage>=InfoSize)
	{
		setCurrPose(currPage);
		memcpy((char*)info, (char*)v[currPage], InfoSize);
		currPage++;
	}
	else
	{
		reminder=InfoSize-(pageSize-currPage);
		middlePose=InfoSize-reminder;
		memcpy((char*)info, (char*)v[currPage], middlePose);
		memcpy((char*)info, (char*)v[middlePose+1], reminder);
		currPage++;
	}

	return true;
}

bool writeFromUserPose(void* info,unsigned int InfoSize,size_t pose)
{
	size_t reminder=0,middlePose=0;
	if(info==0) return false;
	if(pose>currPage) return false;
	if(pageSize-pose>=InfoSize)
	{
		setCurrPose(pose);
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
}

static void setPageSize(size_t size)
{
	this->pageSize=pow(2, ceil(log(size)/log(2)));
}

static size_t getPageSize()
{
	return this->pageSize;
}

bool isPgEmpty()
{
	(v[1]=0) ? return true:return false;
}

size_t actualPgSize()
{
	return getCurrPose();
}

