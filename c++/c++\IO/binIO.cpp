#include "binIOH.h"

binIO_t& binIO_t::operator<<(const void* buff)
{
	if(m_state != ok_e ||!IsStatus4Read(this->m_mode)||buff==0)
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
	if(m_mode=="r")
		return scanI(lenBuff);
	else if(m_mode=="w")
		return printI(lenBuff);
}

