#define _CRT_SECURE_NO_WARNINGS 1

#include "Functions.h"

int main()
{
	int ti = 0;
	int ba = 0;
	printf("Press any key to start >>");
ft_me:
	while (getchar() != '\n')
		system("cls");
	switch (ba = menu(ti))
	{
	case 0:
		ba = debug();
		break;
	case 1:
		ba = game();
		break;
	case 2:
		break;
	default:
		Fault(ba);
		goto ft_me;
		break;
	}
	Fault(ba);
	return ba;
}