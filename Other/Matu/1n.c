#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	int n = 0, res = 1;
	scanf("%d", &n);
	for (int i = 0; i < 5; i++)
	{
		printf("%d", res *= n);
		if (i < 4)
			printf(" ");
	}
	printf("\n");
	return 0;
}