#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>

int main()
{
	int inp = 0;
	int exi = 1;
	if (scanf("%d", &inp) != 1 || inp <= 3 || inp > 2147483647)
	{
		printf("error");
		return -1;
	}
	else
	{
		int top = (int)sqrt((double)inp);
		for (int i = 2; i <= top; i++)
		{
			if (inp % i == 0)
			{
				exi = i;
				break;
			}
		}
		if (exi == 1)
			printf("yes");
		else
			printf("no");
	}
	return 0;
}