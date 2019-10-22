#include <string>
using namespace std;

typedef enum status{ok_e,cant_open_file_e,bad_access_e,writeErr_e,readErr_e}status;

class virtIO_t
{
public:
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