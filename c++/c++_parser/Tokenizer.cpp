#include "TokenizerH.h"

string Tokenizer_t::delimiters = "(){}[];<>=+-;*&, \t\n\f\v\r";

Tokenizer_t::Tokenizer_t(){};

Tokenizer_t::~Tokenizer_t()
{
	m_tokens.clear();
}

vector<string>& Tokenizer_t::getTokens(string& line) 
{
	size_t previous = 0;
	size_t current = line.find_first_of(delimiters);
	while(current!=string::npos)
	{
		if(line.substr(previous,current-previous).size()!=0)
			m_tokens.push_back(line.substr(previous,current-previous));
		if(isspace(line[current])==0)
			m_tokens.push_back(string(1,line[current]));

		previous = current+1;
		current = line.find_first_of(delimiters,previous);
	}

	if(isspace(line[current])==0)
		m_tokens.push_back(line.substr(previous,current-previous));
	return m_tokens;
}

const string& Tokenizer_t::getDeli()
{
	return delimiters;
}

void Tokenizer_t::setDeli(const string& deli)
{
	delimiters = deli;
}
