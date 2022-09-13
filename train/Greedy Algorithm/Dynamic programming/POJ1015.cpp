/* 
 * 问题描述：有n个人，每个人有一个D值和P值，求选出m个人，使得|∑(D)-∑(P)|最小，如果最小值相同，则选择|∑(D)+∑(P)|较大的，输出选出的人和∑(D)，∑(P)
。
 *
 * 提交状态： AC
 *
 * AC 结果： Memory: 1312K Time:94 MS
 *
* 解题方法1：，动态规划:
dp[i][j] 代表选第i个，选择的D[]和与P[]和差为j的 最大总和。
path[i][j] 记录前i个选择的组。
Sub[i] = D[i]-P[i];
Pus[i] = D[i]+P[i];
如果选择的前i组和差无法达到j，那么dp[i][j] = -1;
if(k 前面有路径 && k 在前面的路径上没有出现)
 dp[i+1][j+sub[k]] = max(dp[i+1][j+sub[k]],dp[i][j]+pus[k]);
 *
 * 解题方法2 （可选）
 *
 * 出错次数：12
 *
 * 错误原因 （可选）：
 *
 * 心得体会 （可选）：
 */

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


