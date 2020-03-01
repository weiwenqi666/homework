#include <stdio.h>
#include <stdlib.h>
#define MAX 100
#define MAXCOST 0x7fffffff
int graph[MAX][MAX];
int Prim(int graph[][MAX], int n)
{
	int lowcost[MAX];//lowcost[i]��¼��iΪ�յ�ıߵ���СȨֵ����lowcost[i]=0ʱ��ʾ�յ�i����������
	int mst[MAX];//mst[i]��¼��Ӧlowcost[i]����㣬��mst[i]=0ʱ��ʾ���i����������
	int i, j, min, minid, sum = 0;
	for (i = 2; i <= n; i++)//Ĭ��ѡ��1�Žڵ��������������2�Žڵ㿪ʼ��ʼ��
	{
		lowcost[i] = graph[1][i];//��̾����ʼ��Ϊ�����ڵ㵽1�Žڵ�ľ���
		mst[i] = 1;//������нڵ������ΪĬ�ϵ�1�Žڵ�
	}

	mst[1] = 0;// ���1�Žڵ����������
	for (i = 2; i <= n; i++)//n���ڵ�������Ҫn-1���߹�����С������
	{
		min = MAXCOST;
		minid = 0;
		for (j = 2; j <= n; j++)//��������������СȨֵ�ߵĽڵ�minid 
		{
			if (lowcost[j] < min && lowcost[j] != 0)//��Ȩֵ��С�Ҳ�����������
			{
				min = lowcost[j];
				minid = j;
			}
		}
		printf("%c - %c : %d\n", mst[minid] + 'A' - 1, minid + 'A' - 1, min);//����������ߵ���Ϣ:��㣬�յ㣬Ȩֵ
		sum += min;//�ۼ�Ȩֵ
		lowcost[minid] = 0;//��ǽڵ�minid����������
		for (j = 2; j <= n; j++)//���µ�ǰ�ڵ�minid�������ڵ��Ȩֵ
		{
			if (graph[minid][j] < lowcost[j])//���ָ�С��Ȩֵ
			{
				lowcost[j] = graph[minid][j];//����Ȩֵ��Ϣ
				mst[j] = minid;//������СȨֵ�ߵ����
			}
		}
	}
	return sum;//������СȨֵ��
}

int main()
{
	int i, j, k, m, n;
	int x, y, cost;
	char chx, chy;
	scanf("%d%d", &m, &n);//��ȡ�ڵ�ͱߵ���Ŀ
	getchar();
	for (i = 1; i <= m; i++)//��ʼ��ͼ�����нڵ�����Ϊ�����
	{
		for (j = 1; j <= m; j++)
		{
			graph[i][j] = MAXCOST;
		}
	}
	for (k = 0; k < n; k++)//��ȡ����Ϣ
	{
		scanf("%c %c %d", &chx, &chy, &cost);
		getchar();
		i = chx - 'A' + 1;
		j = chy - 'A' + 1;
		graph[i][j] = cost;
		graph[j][i] = cost;
	}
	cost = Prim(graph, m);//�����С������
	printf("Total:%d\n", cost);//�����СȨֵ��
	return 0;
}