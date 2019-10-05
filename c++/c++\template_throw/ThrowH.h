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
			TException_t(string mes,string fileN,int lineNumber,TID VarThrow)
			{
				mes = throwMessage;
				fileName = fileN;
				lineNum = lineNumber;
				varThrow = VarThrow;
			};

			TException_t(TException_t<TID>& Texcp)
			{
				Texcp.throwMessage = throwMessage;
				Texcp.fileName = fileName;
				Texcp.lineNum = lineNum;
				Texcp.varThrow = varThrow;
			};

			TException_t<TID>& operator=(TException_t<TID>& Texcp)
			{
				if(Texcp->throwMessage!=throwMessage || Texcp->fileName!=fileName || Texcp->lineNum!=lineNum || Texcp!=varThrow)
				{
					throwMessage = Texcp->throwMessage;
					fileName = Texcp->fileName;
					lineNum = Texcp->lineNum;
					varThrow = Texcp->varThrow;
				}
				return *this;
			};

			const string& getMessage() const{return throwMessage;};
			const string& getFileName() const{return fileName;};
			const int& getLineNum() const{return lineNum;};
			const TID& getVarThrow() const{return varThrow;};

			void setMessage(string throwMes){throwMessage = throwMes;};
			void setFileName(string fileN){fileName = fileN;};
			void setlineNum(int nLine){lineNum = nLine;};
			void setVarThrow(TID VarThrow){varThrow = VarThrow;};

		private:
			string throwMessage;
			string fileName;
			int lineNum;
			TID varThrow;

	};


#endif