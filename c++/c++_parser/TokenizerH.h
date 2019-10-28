#ifndef TokenizerH
#define TokenizerH
	
	#include <queue>
	#include <string>
	using namespace std;

	class Tokenizer_t
	{
		public:
			Tokenizer_t();
			~Tokenizer_t();
			
			
			vector<string>& getTokens(string& line); 

		
			static const string& getDeli();
			static void setDeli(const string& deli);

		private:
			static string delimiters;
			vector<string> m_tokens;
			//forbid copy CTOR and assign
	};



#endif 