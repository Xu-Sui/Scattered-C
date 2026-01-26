#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	int a = 0, b = 0, c = 0;
	scanf("%d,%d,%d", &a, &b, &c);
	if (a <= 0 || b <= 0 || c <= 0)
		printf("error");
	else
	{
		if (a + b <= c || a + c <= b || b + c <= a)
			printf("no");
		else
			printf("yes");
	}
	return 0;
}