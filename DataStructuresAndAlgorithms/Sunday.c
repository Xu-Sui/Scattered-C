#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR UCHAR_MAX + 1

char* Sunday(char* str, char* pattern) {
	size_t sz = strlen(pattern);
	size_t sz_str = strlen(str);
	
	int shift[MAX_CHAR];
	for (int i = 0; i < MAX_CHAR; i++)	shift[i] = sz + 1;
	for (int i = 0; i < sz; i++)		shift[(unsigned char)pattern[i]] = sz - i; //negative char

	for (int i = 0, j = 0; i <= sz_str - sz; ) { //the out-of-bounds access neglect && the range of i
		for (j = 0; pattern[j] != '\0'; j++)
			if (pattern[j] != str[i + j]) {
				i += shift[(unsigned char)str[i + sz]];
				break;
			}
		if (pattern[j] == '\0')
			return str + i;
		if (i + sz > sz_str) //the same
			break;
	}
	return NULL;
}

int main() {

	//function test
	char str[50] = { 0 };
	char pattern[50] = { 0 };
	printf("str >> ");
	scanf("%s", str);
	printf("pattern >> ");
	scanf("%s", pattern);
	printf("Match Place >> %s\n", Sunday(str, pattern));
	return 0;
}