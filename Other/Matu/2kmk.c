#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	unsigned int m = 0, k = 0;
	if (scanf("%u", &m) != 1)
		return -1;
	unsigned med = 1;
	if (m == 1)
		printf("%u", k);
	else
	{
		for (k; med <= m && k <= 31; k++)
			med <<= 1;
		printf("%u", --k);
	}
	return 0;
}