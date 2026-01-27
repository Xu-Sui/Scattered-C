#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* KMP(const char* str, const char* pattern) {
	//NEXT
	int* next = (int*)calloc(strlen(pattern), sizeof(int));
	next[0] = 0;
	for (int i = 1, j = 0; pattern[i] != '\0';) {
		while (j > 0 && pattern[i] != pattern[j])
			j = next[j - 1];
		(pattern[i] == pattern[j]) ? (next[i++] = ++j) : (j == 0 ? i++ : 0);
	}
	
	//print NEXT
	printf("next >> ");
	for (int i = 0; i < strlen(pattern); printf("%-2d", next[i++]));
	printf("\n");

	//MATCH
	for (int i = 0, j = 0; str[i] != '\0'; i++) {
		while (j > 0 && str[i] != pattern[j])
			j = next[j - 1];
		if (str[i] == pattern[j])
			if ((++j) == strlen(pattern)) {
				free(next);
				return str + i - j + 1;
			}
	}
	free(next);
	return NULL;
}

//test space
int main() {
	char str[50] = { 0 };
	printf("str >> ");
	scanf("%s", str);
	char pattern[50] = { 0 };
	printf("pattern >> ");
	scanf("%s", pattern);
	
	char* n;
	n = KMP(str, pattern);
	printf("%s", n);
	return 0;
}