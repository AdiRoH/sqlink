#include "ParserH.h"
#include "TokenizerH.h"


int main(int argc,char* argv[])
{
	int i=1;
	for(i=1;i<argc;i++)
	{
		Parser_t pr;
		pr.parse(argv[i]);
	}

	return 0;
}