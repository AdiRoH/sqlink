#ifndef binIOH
#define binIOH

	#include "virtIO_H.h"

	class binIO_t:public virtIO_t
	{
	public:

		~binIO_t(){close();}

		binIO_t(const string& name, const char* mode):virtIO_t(name,mode){}
		binIO_t(){this->m_fp=NULL;this->m_buff=NULL;}

		binIO_t& operator<<(const void* Buff);
		binIO_t& operator>>(void* Buf);
		const binIO_t&  operator,(int lenBuff);

		virtual binIO_t& operator<<(int nBytes){return printI(nBytes);}
		virtual binIO_t& operator>>(int& nBytes){return scanI(nBytes);}
		virtual binIO_t& operator<<(float nBytes){return printI(nBytes);}
		virtual binIO_t& operator>>(float& nBytes){return scanI(nBytes);}

	private:
		template<class T> binIO_t& printI(T nBytes);
		template<class T> binIO_t& scanI(T nBytes);

		
	};

	template<class T> 
	binIO_t& binIO_t::printI(T nBytes)
	{
		if(fwrite(this->m_buff,nBytes,1,m_fp)!=1)
		{
			m_state = writeErr_e;
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

#endif