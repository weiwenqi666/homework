#include <stdlib.h>
#include <stdio.h>
#define N 10

void Merge(int a[], int temp[], int start, int mid, int end)
{
	int i = start, j = mid + 1, k = start;
	while (i != mid + 1 && j != end + 1)
	{
		if (a[i] > a[j])
			temp[k++] = a[j++];
		else
			temp[k++] = a[i++];
	}
	while (i != mid + 1)
		temp[k++] = a[i++];
	while (j != end + 1)
		temp[k++] = a[j++];
	for (i = start; i <= end; i++)
		a[i] = temp[i];
}

void MergeSort(int a[], int temp[], int start, int end)
{
	int mid;
	if (start < end)
	{
		mid = start + (end - start) / 2;
		MergeSort(a, temp, start, mid);
		MergeSort(a, temp, mid + 1, end);
		Merge(a, temp, start, mid, end);
	}
}

int main(int argc, char * argv[])
{
	int a[N] = { 16,4,128,8,64,2,32,512,1,256 };
	int i, b[N];
	MergeSort(a, b, 0, N-1);
	for (i = 0; i < 10; i++)
		printf("%d ", a[i]);
	printf("\n");
	return 0;
}