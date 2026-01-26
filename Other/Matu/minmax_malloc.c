#include <stdio.h>

int main()
{
	int sz = 0;
	if (scanf("%d", &sz) != 1 || sz <= 0)
	{
		printf("error");
		return -1;
	}
	int *arr = (int)malloc(sizeof (int) * sz);
	for (int i = 0; i < sz; i++)
		scanf("%d", &arr[i]);
	int *min = &arr[0], *max = &arr[0];
	for (int i = 0, *p = &arr[0]; i < sz; i++)
		p = *p > arr[i] ? p : &arr[i];
	