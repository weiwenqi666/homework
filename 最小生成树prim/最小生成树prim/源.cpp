#include <stdio.h>
#include <stdlib.h>
#define MAX 100
#define MAXCOST 0x7fffffff
int graph[MAX][MAX];
int Prim(int graph[][MAX], int n)
{
	int lowcost[MAX];//lowcost[i]记录以i为终点的边的最小权值，当lowcost[i]=0时表示终点i加入生成树
	int mst[MAX];//mst[i]记录对应lowcost[i]的起点，当mst[i]=0时表示起点i加入生成树
	int i, j, min, minid, sum = 0;
	for (i = 2; i <= n; i++)//默认选择1号节点加入生成树，从2号节点开始初始化
	{
		lowcost[i] = graph[1][i];//最短距离初始化为其他节点到1号节点的距离
		mst[i] = 1;//标记所有节点的起点皆为默认的1号节点
	}

	mst[1] = 0;// 标记1号节点加入生成树
	for (i = 2; i <= n; i++)//n个节点至少需要n-1条边构成最小生成树
	{
		min = MAXCOST;
		minid = 0;
		for (j = 2; j <= n; j++)//找满足条件的最小权值边的节点minid 
		{
			if (lowcost[j] < min && lowcost[j] != 0)//边权值较小且不在生成树中
			{
				min = lowcost[j];
				minid = j;
			}
		}
		printf("%c - %c : %d\n", mst[minid] + 'A' - 1, minid + 'A' - 1, min);//输出生成树边的信息:起点，终点，权值
		sum += min;//累加权值
		lowcost[minid] = 0;//标记节点minid加入生成树
		for (j = 2; j <= n; j++)//更新当前节点minid到其他节点的权值
		{
			if (graph[minid][j] < lowcost[j])//发现更小的权值
			{
				lowcost[j] = graph[minid][j];//更新权值信息
				mst[j] = minid;//更新最小权值边的起点
			}
		}
	}
	return sum;//返回最小权值和
}

int main()
{
	int i, j, k, m, n;
	int x, y, cost;
	char chx, chy;
	scanf("%d%d", &m, &n);//读取节点和边的数目
	getchar();
	for (i = 1; i <= m; i++)//初始化图，所有节点间距离为无穷大
	{
		for (j = 1; j <= m; j++)
		{
			graph[i][j] = MAXCOST;
		}
	}
	for (k = 0; k < n; k++)//读取边信息
	{
		scanf("%c %c %d", &chx, &chy, &cost);
		getchar();
		i = chx - 'A' + 1;
		j = chy - 'A' + 1;
		graph[i][j] = cost;
		graph[j][i] = cost;
	}
	cost = Prim(graph, m);//求解最小生成树
	printf("Total:%d\n", cost);//输出最小权值和
	return 0;
}