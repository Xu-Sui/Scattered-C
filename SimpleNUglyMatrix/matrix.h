#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <assert.h>

#define RANDTOP 50

typedef struct {
	double** mat;
	int row, col;
}Matrix;
//结构体定义矩阵

void InitialMatrixRowCol(Matrix* T);
void InitialMatrix(Matrix* T);
void InitialMatrixZero(Matrix* T);
void InitialMatrixRand(Matrix* T);
void InputMatrix(Matrix* T);
void DestroyMatrix(Matrix* T);

void PrintMatrix(Matrix* T);
int AddMatrix(Matrix* A, Matrix* B, Matrix* Res);
int MinusMatrix(Matrix* A, Matrix* B, Matrix* Res);
int MultiMatrix(Matrix* A, Matrix* B, Matrix* Res);
double MeanMatrix(Matrix* T);
int SubMatrix(Matrix* T, Matrix* S);
double MinorMatrix(Matrix* T, Matrix* M, int* xy);
double MaxMatrix(Matrix* T);
void TransMatrix(Matrix* T);
void NormMatrix(Matrix* T);
void ReverseMatrix(Matrix* A, Matrix* B);

int reverseordersum(int arr[], int n);
void traverse(int arr[], int n);
void swap(int* e1, int* e2);
void permutation(int arr[], int n, double* back, Matrix* T);
double DeterminantMatrix(Matrix* T);

void voidpointer(void* p, char funcname[]);
