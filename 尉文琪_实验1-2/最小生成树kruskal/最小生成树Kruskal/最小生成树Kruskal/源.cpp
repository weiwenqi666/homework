#include <stdio.h>
#include <stdlib.h>
#define MAXE 100
#define MAXV 100
typedef struct {
	int u;                     //�ߵ���ʼ����
	int v;                      //�ߵ���ֹ����
	int weight;                    //�ߵ�Ȩֵ
}Edge;
void kruskal(Edge E[], int n, int e)
{
	int i, j, m1, m2, sn1, sn2, k, sum = 0;
	int vset[MAXE];
	for (i = 1; i <= n; i++)        //��ʼ����������
		vset[i] = i;
	k = 1;//��ʾ��ǰ������С�������ĵ�k���ߣ���ֵΪ1
	j = 0;//E�бߵ��±꣬��ֵΪ0
	while (k < n)//���ɵı���С��nʱ����ѭ��
	{
		m1 = E[j].u;
		m2 = E[j].v;//ȡһ���ߵ������ڽӵ�
		sn1 = vset[m1];
		sn2 = vset[m2];
		//�ֱ�õ��������������ļ��ϱ��
		if (sn1 != sn2)//����������ڲ�ͬ�ļ��ϣ��ñ�����С��������һ����
		{//��ֹ���ֱպϻ�· 
			printf("V%d-V%d : %d\n", m1, m2, E[j].weight);
			sum += E[j].weight;
			k++;                //���ɱ������� 
			if (k >= n)
				break;
			for (i = 1; i <= n; i++)    //��������ͳһ���
				if (vset[i] == sn2)  //���ϱ��Ϊsn2�ĸ�Ϊsn1
					vset[i] = sn1;
		}
		j++;                  //ɨ����һ����
	}
	printf("Total:%d\n", sum);
}
int fun(Edge arr[], int low, int high)
{
	int key;
	Edge lowx;
	lowx = arr[low];
	key = arr[low].weight;
	while (low < high)
	{
		while (low < high && arr[high].weight >= key)
			high--;
		if (low < high)
			arr[low++] = arr[high];

		while (low < high && arr[low].weight <= key)
			low++;
		if (low < high)
			arr[high--] = arr[low];
	}
	arr[low] = lowx;
	return low;
}
void quick_sort(Edge arr[], int start, int end)
{
	int pos;
	if (start < end)
	{
		pos = fun(arr, start, end);
		quick_sort(arr, start, pos - 1);
		quick_sort(arr, pos + 1, end);
	}
}
int main()
{
	Edge E[MAXE];
	int nume, numn;
	scanf("%d%d", &numn, &nume);
	for (int i = 0; i < nume; i++)
		scanf("%d%d%d", &E[i].u, &E[i].v, &E[i].weight);
	quick_sort(E, 0, nume - 1);
	kruskal(E, numn, nume);
}