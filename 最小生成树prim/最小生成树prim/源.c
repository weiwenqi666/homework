const int M = 1e5 + 10;
const int N = 1e3 + 10;
const int inf = 0x3f3f3f3f;
int mp[N][N];//�ڽӾ����ͼ
int d[N];
bool vis[N];//�������
int n;//�������
int m;//�ߵ�����
int ans;
bool prim() {
	memset(vis, 0, sizeof vis);//��������ʼ��
	memset(d, inf, sizeof d);//��d �����ֵ����Ϊ�����
	d[1] = 0;//��ȷ��1�ŵ�������С������
	for (int i = 1; i < n; i++) {//ִ�� n-1 �Σ���ʣ��� n-1 ����
		int x = 0;
		for (int j = 1; j <= n; j++) {
			if (!vis[j] && (x == 0 || d[j] < d[x]))x = j;//�ҳ�δ����ǵ��� d ֵ��С��һ����
		}
		vis[x] = 1;//��������ǣ���ʾ�õ��ѱ���¼����С�������ļ���
		for (int y = 1; y <= n; y++) {
			if (!vis[y])d[y] = min(d[y], mp[x][y]);//ɨ��õ�����г��ߣ�������һ�˵�� d ֵ
		}
	}
	ans = 0;
	for (int i = 2; i <= n; i++) {
		if (d[i] == inf)return false;//�����һ����� d ֵ���������˵���õ㱻������ԭͼ��������С������
		ans += d[i];//�ۼӴ�
	}
	return true;
}