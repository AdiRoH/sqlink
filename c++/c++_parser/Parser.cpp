#include "TokenizerH.h"
#include "AnalizerH.h"
#include "ParserH.h"

Parser_t::~Parser_t()
{
	m_token.clear();
	delete tn;
	delete an;
}
		
Parser_t::Parser_t()
{
	tn = new Tokenizer_t;
	an = new Analizer_t;
	m_numLine = 0;
}

void Parser_t::parse(const char* fileName)
{
	//check what happend if EOF
	fstream fs;
	fs.open(fileName,fstream::in);

	if(fs.fail()) throw("can't read file\n");
	m_numLine++;
	getline(fs, m_Line);
	m_token = tn->getTokens(this->m_Line);
	an->checkBrackets(this->m_Line);
	fs.close();
}