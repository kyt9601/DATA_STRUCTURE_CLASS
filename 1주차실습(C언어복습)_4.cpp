#include<stdio.h>
#include <string.h>

int main()
{
	int i, j;
	int str_len;

	char str[101];
	char t;

	scanf("%s",str);
	puts(str);

	str_len = strlen(str);

	for (i=0; i<str_len-1; i++)
	{
		t = str[0];

		for (j=0; j<str_len-1; j++)
		{
			str[j] = str[j+1];
		}

		str[str_len-1] = t;

		puts(str);
	}

	return 0;
}