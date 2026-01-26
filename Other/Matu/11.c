#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int gr_co_div(int x, int y)
{
	int back = 1;
	for (int i = 1; i <= x && i <= y; i++)
		if (!(x % i) && !(y % i))
			back = i;
	return back;
}

int le_co_mul(int x, int y, int grcodiv)
{
	return x * y / grcodiv;
}

int main()
{
	int x = 0, y = 0;
	scanf("%d %d", &x, &y);
	int grcodiv = gr_co_div(x, y);
	printf("%d,%d", grcodiv, le_co_mul(x, y, grcodiv));
	return 0;
}