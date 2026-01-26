#define LEN 9
#define MINE 30
#define NUM (int)(LEN * LEN / MINE)

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int menu(int times)
{
	int ch = 0;
	printf("                                        \n");
	if(times)
		printf("       1.again           2.exit         \n");
	else
		printf("       1.start           2.exit         \n");
	printf("                                        \n");
	printf("Please type your choice >> ");
	if (scanf("%d", &ch) != 1)
		return 20;
	else if (ch != 1 && ch != 2 && ch != 0)
		return 21;
	else
		return ch;
}

void Fault(int const fcode)
{
	switch (fcode)
	{
	case -1:
		//mine digged
		printf("Look out, MINE!\n");
	case 0:
		//safe run
		break;
	case 20:
		//menu type form error
		printf("Type correct form!\n");
		break;
	case 21:
		//menu type number error
		printf("Type correct number\n");
		break;
	}
	//printf("Press any key to exit >> ");
	//while (getchar() != '\n')
	//	;
}

void init_sur(char sur[LEN + 1][LEN + 1], int const len)
{
	for (int i = 0; i <= len; i++)
	{
		for (int j = 0; j <= len; j++)
		{
			if (!i && j)
				sur[i][j] = j + '0';
			else if (i && !j)
				sur[i][j] = i + '0';
			else if (!i && !j)
				sur[i][j] = ' ';
			else
				sur[i][j] = '#';
		}
	}
}

void init_in(char in[LEN][LEN], int const len, int mine)
{
	srand((unsigned int)time(NULL));
remain:
	mine = MINE;
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < len; j++)
		{
			in[i][j] = '0';
			if (mine > 0 && rand() % 3 % 2)
			{
				mine--;
				in[i][j] = '1';
			}
		}
	}
	if (mine)
		goto remain;
}

void dis_in(char const in[LEN][LEN], int const len)
{
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < len; j++)
		{
			printf(" %c ", in[i][j]);
		}
		printf("\n");
	}
}

void dis_sur(char const sur[LEN + 1][LEN + 1], int const len)
{
	system("cls");
	for (int i = 0; i <= len; i++)
	{
		if (!i)
		{
			for (int j = 0; j <= len; j++)
				printf("  %c ", sur[i][j]);
			printf(" ");
		}
		else
		{
			int j = 0;
			printf("  %c |", sur[i][j]);
			for (j = 1; j <= len; j++)
				printf(" %c |", sur[i][j]);
		}
		printf("\n    -");
		for (int j = 0; j < len; j++)
			printf("----");
		printf("\n");
	}
}

/*
	      1   2
		---------
	  1 | # | # |
	    ---------
	  2 | # | # |
	    ---------
*/

int dig(char sur[LEN + 1][LEN + 1], char const in[LEN][LEN], int const len, int x, int y)
{
	if (in[y - 1][x - 1] == '1')
	{
		sur[y][x] = '*';
		return -1;
	}
	else
	{
		int count = 0;
		x -= 2, y -= 2;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (x + j < 0 || y + i < 0 || x >= len || y >= len)
					;
				else
				{
					if (in[y + i][x + j] == '1')
						count++;
				}
			}
		}
		x += 2, y += 2;
		if (count == 0)
			sur[y][x] = ' ';
		else
			sur[y][x] = '0' + count;
		return 1;
	}
}

void rest_dis(char sur[LEN + 1][LEN + 1], char in[LEN][LEN], int len)
{
	for (int i = 1; i <= len; i++)
	{
		for (int j = 1; j <= len; j++)
		{
			if (sur[j][i] == '#')
				dig(sur, in, len, i, j);
		}
	}
}

//int set_back(char sur[LEN + 1][LEN + 1], char in[LEN][LEN], int x, int y, int len)
//{
//
//}

int game()
{
	char sur[LEN + 1][LEN + 1] = { 0 };
	char in[LEN][LEN] = { 0 };
	int res = 0;
	init_sur(sur, LEN);
	init_in(in, LEN, MINE);

	for (int i = 0; i < LEN * LEN; i++)
	{
		dis_sur(sur, LEN);
		int x = 0, y = 0;
		printf("Please type your coordination >> \n");
		printf("x = ");
		scanf("%d", &x);
		printf("y = ");
		scanf("%d", &y);
		if (res = dig(sur, in, LEN, x, y), res == -1)
		{
			rest_dis(sur, in, LEN);
			dis_sur(sur, LEN);
			break;
		}
	}
	return res;
}

int debug()
{
	char sur[LEN + 1][LEN + 1] = { 0 };
	char in[LEN][LEN] = { 0 };
	init_sur(sur, LEN);
	init_in(in, LEN, MINE);
	dis_sur(sur, LEN);
	dis_in(in, LEN);
	return 0;
}