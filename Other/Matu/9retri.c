#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	char star = '*';
	int bot_leng = 0;
	if (scanf("%d", &bot_leng) != 1 || bot_leng > 79 || bot_leng < 1 || bot_leng % 2 == 0)
		printf("error");
	else
	{
		for (int i = 1; i <= bot_leng; i += 2)
		{
			printf("%*c", (bot_leng - i) / 2 + 1, star);
			for (int j = 1; j < i; j++)
				printf("%c", star);
			printf("\n");
		}

	}
	return 0;
}