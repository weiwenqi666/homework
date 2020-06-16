#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;

const double INF = 1e20;
const int N = 100005;

//��������ýṹ��洢
struct Point {
	double x, y;
}point[N];
int n;
int tmpt[N];

//����������ƽ���ĺ���
double distance(int i,int j) {
	return sqrt(pow(point[i].x - point[j].x, 2) + pow(point[i].y - point[j].y, 2));
}

//�ȽϺ���
bool compareXY(Point& a, Point& b) {
	if (a.x != b.x)
		return a.x < b.x;
	return a.y < b.y;
}

bool compareY(int& a, int& b) {
	return point[a].y < point[b].y;
}

//����Сֵ
double min(int a, int b) {
	return a < b ? a : b;
}

//�������㷨
double EfficientClosestPair(int left, int right)
{
	double d = INF;
	if (left == right)
		return d;
	if (left + 1 == right)
		return distance(left, right);
	int mid = (left + right) >> 1;
	double d1 = EfficientClosestPair(left, mid);
	double d2 = EfficientClosestPair(mid + 1, right);
	d = min(d1, d2);
	int i, j, k = 0;
	//��������Ϊd������  
	for (i = left; i <= right; i++)
	{
		if (fabs(point[mid].x - point[i].x) <= d)
			tmpt[k++] = i;
	}
	sort(tmpt, tmpt + k, compareY);
	//����ɨ��  
	for (i = 0; i < k; i++)
	{
		for (j = i + 1; j < k && point[tmpt[j]].y - point[tmpt[i]].y < d; j++)
		{
			double d3 = distance(tmpt[i], tmpt[j]);
			if (d > d3)
				d = d3;
		}
	}
	return d;
}


int main()
{
	while (true)
	{
		scanf("%d", &n);
		if (n == 0)
			break;
		for (int i = 0; i < n; i++)
			scanf("%lf %lf", &point[i].x, &point[i].y);
		sort(point, point + n, compareXY);
		printf("%.2lf\n", EfficientClosestPair(0, n - 1) / 2);
	}
	return 0;
}
