#ifndef virtIO_H
#define virtIO_H

	#include <string>
	#include <stdio.h>
	#include <cstring>
	using namespace std;



	class virtIO_t
	{
	public:
		//should be public
		enum status{ok_e,cant_open_file_e,bad_access_e,writeErr_e,readErr_e};

		virtual ~virtIO_t(){fclose(m_fp);};
		virtIO_t(){this->m_fp=NULL;this->m_buff=NULL;}
		virtIO_t(const string& name, const char* mode);



		const string& getAccess()const {return this->m_mode;}
		const string& getPath()const {return this->m_name;}
		const long& getPose()const {return this->m_pose;}
		const status& getStatus()const {return this->m_state;}
		void setStatus(const status& st){this->m_state = st;}
		void open();
		long lengthOfFile()const;

		void close()
		{
			fclose(this->m_fp);
			m_state = bad_access_e;
		}
		
		void setPose(const long& ps)
		{
			m_pose = ps;
			fseek(m_fp,m_pose,SEEK_SET);
		}
	
		virtual virtIO_t& operator<<(int nBytes)=0;
		virtual virtIO_t& operator>>(int& nBytes)=0;
		virtual virtIO_t& operator<<(float nBytes)=0;
		virtual virtIO_t& operator>>(float& nBytes)=0;
		virtual virtIO_t& operator<<(long nBytes)=0;
		virtual virtIO_t& operator>>(long& nBytes)=0;
		virtual virtIO_t& operator<<(short nBytes)=0;
		virtual virtIO_t& operator>>(short& nBytes)=0;
		virtual virtIO_t& operator<<(char nBytes)=0;
		virtual virtIO_t& operator>>(char& nBytes)=0;
		virtual virtIO_t& operator<<(double nBytes)=0;
		virtual virtIO_t& operator>>(double& nBytes)=0;
		virtual virtIO_t& operator<<(unsigned int nBytes)=0;
		virtual virtIO_t& operator>>(unsigned int& nBytes)=0;
		virtual virtIO_t& operator<<(unsigned long nBytes)=0;
		virtual virtIO_t& operator>>(unsigned long& nBytes)=0;
		virtual virtIO_t& operator<<(unsigned short nBytes)=0;
		virtual virtIO_t& operator>>(unsigned short& nBytes)=0;
		virtual virtIO_t& operator<<(unsigned char nBytes)=0;
		virtual virtIO_t& operator>>(unsigned char& nBytes)=0;



	
	protected:
		FILE* m_fp;
		status m_state;
		string m_name;
		string m_mode;
		long m_pose;
		void* m_buff;

		bool IsStatus4Write(string mode)
		{
			return(!strcmp(mode.c_str(),"w")||!strcmp(mode.c_str(),"w+"))?false:true;
		}

		bool IsStatus4Read(string mode)
		{
			return(!strcmp(mode.c_str(),"r")||!strcmp(mode.c_str(),"r+"))?false:true;
		}

	private:
		virtIO_t(const virtIO_t& vt);
		virtIO_t& operator=(const virtIO_t& vt);
	};

#endif