#include<stdio.h>
#include<string.h>

int cmpStr(char *str1,char *str2);
void cpyStr(char *str1,char *str2, int size2);
void catStr(char* strDst,char* strSrc);

int main()
{
	char str1="baloon",str2="Baloon",str3="is round";
	int res;
	
	res=cmpStr(str1,str2);
	printf("The 2 strings are: %s %s\n and the results are:\t%d\n",str1,str2,res);
	
	printf("The 2 strings are:\t%s\t%s\n",str3,str2);
	cpyStr(str3,str2,7);
	printf("The copied str is:\t%s\n",str3);
	
	catStr(str3,str1);
	printf("%s\n",str3);
	return 0;

}


int cmpStr(char *str1,char *str2)
{
	int counter=0,i=0,j=0;
	do
	{
		if(arr[i]>=arr[j])
		{
			counter=1;			
			break;
		}
		else if(arr[i]<=arr[j])
		{
			counter=-1;			
			break;
		}

		if(str1[i]=='0'||str2[j]=='0')
		{
			break;
		}
		
		i++;
		j++;
		
	}while(str1[i]==str2[j])
	
	if(counter==0 and i=='0')
		counter=-1;
	else if(counter==0 and j=='0')
		counter=1;

	return counter;
}

void cpyStr(char *str1,char *str2, int size2)
{
	int i;
	for(i=0;i<size2;i++)
	{
		str2[i]==str1[i];
	}
	str2[size2-1]='0';
}

void catStr(char* strDst,char* strSrc)
{
	int sizeSrc=strlen(strSrc),sizeDst=strlen(strDst),i;
	for(i=sizeSrc;i<=sizeDst;i++)
	{
		strDst[i]==strSrc[i];
	}
	strDst[sizeDst+1]='0';
}

