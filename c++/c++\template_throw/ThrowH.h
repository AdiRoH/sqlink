#ifndef ThrowH
#define ThrowH

	#include <string>
	#include <string.h>
	#include <iostream>

	using namespace std;
	template <class TID>

	class  TException_t 
	{
		public:
			~TException_t(){}
			TException_t(const string& mes, const string& fileN,  int lineNumber, TID VarThrow)
			{
				m_throwMessage=mes ;
				m_fileName = fileN;
				m_lineNum = lineNumber;
				m_varThrow = VarThrow;
			}

			TException_t(const TException_t<TID>& Texcp)
			{
				Texcp.m_throwMessage = m_throwMessage;
				Texcp.m_fileName = m_fileName;
				Texcp.m_lineNum = m_lineNum;
				Texcp.m_varThrow = m_varThrow;
			}  

			

			const string& getMessage() const{return m_throwMessage;};
			const string& getFileName() const{return m_fileName;};
			const int& getLineNum() const{return m_lineNum;};
			const TID& getVarThrow() const{return m_varThrow;};

	
		private:
			string m_throwMessage;
			string m_fileName;
			int m_lineNum;
			TID m_varThrow;

			TException_t<TID>& operator=(const TException_t<TID>& Texcp){};

	};


#endif