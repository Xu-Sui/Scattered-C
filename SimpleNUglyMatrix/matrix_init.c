#define _CRT_SECURE_NO_WARNINGS 1
#include "matrix.h"

void InitialMatrixRowCol(Matrix* T) {
	voidpointer(T, __func__);
	printf("row = ");
	scanf("%d", &T->row);
	printf("col = ");
	scanf("%d", &T->col);
}

void InitialMatrix(Matrix* T) {
	voidpointer(T, __func__);
	if ((T->mat = (double**)malloc(sizeof(double*) * T->row)) == NULL)
		printf("Not enough space!");
	for (int i = 0; i < T->row; assert(T->mat[i]), i++)
		if ((T->mat[i] = (double*)malloc(sizeof(double) * T->col)) == NULL) {
			printf("Not enough space!");
			break;
		}
}
//内存初始化

void InitialMatrixZero(Matrix* T) {
	voidpointer(T, __func__);
	for (int i = 0; i < T->row; i++)
		for (int j = 0; j < T->col; j++)
			T->mat[i][j] = 0.0;
}
//零矩阵初始化

void InitialMatrixRand(Matrix* T) {
	voidpointer(T, __func__);
	srand((unsigned int)time(NULL));
	for (int i = 0; i < T->row; i++)
		for (int j = 0; j < T->col; j++)
			T->mat[i][j] = rand() % RANDTOP + 1;
}
//随机矩阵初始化

void InputMatrix(Matrix* T) {
	voidpointer(T, __func__);
	printf("input the elements in order please >>\n");
	for (int i = 0; i < T->row; i++)
		for (int j = 0; j < T->col; j++)
			assert(scanf("%lf", &T->mat[i][j]) != 1);
}
//矩阵输入

void DestroyMatrix(Matrix* T) {
	free(T->mat), T->row = 0, T->col = 0;
}
//内存销毁