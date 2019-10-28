#include <iostream>
#include "AnalizerH.h"
using namespace std;

Analizer_t::Analizer_t()
{
	m_bracket = 0;
	m_closure = 0;
	m_pointy = 0;
	m_currBrackets = 0;
}

void Analizer_t::checkBrackets(const string& TokensLine) 
{
	int i=0;
	char c;
  	while (TokensLine[i])
  	{
  		c = TokensLine[i];
	
		if(((c=='<')&&(m_pointy==0))||(c=='>'&&(m_pointy==1)))
		{
			this->m_pointy = 1;
		} 
		else if(c=='<'&&m_pointy==1||c=='>'&&m_pointy==0)
		{
			cout<<"error in pointy!"<<endl;
			this->m_pointy = 0;
		}
		
		if((c=='['&& m_bracket==0)||(c==']'&&m_bracket==1)) 
		{
			this->m_pointy = 1;
		}
		else if((c=='['&&m_bracket==1)||(c==']'&&m_bracket==0))
		{
			cout<<"error in brackets!"<<endl;
			this->m_pointy = 0;
		}

	

		if((c=='{'&& m_currBrackets==0)||(c=='}'&&m_currBrackets==1)) this->m_pointy = 1;
		else if(c=='{'&&m_currBrackets==1||c=='}'&&m_currBrackets==0)
		{
			cout<<"error in currly brackets!"<<endl;
			this->m_pointy = 0;
		}		



		if((c=='('&&m_closure==0)||(c==')'&&m_closure==1)) this->m_pointy = 1;
		else if(c=='('&&m_closure==1||c==')'&&m_closure==0)
		{
			cout<<"error in closure!"<<endl;
			this->m_pointy = 0;
		}

   		
   		
   		i++;
 	}
  

}