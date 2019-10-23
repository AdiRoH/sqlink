#include "asciiO_H.h"

template<class T>
asciiIO_t& asciiIO_t::printI(T nBytes,string format)
{
	if(fprintf(m_fp,format.c_str(),nBytes)<=0)
		 m_state = writeErr_e;
	else return *this;

}

template<class T>
asciiIO_t& asciiIO_t::scanI(T nBytes,string format)
{
	
	if(fscanf(m_fp,format.c_str(),nBytes)<nBytes)
		m_state = readErr_e;
	else return *this;
}
