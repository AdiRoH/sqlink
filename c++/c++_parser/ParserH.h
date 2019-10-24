#ifndef ParserH
#define ParserH

	#include <string>
	#include <cstdio>
	#include <iostream>
	#include <fstream>

	using namespace std;
	class Parser_t
	{
	public:

		Parser_t();
		Parser_t(const string& fileName)
		{
			m_fileName = fileName;
			m_numLine = 0;
		}

		~Parser_t(){};
		
		void getfunc()
		{
			//check what happend if EOF
			fstream fs;
			fs.open(m_fileName.c_str(),fstream::in);
			if(fs.fail()) throw("can't read file\n");
			m_numLine++;
			getline(fs, m_Line);
			fs.close();
		}

	private:
		int m_numLine;
		string m_Line;
		string m_fileName;
		
	};


#endif