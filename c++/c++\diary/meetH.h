#ifndef meetH
#define meetH

	using namespace std;
	#include <string>

	class Meet_t
	{
	public:
		Meet_t(){};
		~Meet_t(){};
		const float& getBegin()const{return m_begin;}
		const float& getEnd()const{return m_end;}
		const string& getSubject()const{return m_subject;}
		bool setBegin(const float& begin);
		bool setEnd(const float& end);
		void setSubject(const string& subject){m_subject=subject;}

	private:
		/*
		Meet_t& operator=(const Meet_t& meet);	
		Meet_t(const Meet_t& meet);
		*/
	

		float m_begin;
		float m_end;
		string m_subject;
		bool isValidHour(const float& hour){return (hour<0||hour>24)?false:true;} 
		
	};

#endif