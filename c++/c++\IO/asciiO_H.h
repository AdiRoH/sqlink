#ifndef asciiO_H
#define asciiO_H

	#include "virtIO_H.h"
	#include <string>
	#include <stdio.h>
	#include <cstring>

	class asciiIO_t:public virtIO_t
	{
	public:

		~asciiIO_t(){if(m_fp!=0) close();}
		asciiIO_t(const string& name, const char* mode):virtIO_t(name,mode){};
		asciiIO_t(){this->m_fp=NULL;this->m_buff=NULL;}
	

		virtual asciiIO_t& operator<<(int nBytes)   
		{
			if(m_state != ok_e ||!IsStatus4Write(this->m_mode)||m_fp!=0)
				return printI(nBytes,"%d");
		}

		virtual asciiIO_t& operator>>(int& nBytes)  
		{
			if(m_state != ok_e ||!IsStatus4Read(this->m_mode)||m_fp!=0)
				return scanI(nBytes,"%d");
		}

		virtual asciiIO_t& operator<<(float nBytes) 
		{
			if(m_state != ok_e ||!IsStatus4Write(this->m_mode)||m_fp!=0)
				return printI(nBytes,"%f");
		}

		virtual asciiIO_t& operator>>(float& nBytes)
		{
			if(m_state != ok_e ||!IsStatus4Read(this->m_mode)||m_fp!=0)
				return scanI(nBytes,"%f");
	}

	private:
		asciiIO_t(const asciiIO_t& asc);
		asciiIO_t& operator=(const asciiIO_t& asc);
		template<class T>asciiIO_t& printI(T nBytes,string format);
		template<class T>asciiIO_t& scanI(T nBytes,string format);
		
	};

#endif