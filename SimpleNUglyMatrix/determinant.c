#include "matrix.h"

int reverseordersum(int arr[], int n) {
	voidpointer(arr, __func__);
	int back = 0;
	int* arr_cmp = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; arr_cmp[i++] = 0);
	for (int i = 0, temp = 0; i < n; i++, temp = 0) {
		arr_cmp[arr[i]-1] = 1;
		int front = arr[i] - 1;
		int behind = n - arr[i];
		if (front <= behind) {
			for (int j = 0; j < front; j++)
				if (arr_cmp[j])
					temp++;
			back += front - temp;
		} 
		else {
			for (int j = n - 1; j > arr[i] - 1; j--)
				if (arr_cmp[j])
					temp++;
			back += front - i + temp;
		}
	}
	return back;
}
//逆序和

void traverse(int arr[], int n) {
	voidpointer(arr, __func__);
	for (int i = 0; i < n; arr[i++] = i + 1);
}
//顺序列数

void swap(int* e1, int* e2) {
	voidpointer(e1, __func__);
	voidpointer(e2, __func__);
	int ex = *e1;
	*e1 = *e2, * e2 = ex;
}
//值互换

void permutation(int arr[], int n, double * back, Matrix * T) {
	voidpointer(arr, __func__);
	voidpointer(back, __func__);
	voidpointer(T, __func__);
	static int floor = 1;
	if (!floor)
		floor = 1;
	if (floor > n) {
		double ex = 1;
		for (int i = 0; i < n; i++) {
			ex *= T->mat[i][arr[i] - 1];
		}
		*back += (reverseordersum(arr, n) % 2) ? (-ex) : ex;
		floor--;
		return;
	}
	for (int i = 0; i <= n - floor; i++) {
		swap(&arr[floor - 1], &arr[floor - 1 + i]);
		floor++, permutation(arr, n, back, T);
		swap(&arr[floor - 1], &arr[floor - 1 + i]);
	}
	floor--;
}
//全排列

double DeterminantMatrix(Matrix* T) {
	voidpointer(T, __func__);
	if (T->row != T->col)
		return EOF;
	else {
		double back = 0.0;
		int* arr = (int*)malloc(sizeof(int) * T->row);
		traverse(arr, T->row);
		permutation(arr, T->row, &back, T);
		free(arr);
		return back;
	}
}
//矩阵行列式