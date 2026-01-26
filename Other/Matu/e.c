#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

double fac(int num)
{
	double back = 1.0;
	if (!num)
		return 1.0;
	for (int i = 1; i <= num; i++)
		back *= i;
	return back;
}

double pw(double x, int y)
{
	double back = 1.0;
	if (!x)
		return 1.0;
	for (int i = 1; i<= y; i++)
		back *= x;
	return back;
}

double e_x(double x, double n)
{
	double back = 0;
	if (!x)
		return 1.0;
	for (int i = 0; i <= n; i++)
		back += pw(x, i) / fac(i);
	return back;
}

int main()
{
	double x, n;
	if (scanf("%lf %lf", &x, &n) != 2 || n <= 0)
		printf("error");
	else
		printf("%.6lf\n", e_x(x,n));
		//printf("%lf\n", pw(x, (int)n));
	return 0;
}