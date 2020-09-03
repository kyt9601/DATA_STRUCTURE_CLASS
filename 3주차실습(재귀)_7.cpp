#include<stdio.h>
#include <string.h>

int CharCount(char *str, int length, char ch, int count);

int main()
{
	char ch;
	char str[101];

	scanf("%s",str);
	getchar();

	scanf("%c",&ch);

	printf("%d\n",CharCount(str,strlen(str),ch,0));

	return 0;
}

int CharCount(char *str, int length, char ch, int count)
{
	if (!length)
		return count;
	
	if (str[length-1] == ch)
		count++;

	return CharCount(str,length-1,ch,count);
}