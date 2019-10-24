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
	

		virtual asciiIO_t& operator<<(int nBytes) {return printI(nBytes,"%d");}
		virtual asciiIO_t& operator>>(int& nBytes) {return scanI(nBytes,"%d");}
		virtual asciiIO_t& operator<<(float nBytes) {return printI(nBytes,"%f");}
		virtual asciiIO_t& operator>>(float& nBytes){return scanI(nBytes,"%f");}
		virtual asciiIO_t& operator<<(long nBytes){return printI(nBytes,"%l");}
		virtual asciiIO_t& operator>>(long& nBytes){return scanI(nBytes,"%l");}//%l
		virtual asciiIO_t& operator<<(short nBytes){return printI(nBytes,"%h");}
		virtual asciiIO_t& operator>>(short& nBytes){return scanI(nBytes,"%h");}//%h
		virtual asciiIO_t& operator<<(char nBytes){return printI(nBytes,"%c");}
		virtual asciiIO_t& operator>>(char& nBytes){return scanI(nBytes,"%c");}//%c
		virtual asciiIO_t& operator<<(double nBytes){return printI(nBytes,"%lf");}
		virtual asciiIO_t& operator>>(double& nBytes){return scanI(nBytes,"%lf");}//%lf
		virtual asciiIO_t& operator<<(unsigned int nBytes) {return printI(nBytes,"%lu");}//%lu
		virtual asciiIO_t& operator>>(unsigned int& nBytes){return scanI(nBytes,"%lu");}
		virtual asciiIO_t& operator<<(unsigned long nBytes){return printI(nBytes,"%lu");}//%lu
		virtual asciiIO_t& operator>>(unsigned long& nBytes){return scanI(nBytes,"%lu");}
		virtual asciiIO_t& operator<<(unsigned short nBytes) {return printI(nBytes,"%hu");}//%hu
		virtual asciiIO_t& operator>>(unsigned short& nBytes){return scanI(nBytes,"%hu");}
		virtual asciiIO_t& operator<<(unsigned char nBytes){return printI(nBytes,"%u");}//%u
		virtual asciiIO_t& operator>>(unsigned char& nBytes){return scanI(nBytes,"%u");}
	

	private:
		asciiIO_t(const asciiIO_t& asc);
		asciiIO_t& operator=(const asciiIO_t& asc);
		template<class T>asciiIO_t& printI(T nBytes,string format);
		template<class T>asciiIO_t& scanI(T nBytes,string format);
		
	};

	template<class T>
	asciiIO_t& asciiIO_t::printI(T nBytes,string format)
	{
		if(m_state != ok_e || !IsStatus4Write(this->m_mode)||m_fp!=NULL)
		{
			if(fprintf(m_fp,format.c_str(),nBytes)<=0)
			{
				m_state = writeErr_e;
				throw(writeErr_e);
			}
				 
			else
			{
				this->m_pose = ftell(this->m_fp);	
			} 
			return *this;
		}
		else throw(writeErr_e);
		
	}

	template<class T>
	asciiIO_t& asciiIO_t::scanI(T nBytes,string format)
	{
		if(m_state != ok_e || !IsStatus4Read(this->m_mode)||m_fp!=NULL)
		{
			if(fscanf(m_fp,format.c_str(),nBytes)<nBytes)
			{
				m_state = readErr_e;
				throw(readErr_e);
			}
				
			else return *this;
		}
		else throw(readErr_e);
	}

#endif