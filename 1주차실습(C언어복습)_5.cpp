#include<stdio.h>

int main()
{
	int h1, m1, s1;
	int h2, m2, s2;
	int h, m, s;

	scanf("%d %d %d",&h1,&m1,&s1);
	scanf("%d %d %d",&h2,&m2,&s2);

	h= h2 - h1;
	m = m2 - m1;
	s = s2 - s1;

	if (s < 0)
	{
		m--;
		s += 60;
	}

	if (m < 0)
	{
		h--;
		m += 60;
	}

	printf("%d %d %d\n",h,m,s);

	return 0;
}