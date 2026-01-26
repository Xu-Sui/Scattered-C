#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	int Cel = 0, Fah = 0;
	if (scanf("%d", &Cel) != 1)
		return -1;
	Fah = (int)(1.8 * Cel) + 32;
	printf("%d", Fah);
	return 0;
}