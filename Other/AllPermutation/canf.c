#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int weishu(int x) {
	static total = 1;
	if (x / 10)
		total++, weishu(x / 10);
	else
		return total;
}

int char_int(char* ex, int ex_sz) {
	int back = 0;
	for (int i = 0; i < ex_sz; i++)
		back += (ex[i] - '0') * (10 ^ i);
	return back;
}

int main() {
	int row = 5, col = 3;
	int** xy = (int**)malloc(sizeof(int*) * 2);
	xy[0] = (int*)malloc(sizeof(int) * row), xy[1] = (int*)malloc(sizeof(int) * col);
	int ex_sz = (weishu(row) > weishu(col)) ? weishu(row) : weishu(col);
	char* ex = (char*)malloc(sizeof(char) * ex_sz);
	for (int i = 0; i < ex_sz; ex[i++] = '0');
	for (int i = 0; i < ex_sz; )
		if (!isdigit(ex[i] = getchar())) {
			ex[i] = '0';
			break;
		}
}