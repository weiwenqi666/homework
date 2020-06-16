#include <stdio.h>
#include <stdlib.h>

#define N 11

int select(int a[], int low, int high, int k);
int split(int a[], int low, int high);

int select(int a[], int low, int high, int k)
{
	int middle;

	middle = split(a, low, high);
	if (middle == k)
		return a[k];
	else if (middle < k)
		return select(a, middle + 1, high, k);
	else     /* if(middle > k) */
		return select(a, low, middle - 1, k);
}

int split(int a[], int low, int high)
{
	int part = a[low];

	for (;;) {
		while (low < high && part <= a[high])
			high--;
		if (low >= high) break;
		a[low++] = a[high];

		while (low < high && a[low] <= part)
			low++;
		if (low >= high) break;
		a[high--] = a[low];
	}

	a[high] = part;
	return high;
}

int main()
{
	int i, r;
	int a[N] = { 2,8,6,10,4,14,18,12,20,16 };
	scanf("%d", &i);
	if (i >= 0 && i <= N - 1)
	{
		r = select(a, 0, N - 1, i);
		printf("result=%d\n", r);
	}
	else
		printf("input error!");

	return 0;
}