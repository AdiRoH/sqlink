#ifndef asciiO_H
#define asciiO_H

	#include "virtIO_H.h"
	#include <string>
	#include <stdio.h>
	#include <cstring>

	template <class T>
	class asciiIO_t:public virtIO_t
	{
	public:

		~asciiIO_t(){if(m_fp!=0)close();}
		asciiIO_t(const string& name, const char& mode);
		asciiIO_t() { this->m_fp=NULL;}



		virtual void open();
		virtual void close()
		{
			fclose(this->m_fp);
			m_state = no_file_open_e;
		}

		virtual const string& getAccess()const {return this->m_mode;}
		virtual const string& getPath()const {return this->m_name;}
		virtual const long& getPose()const {return this->m_pose;}
		virtual const status& getStatus()const {return this->m_state;}
		virtual void setStatus(const status& st){this->m_state = st;}

		virtual long lengthOfFile()const
		{
			 fseek(m_fp, 0L, SEEK_END);
			 return ftell(m_fp);
		}
		virtual void setPose(const long& ps)
		{
			m_pose = ps;
			fseek(m_fp,m_pose,SEEK_SET);
		}

		virtual virtIO_t& operator<<(int nBytes)
		{
			printI(nBytes,"%d");
			return *this;
		}
		virtual virtIO_t& operator>>(int& nBytes)
		{
			scanI(nBytes,"%d");
			return *this;
		}
		virtual asciiIO_t& operator<<(float nBytes)
		{
			printI(nBytes,"%f");
			return *this;
		}
		virtual asciiIO_t& operator>>(float& nBytes)	
		{
			scanI(nBytes,"%f");
			return *this;
		}

		

	//fwrite//fread in binari
	private:
		asciiIO_t(const asciiIO_t& asc);
		asciiIO_t& operator=(const asciiIO_t& asc);

		FILE* m_fp;
		status m_state;
		string m_name;
		string m_mode;
		long m_pose;

		const char* convertStr2Ch(const string& str)
		{
			char *cstr = new char [str.length()+1];
  			strcpy (cstr, str.c_str());
  			return cstr;
		}

		bool IsStatus4Write(string mode)
		{
			return(mode!="w"||mode!="w+")?false:true;
		}

		bool IsStatus4Read(string mode)
		{
			return(mode!="r"||mode!="r+")?false:true;
		}

		void printI(T nBytes,string format);
		void scanI(T nBytes,string format);
		
	};

#endif