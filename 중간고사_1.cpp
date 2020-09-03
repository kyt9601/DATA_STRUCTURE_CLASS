#include <stdio.h>
#include <string.h>

int checkCh(char *start, char *end, char ch);

int main()
{
	char str[101];
	char ch;

	scanf("%s",str);
	getchar();
	scanf("%c",&ch);

	printf("%d\n",checkCh(str,str+strlen(str)-1,ch));

	return 0;
}

int checkCh(char *start, char *end, char ch)
{
	if (start == end)
		return *start==ch ? 1 : 0;

	return checkCh(start,start+(end-start)/2,ch) + checkCh(start+(end-start)/2+1,end,ch);
}