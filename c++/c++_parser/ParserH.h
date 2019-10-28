#ifndef ParserH
#define ParserH

	#include <string>
	#include <cstdio>
	#include <iostream>
	#include <fstream>
	#include <queue>

	using namespace std;
	class Tokenizer_t;
	class Analizer_t;

	class Parser_t
	{
	public:

		Parser_t();
		~Parser_t();
		
		void parse(const char* fileName);
		

	private:
		int m_numLine;
		string m_Line;
		Analizer_t* an;
		Tokenizer_t* tn;
		vector<string> m_token;
		
	};


#endif