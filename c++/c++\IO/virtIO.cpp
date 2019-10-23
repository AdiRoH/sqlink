#include "virtIO_H.h"
         
virtIO_t::virtIO_t(const string& name, const char* mode)
{
	this->m_name = name;
	if(this->m_mode!="r"||this->m_mode!="w"||this->m_mode!="r+"||this->m_mode!="w+") 
		throw(bad_access_e);
	else m_mode = mode;
	open();//initialize m_Stat;
	this->m_pose = 0;
	this->m_buff = NULL;

}

void virtIO_t::open()
{
	m_fp =fopen(this->m_name.c_str(),this->m_mode.c_str());
	(m_fp==0)?m_state = cant_open_file_e:m_state = ok_e;
}


long virtIO_t::lengthOfFile()const
{ 
	long res,currPose = ftell(m_fp);
	fseek(m_fp, 0L, SEEK_END);
	res = ftell(m_fp);
	fseek(m_fp,currPose,SEEK_SET);//not initialize into m_pose because the function is const
	return res;
}
