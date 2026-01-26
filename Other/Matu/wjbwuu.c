#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

int cmp_arr(const void* e1, const void* e2)
{
	return *(int*)e1 - *(int*)e2;
}

void find(int n)
{
	for (int ti = 2; ti <= n; ti++)
	{
		int arr[173] = { 0 };
		arr[0] = 1;
		int count = 1, sum = 1;
		for (int i = 2; i * i <= ti; i++)
			if (!(ti % i))
			{
				if (i * i == ti)
					sum += (arr[count] = i);
				else
					sum += (arr[count++] = i), sum += (arr[count++] = ti / i);
			}
		if (sum != ti)
			continue;
		int sz = count;
		qsort(arr, sz, sizeof(int), cmp_arr);
		count = 0, printf("%d=%d", ti, arr[count++]);
		for (; count < sz; count++)
			printf("+%d", arr[count]);
		printf("\n");
	}
}

int main()
{
	int n = 0;
	scanf("%d", &n);
	find(n);

	return 0;
}