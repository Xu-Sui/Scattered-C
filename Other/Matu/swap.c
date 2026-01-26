#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

void swap(int* array, int n)
{
	if (n < 1)
	{
		printf("error");
		return;
	}
	for (int i = 0; i < n; i++)
		if (array + i == NULL)
		{
			printf("error");
			return;
		}
	int ex = *array;
	*array = array[n-1];
	array[n-1] = ex;
}

int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	swap(arr, sz);
	//for (int i = 0; i < sz; i++)
	//	printf("%d\t", arr[i]);
	return 0;
}