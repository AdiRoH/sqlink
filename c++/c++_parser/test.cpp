#include "ParserH.h"
//#include "TokenizerH.h"
//#include "AnalizerH.h"

int main(int argc,char* argv[])
{
	int i=0;
	for(i=0;i<argc;i++)
	{
		Parser_t pr(argv[i]);
		pr.getfunc();
	}

	return 0;
}