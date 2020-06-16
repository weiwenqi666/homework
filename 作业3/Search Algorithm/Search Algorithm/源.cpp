#include<iostream>
using namespace std;

int Sequential_Search(int a[], int n, int key)
{
	int i;
	for (i = 1; i <= n; i++)
	{
		if (a[i] == key)
			return i;
	}
	return 0;
}
int Binary_Search(int a[], int length, int key)
{
	int low = 1;
	int high = length;
	int mid;
	while (low <= high)
	{
		mid = (low + high) / 2;   //�۰룬midΪ�м�����
		if (key < a[mid])
			high = mid - 1;     //����±��Ϊ����mid�±�ǰһλ����������
		else if (key > a[mid])
			low = mid + 1;     //��С�±��Ϊ����mid�±��һλ����������
		else
			return mid;      //��ȼ��ҵ�������mid
	}
	return 0;
}

int main() {
	int a[] = { 2,4,6,8,10,12,14,16,18,20 };
	int n;
	int length = sizeof(a);
	cin >> n;
	int j = Sequential_Search(a, length, n);
	//int j = Binary_Search(a, length - 1, n);
	if (j >= 0)
	{
		cout << "j=" << j << endl;
	}
	else
	{
		cout << "j=0" << endl;
	}

	return 0;
}