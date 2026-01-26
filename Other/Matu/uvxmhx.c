#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int cube(int a)
{
	return a * a * a;
}

int find(int n)
{
	if (n < 100 || n >= 1000)
		return 0;
	int count = 0;
	for (int i = 100; i <= n; i++)
	{
		int n3 = i / 100;
		int n2 = i / 10 % 10;
		int n1 = i % 10;
		if (cube(n1) + cube(n2) + cube(n3) == i)
			count++;
	}
	return count;
}

int main()
{
	int n = 0;
	if (scanf("%d", &n) != 1)
	{
		printf("%d", 0);
		return -1;
	}
	printf("%d", find(n));

	return 0;
}