#include "matrix.h"

void PrintMatrix(Matrix* T) {
	for (int i = 0; i < T->row; i++, printf("\n"))
		for (int j = 0; j < T->col; j++, printf("\t"))
			printf("%lf", T->mat[i][j]);
}
//矩阵打印输出

int AddMatrix(Matrix* A, Matrix* B, Matrix* Res) {
	if (A->row != B->row || A->col != B->col)
		return 0;
	Res->row = A->row, Res->col = A->col;
	InitialMatrix(Res), InitialMatrixZero(Res);
	for (int i = 0; i < Res->row; i++)
		for (int j = 0; j < Res->col; j++)
			Res->mat[i][j] = B->mat[i][j] + A->mat[i][j];
	return 1;
}
//矩阵加法

int MinusMatrix(Matrix* A, Matrix* B, Matrix* Res) {
	Matrix C = *B;
	for (int i = 0; i < C.row; i++)
		for (int j = 0; j < C.row; j++)
			C.mat[i][j] = -C.mat[i][j];
	return AddMatrix(A, &C, Res);
}
//矩阵减法

int MultiMatrix(Matrix* A, Matrix* B, Matrix* Res) {
	voidpointer(A, __func__);
	voidpointer(B, __func__);
	voidpointer(Res, __func__);
	if (A->col != B->row)
		return 0;
	Res->row = A->row, Res->col = B->col;
	InitialMatrix(Res), InitialMatrixZero(Res);
	for (int i = 0; i < A->row; i++)
		for (int j = 0; j < B->col; j++)
			for (int k = 0; k < A->col; k++)
				Res->mat[i][j] += A->mat[i][k] * B->mat[k][j];
	return 1;
}
//矩阵乘法

double MeanMatrix(Matrix* T) {
	voidpointer(T, __func__);
	double res = 0;
	for (int i = 0; i < T->row; i++)
		for (int j = 0; j < T->col; j++)
			res += T->mat[i][j];
	return res /= T->row * T->col;
}
//矩阵元素均值

int SubMatrix(Matrix* T, Matrix* S) {
	voidpointer(T, __func__);
	voidpointer(S, __func__);
	int xy_sz[2] = { 0 };
	printf("Chosen rows number>> "), scanf("%d", &xy_sz[0]);
	printf("Chosen cols number>> "), scanf("%d", &xy_sz[1]);
	int* xy[2];
	for (int i = 0; i < 2; i++) {
		xy[i] = (int*)malloc(sizeof(int) * xy_sz[i]);
		for (int j = 0; j < xy_sz[i]; xy[i][j++] = 0);
	}
	S->row = xy_sz[0], S->col = xy_sz[1];
	printf("Chosen rows >> \n");
	for (int i = 0; i < xy_sz[0]; i++)
		scanf("%d", &xy[0][i]);
	printf("Chosen cols >> \n");
	for (int j = 0; j < xy_sz[1]; j++)
		scanf("%d", &xy[1][j]);
	InitialMatrix(S), InitialMatrixZero(S);
	for (int i = 0; i < xy_sz[0]; i++)
		for (int j = 0; j < xy_sz[1]; j++)
			S->mat[i][j] = T->mat[xy[0][i] - 1][xy[1][j] - 1];
	for (int i = 0; i < 2; i++)
		free(xy[i]);
	return 1;
			
}
//子矩阵求取

double MinorMatrix(Matrix* T, Matrix* M, int* xy) {
	voidpointer(T, __func__);
	voidpointer(M, __func__);
	voidpointer(xy, __func__);
	M->row = T->row - 1, M->col = T->col - 1;
	InitialMatrix(M);
	int x = 0, y = 0;
	for (int i = 0; i < T->row; i++) {
		if (i == xy[0])
			continue;
		for (int j = 0; j < T->col; j++) {
			if (j == xy[1])
				continue;
			else {
				M->mat[x][y++] = T->mat[i][j];
				x += y / M->col, y %= M->col;
			}
		}
	}
	double det_M = DeterminantMatrix(M);
	return ((xy[0] + xy[1]) % 2) ? (-det_M) : det_M;
}
//余子式求取

double MaxMatrix(Matrix* T) {
	voidpointer(T, __func__);
	double res = T->mat[0][0];
	for (int i = 0; i < T->row; i++)
		for (int j = 0; j < T->col; j++)
			res = res > T->mat[i][j] ? res : T->mat[i][j];
	return res;
}
//矩阵最大元素

void TransMatrix(Matrix* T) {
	voidpointer(T, __func__);
	int ex = T->row;
	T->row = T->col;
	T->col = ex;
	double** nnew;
	nnew = (double**)malloc(sizeof(double*) * T->row);
	for (int i = 0; i < T->row; i++)
		nnew[i] = (double*)malloc(sizeof(double*) * T->col);
	for (int i = 0; i < T->row; i++)
		for (int j = 0; j < T->col; j++)
			nnew[i][j] = T->mat[j][i];
	T->mat = nnew;
}
//转置矩阵

void NormMatrix(Matrix* T) {
	voidpointer(T, __func__);
	double sum = 0.0;
	for (int j = 0; j < T->col; j++, sum = 0.0) {
		for (int i = 0; i < T->row; sum += (T->mat[i][j]) * (T->mat[i][j]), i++);
		for (int i = 0; i < T->row; T->mat[i++][j] /= sqrt(sum));
	}
}
//矩阵归一化

void ReverseMatrix(Matrix* A, Matrix* B) {
	voidpointer(A, __func__);
	voidpointer(B, __func__);
	if (A->row != A->col || DeterminantMatrix(A) == 0.0) {
		printf("No reverse!\n");
		return;
	}
	else {
		B->row = B->col = A->row;
		InitialMatrix(B);
		double det_A = DeterminantMatrix(A);
		for (int i = 0; i < A->row; i++)
			for (int j = 0; j < A->col; j++) {
				Matrix ex;
				int arr[2] = { i, j };
				B->mat[j][i] = MinorMatrix(A, &ex, arr) / det_A;
			}
	}
}
//逆矩阵