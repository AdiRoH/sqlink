#ifndef AnalizerH
#define AnalizerH

	#include <string>
	using namespace std;

	class Analizer_t
	{
	public:
		~Analizer_t(){};
		Analizer_t();
		void checkBrackets(const string& TokensLine);

		//forbid copy ctor
		//only 2 functions besides ctor,dtor


	private:
		int m_bracket;
		int m_closure;
		int m_pointy;
		int m_currBrackets;
		

	};



#endif