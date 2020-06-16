#include <iostream>
#include <cstdio>
#define INTMAX 214748364
using namespace std;
const int MAX = 100;
const int M = 6;

//递归
int RecurMatrixChain(int P[], int i, int j) {
	int m[MAX][MAX], s[MAX][MAX];
	if (i == j) { 
		m[i][j] = 0;
		s[i][j] = i;
		return m[i][j];
	}
	m[i][j] = INTMAX;  
	s[i][j] = i;       
	for (int k = i; k <= j - 1; k++) { 
		int q = RecurMatrixChain(P, i, k) + RecurMatrixChain(P, k + 1, j) + P[i - 1] * P[k] * P[j]; 
		if (q < m[i][j]) {
			m[i][j] = q;
			s[i][j] = k;
		}
	}
	return m[i][j];
}
//迭代
void MatrixChain(int *p, int Length, int m[][M], int s[][M])
{
	int q, n = Length - 1;
	for (int i = 1; i <= n; i++) m[i][i] = 0;
	for (int l = 2; l <= n; l++) 
	{
		for (int i = 1; i <= n - l + 1; i++)
		{
			int j = i + l - 1;         
			m[i][j] = INTMAX;
			for (int k = i; k <= j - 1; k++)
			{
				q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
				if (q < m[i][j])
				{
					m[i][j] = q;
					s[i][j] = k;
				}
			}
		}
	}
}
void print(int s[][M], int i, int j)
{
	if (i == j) cout << "A" << i;
	else
	{
		cout << "(";
		print(s, i, s[i][j]);
		print(s, s[i][j] + 1, j);
		cout << ")";
	}
}
int main()
{
	int p[M] = { 5,1,4,6,3,2 };
	int m[M][M], s[M][M];
	MatrixChain(p, M, m, s);
	cout << "当n=5时最优解为: \n" << m[1][5];
	cout << "\n括号化方案为：\n";
	print(s, 1, 5);
	return 0;
}

