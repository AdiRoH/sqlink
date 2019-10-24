#include "binIOH.h"

binIO_t& binIO_t::operator<<(const void* buff)
{
	if(m_state != ok_e ||!IsStatus4Write(this->m_mode)||buff==0)
		throw(writeErr_e);
	else this->m_buff = (void*)buff;
	return *this;
}

binIO_t& binIO_t::operator>>(void* buff)
{
	if(m_state != ok_e ||!IsStatus4Read(this->m_mode)||buff==0)
		throw(readErr_e);
	else this->m_buff = (void*)buff;
	return *this;		
}

const binIO_t&  binIO_t::operator,(int lenBuff)
{
	if(m_mode=="r") fread(this->m_buff,lenBuff,1,m_fp);
	else if(m_mode=="w")
	{
		fwrite(this->m_buff,lenBuff,1,m_fp);
		this->m_pose = ftell(m_fp);	
	}
	return *this;
	    
}



