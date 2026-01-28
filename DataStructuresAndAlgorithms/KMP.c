#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* KMP(const char* str, const char* pattern) {
	int sz = strlen(pattern);

	//NEXT
	int* next = (int*)calloc(sz, sizeof(int));
	next[0] = 0;
	for (int i = 1, j = 0; pattern[i] != '\0';) {
		while (j > 0 && pattern[i] != pattern[j])
			j = next[j - 1];
		(pattern[i] == pattern[j]) ? (next[i++] = ++j) : (j == 0 ? i++ : 0);
	}
	
	//print NEXT
	printf("next >> ");
	for (int i = 0; i < sz; printf("%-2d", next[i++]));
	printf("\n");

	//NEXTVAL
	int* nextval = (int*)calloc(sz, sizeof(int));
	for (int i = 1; pattern[i] != '\0'; i++) {
		if (next[i - 1] > 0 && pattern[i] == pattern[next[i - 1]])
			nextval[i - 1] = nextval[next[i - 1] - 1];
		else
			nextval[i - 1] = next[i - 1];
	}
	nextval[sz - 1] = 0;

	//print NEXTVAL
	printf("nextval >> ");
	for (int i = 0; i < sz; printf("%-2d", nextval[i++]));
	printf("\n");

	//MATCH
	for (int i = 0, j = 0; str[i] != '\0'; i++) {
		if (j > 0 && str[i] != pattern[j])
			j = nextval[j - 1];
		if (str[i] == pattern[j])
			if ((++j) == sz) {
				free(next), free(nextval);
				return str + i - j + 1;
			}
	}
	free(next), free(nextval);
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