#ifndef binIOH
#define binIOH

	#include "virtIO_H.h"

	class binIO_t:public virtIO_t
	{
	public:

		~binIO_t(){close();}//should be empty,explanation in base.h

		binIO_t(const string& name, const char* mode):virtIO_t(name,mode){}
		binIO_t(){this->m_fp=NULL;this->m_buff=NULL;}

		binIO_t& operator<<(const void* Buff);
		binIO_t& operator>>(void* Buf);
		const binIO_t&  operator,(int lenBuff);

		virtual binIO_t& operator<<(int nBytes) {return writeFunc(nBytes);}
		virtual binIO_t& operator>>(int& nBytes){return readFunc(nBytes);}
		virtual binIO_t& operator<<(float nBytes){return writeFunc(nBytes);}
		virtual binIO_t& operator>>(float& nBytes){return readFunc(nBytes);}

		virtual binIO_t& operator<<(long nBytes) {return writeFunc(nBytes);}
		virtual binIO_t& operator>>(long& nBytes){return readFunc(nBytes);}//%l
		virtual binIO_t& operator<<(short nBytes){return writeFunc(nBytes);}
		virtual binIO_t& operator>>(short& nBytes){return readFunc(nBytes);}//%h
		virtual binIO_t& operator<<(char nBytes) {return writeFunc(nBytes);}
		virtual binIO_t& operator>>(char& nBytes){return readFunc(nBytes);}//%c
		virtual binIO_t& operator<<(double nBytes){return writeFunc(nBytes);}
		virtual binIO_t& operator>>(double& nBytes){return readFunc(nBytes);}//%lf
		virtual binIO_t& operator<<(unsigned int nBytes) {return writeFunc(nBytes);}//%lu
		virtual binIO_t& operator>>(unsigned int& nBytes){return readFunc(nBytes);}
		virtual binIO_t& operator<<(unsigned long nBytes){return writeFunc(nBytes);}//%lu
		virtual binIO_t& operator>>(unsigned long& nBytes){return readFunc(nBytes);}
		virtual binIO_t& operator<<(unsigned short nBytes) {return writeFunc(nBytes);}//%hu
		virtual binIO_t& operator>>(unsigned short& nBytes){return readFunc(nBytes);}
		virtual binIO_t& operator<<(unsigned char nBytes){return writeFunc(nBytes);}//%u
		virtual binIO_t& operator>>(unsigned char& nBytes){return readFunc(nBytes);}

	private:
		template<class T> const binIO_t& printI(T nBytes);
		template<class T> binIO_t& scanI(T nBytes);
		template<class T> binIO_t& writeFunc(T nBytes);
		template<class T> binIO_t& readFunc(T nBytes);
		//assign operator
		//copy constructor
	};


	template<class T> 
	const binIO_t& binIO_t::printI(T nBytes)
	{
		if(fwrite(this->m_buff,nBytes,1,m_fp)!=1)
		{
			m_state = writeErr_e;
		}
		else
		{
			m_pose = ftell(m_fp);
		}
		return *this;
	}

	template<class T> 
	binIO_t& binIO_t::scanI(T nBytes)
	{
		if(fread(this->m_buff,nBytes,1,m_fp)<=0)
		{
			m_state = readErr_e;
		}
		return *this;
	}

	template<class T> 
	binIO_t& binIO_t::writeFunc(T nBytes)
	{
		if(m_state != ok_e ||!IsStatus4Write(this->m_mode))//||m_fp==0
		{
			fwrite(&nBytes, sizeof(nBytes), 1, m_fp);
			this->m_pose = ftell(this->m_fp);
		}
		return *this;
	}

	template<class T> 
	binIO_t& binIO_t::readFunc(T nBytes)
	{
		if(m_state != ok_e ||!IsStatus4Write(this->m_mode))//||m_fp==0
		{
			fread(&nBytes, sizeof(nBytes), 1, this->m_fp);
			this->m_pose = ftell(this->m_fp);
		}
		return *this;
	}

#endif