#include<stdio.h>
#include<string.h>
const int MAX = 150;

int n, m, p;
int a[MAX][MAX]; 
int color[MAX] = { 0 };
int count = 0;    //方案数量

bool Ok(int t) {
	for (int i = 1; i <= n; ++i) {
		if (a[t][i] == 1 && color[t]== color[i])
			return false;
	}
	return true;
}

void Trackback(int t) { //回溯
	if (t > n) {
		count++;
		for (int i = 1; i <= n; i++)
			printf("%d ", color[i]);
		printf("\n");
	}
	else {
		for (int i = 1; i <= m; i++) {  //颜色小于色数
			color[t] = i;
			if (Ok(t)) 
			{
				Trackback(t + 1);
			}
			color[t] = 0;
		}
	}
}

int main() {
	scanf("%d", &m);
	scanf("%d %d", &n, &p);
	for (int i = 1; i <= p; ++i) {
		int x, y;
		scanf("%d %d", &x, &y);
		a[x][y] = a[y][x] = 1;
	}
	Trackback(1);
	if (count == 0)
		printf("NO\n");
	else 
		printf("%d\n", count);
}