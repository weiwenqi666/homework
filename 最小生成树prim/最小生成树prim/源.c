const int M = 1e5 + 10;
const int N = 1e3 + 10;
const int inf = 0x3f3f3f3f;
int mp[N][N];//邻接矩阵存图
int d[N];
bool vis[N];//标记数组
int n;//点的数量
int m;//边的数量
int ans;
bool prim() {
	memset(vis, 0, sizeof vis);//标记数组初始化
	memset(d, inf, sizeof d);//将d 数组初值都设为无穷大
	d[1] = 0;//先确定1号点属于最小生成树
	for (int i = 1; i < n; i++) {//执行 n-1 次，找剩余的 n-1 个点
		int x = 0;
		for (int j = 1; j <= n; j++) {
			if (!vis[j] && (x == 0 || d[j] < d[x]))x = j;//找出未被标记的且 d 值最小的一个点
		}
		vis[x] = 1;//将这个点标记，表示该点已被收录进最小生成树的集合
		for (int y = 1; y <= n; y++) {
			if (!vis[y])d[y] = min(d[y], mp[x][y]);//扫描该点的所有出边，更新令一端点的 d 值
		}
	}
	ans = 0;
	for (int i = 2; i <= n; i++) {
		if (d[i] == inf)return false;//如果有一个点的 d 值还是无穷大，说明该点被孤立，原图不存在最小生成树
		ans += d[i];//累加答案
	}
	return true;
}