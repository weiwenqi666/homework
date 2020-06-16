#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAX = 1010;
char x[MAX], y[MAX];
int A[MAX][MAX];
int B[MAX][MAX];
void Print(int i, int j)
{
	if (i == 0 || j == 0)
	{
		return;
	}
	if (B[i][j] == 1)
	{
		Print(i - 1, j - 1);
		printf("%c", x[i - 1]);
	}
	else if (B[i][j] == 2)
	{
		Print(i - 1, j);
	}
	else if (B[i][j] == 3)
	{
		Print(i, j - 1);
	}
}
int main()
{
	int len1, len2, i, j;
	while (scanf("%s%s", x, y) != EOF)
	{
		memset(A, 0, sizeof(A));
		memset(B, 0, sizeof(B));
		len1 = strlen(x);
		len2 = strlen(y);
		for (i = 1; i <= len1; i++)
		{
			for (j = 1; j <= len2; j++)
			{
				if (x[i - 1] == y[j - 1])
				{
					A[i][j] = A[i - 1][j - 1] + 1;
					B[i][j] = 1;
				}
				else
				{
					if (A[i - 1][j] > A[i][j - 1])
					{
						A[i][j] = A[i - 1][j];
						B[i][j] = 2;
					}
					else
					{
						A[i][j] = A[i][j - 1];
						B[i][j] = 3;
					}
				}
			}
		}
		Print(len1, len2);
	}
	return 0;
}