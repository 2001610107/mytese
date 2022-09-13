
/*#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
int dp[25][810];
int main()
{
	int sub[210], pus[210];
	int cnt = 1;
	int n, m;
	vector<int>path[21][801];
	while (~scanf_s("%d%d", &n, &m) && n && m)
	{
		for (int i = 0; i < m; ++i) //Çå¿Õ
			for (int j = 0; j < 801; ++j)
				path[i][j].clear();
		memset(dp, -1, sizeof(dp));
		int d, p;
		for (int i = 0; i < n; i++)
		{
			cin >> d >> p;
			sub[i] = d - p;
			pus[i] = d + p;
		}

		int fix = 20 * m;
		dp[0][fix] = 0;
		for (int k = 0; k < n; k++)
			for (int i = m - 1; i >= 0; i--)
				for (int j = 0; j < 2 * fix; j++)
				{
					if (dp[i][j] >= 0)
					{
						if (dp[i + 1][j + sub[k]] <= dp[i][j] + pus[k])
						{
							dp[i + 1][j + sub[k]] = dp[i][j] + pus[k];
							path[i + 1][j + sub[k]] = path[i][j];
							path[i + 1][j + sub[k]].push_back(k);
						}
					}
				}

		int i = 0;
		for (i = 0; dp[m][fix + i] == -1 && dp[m][fix - i] == -1; i++);
		int temp;
	    temp = (dp[m][fix + i] > dp[m][fix - i]) ? i : -i;
		int resD = (dp[m][fix + temp] + temp) / 2;
		int resP = (dp[m][fix + temp] - temp) / 2;
		printf("Jury #%d\n", cnt++);
		printf("Best jury has value %d for prosecution and value %d for defence:\n", resD, resP);
		for (int i = 0; i < m; i++)
			printf(" %d", path[m][fix + temp][i] + 1);
		printf("\n\n");
	}
}
*/


