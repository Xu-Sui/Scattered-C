#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <ctype.h>

int main()
{
	char str[51] = { 0 };
	for (int i = 0; i < 51; i++)
		str[i] = '\0';
	fgets(str, 50, stdin);
	for (int i = 0; i < 50 && str[i] != '\0'; i++)
	{
		if (isalnum(str[i]) || isalpha(str[i]))
			continue;
		else
			for (int j = 1; str[i] == str[i + j]; j++)
				str[i + j] = '\n';
	}
	for (int i = 0; i < 51 && str[i] != '\0'; i++)
	{
		if (str[i] == '\n')
			continue;
		else
			printf("%c", str[i]);
	}
	return 0;
}