#include "asciiO_H.h"


asciiIO_t::asciiIO_t(const string& name, const char& mode)//implemented
{
	this->m_name = name;
	this->m_mode = mode;
	this->m_state = open();//fopen
	this->m_pose = 0;
	if(m_state!=ok_e)
		throw("can't open file!");
}


asciiIO_t::void open()
{
	const char* a=convertStr2Ch(this->m_name);
	const char* b=convertStr2Ch(this->m_mode);
	m_fp =fopen(a,b);
	(m_fp==0)?m_stat = cant_open_file_e:m_stat = ok_e;
}

template<class T>
void asciiIO_t::printI(T nBytes,string format)
{
	if(m_stat != ok_e ||!IsStatus4Write(this->m_mode))

	if(format=="%d")
	{
		fprintf(m_fp,"%d",nBytes);
	}

	else if(format=="%f")
	{
		fprintf(m_fp,"%f",nBytes);
	}
}

template<class T>
void asciiIO_t::scanI(T nBytes,string format)
{
	if(m_stat != ok_e ||!IsStatus4Read(this->m_mode))

	if(format=="%d")
	{
		fscanf(m_fp,"%d",nBytes);
	}

	else if(format=="%f")
	{
		fscanf(m_fp,"%f",nBytes);
	}
}
