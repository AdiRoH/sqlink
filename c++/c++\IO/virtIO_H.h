#ifndef virtIO_H
#define virtIO_H

	#include <string>
	using namespace std;

	enum status{ok_e,cant_open_file_e,bad_access_e,writeErr_e,readErr_e,no_file_open_e};


	class virtIO_t
	{
	public:
		virtual ~virtIO_t()=0;
		virtIO_t(){};
		virtIO_t(const string& name, const char& mode){};
		virtual void open()=0;
		virtual void close()=0;
		virtual const string& getAccess()const=0;
		virtual const string& getPath()const=0;
		virtual long lengthOfFile()const=0;
		virtual void setPose(const long& ps)=0;
		virtual const long& getPose()const=0;
		virtual const status& getStatus()const=0;
		virtual void setStatus(const status& st)=0;
		virtual virtIO_t& operator<<(int nBytes)=0;
		virtual virtIO_t& operator>>(int& nBytes)=0;
		virtual virtIO_t& operator<<(float nBytes)=0;
		virtual virtIO_t& operator>>(float& nBytes)=0;
	private:
		//copyCTOR;
		//assign operator
	};

#endif