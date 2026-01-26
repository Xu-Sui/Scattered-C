#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int fac(int num)
{
	int back = 1;
	for (; num > 1; num--)
		back *= num;
	return back;
}

int fac_sum(int last)
{
	int sum = 0;
	for (int i = 1; i <= last; i++)
		sum += fac(i);
	return sum;
}

int main()
{
	int last = 0;
	if (scanf("%d", &last) != 1 || last > 10 || last < 1)
		printf("error");
	else
		printf("%d\n", fac_sum(last));
	return 0;
}