#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

void traverse(int arr[], int n) {
	for (int i = 0; i < n; arr[i++] = i + 1);
}

void swap(int *e1, int *e2) {
	int ex = *e1;
	*e1 = *e2, * e2 = ex;
}

void permutation(int arr[], int n) {
	static floor = 1;
	if (floor > n) {
		for (int i = 0; i < n; printf("%d", arr[i++]));
		printf("\n");
		floor--;
		return;
	}
	for (int i = 0; i <= n - floor; i++) {
		swap(&arr[floor - 1], &arr[floor - 1 + i]);
		floor++, permutation(arr, n);
		swap(&arr[floor - 1], &arr[floor - 1 + i]);
	}
	floor--;
}
