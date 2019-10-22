#include "virtIO_H.h"
#include <string>
class asciiIO_t:public virtIO_t
{
	~virtIO_t(){};
	virtIO_t();
	virtIO_t(const string& name, const char& mode);
	virtual status open()=0;
	virtual status close()=0;
	virtual char& getAccess()const=0;
	string& getPath()const;
	unsigned int& lengthOfFile()const;
	void setPose(const int& ps);
	long int& getPose()const;
	const status& getStatus(const status&)const;
	void setStatus(const status&);
	virtual status operator<<(int nBytes)=0;
	virtual status operator>>(int nBytes)=0;
};