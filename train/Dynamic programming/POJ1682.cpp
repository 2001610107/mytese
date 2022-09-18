
/*
 * 问题描述：有三个相互隔离的河岸X,Y,Z，每个岸上分别有n,m,p个部落，每个河岸上的部落之间是敌对的（即同一个河岸上的部落之间不能连通），
 然而，位于不同河岸上的任意两个部落之间都是友好的，现在请你在部落之间搭建桥梁（不能交叉），
 每座桥的费用是两部落的海拔差的绝对值，求：使得每一个部落都能与至少一个他的友好部落连通 的桥的总费用。
 *
 * 提交状态： AC
 *
 * AC 结果： Memory: 540K Time: 63MS
 *
 * 解题方法1：1、两两解决，共三组。dp[i][j]表示一面匹配到i，另一面匹配到j的情况，将这三组合起来。
 *
 * 解题方法2 （可选）：
 *
 * 出错次数：10
 *
 * 错误原因 （可选）：
 *
 * 心得体会 （可选）：
 */

#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>

using namespace std;
const int N = 150;
void DP()
{
	int m, n, p;
	int x[N], y[N],z[N];
	int xy[N][N], xz[N][N], yz[N][N];
	cin >> m >> n >> p;
	for (int i = 1; i <= n; i++)cin >> x[i];
	for (int i = 1; i <= m; i++) cin >> y[i];
	for (int i = 1; i <= p; i++) cin>>z[i];
	for (int i = 0; i < 150; i++)
		for (int j = 0; j < 150; j++)
			xz[i][j] = xy[i][j] = yz[i][j] = 999999;
	int res = 999999;

	
	xz[0][p + 1] = 0;
	for (int i = 1; i <= n; i++)
		for (int j = p; j >= 1; j--)
			xz[i][j] = min(min(xz[i - 1][j + 1], xz[i - 1][j]), xz[i][j + 1]) + abs(x[i] - z[j]);
	xy[n + 1][0] = 0;
	for (int i = n; i >= 1; i--)
		for (int j = 1; j <= m; j++)
			xy[i][j] = min(min(xy[i + 1][j - 1], xy[i + 1][j]), xy[i][j - 1]) + abs(x[i] - y[j]);
	yz[m + 1][0] = 0;
	for (int i = m; i >= 1; i--)
		for (int j = 1; j <= p; j++)
			yz[i][j] = min(min(yz[i + 1][j - 1], yz[i + 1][j]), yz[i][j - 1]) + abs(y[i] - z[j]);

	for (int i = 0; i <= n + 1; i++)
		for (int j = 0; j <= m + 1; j++)
			for (int k = 0; k <= p + 1; k++)
			{
				res = min(res, xy[i][j] + xz[i][k] + yz[j][k]);
				res = min(res, xy[i][j] + xz[i][k] + yz[j + 1][k]);
				res = min(res, xy[i + 1][j] + xz[i][k] + yz[j][k]);
				res = min(res, xy[i][j] + xz[i][k + 1] + yz[j][k]);
				res = min(res, xy[i + 1][j] + xz[i][k] + yz[j + 1][k]);
				res = min(res, xy[i][j] + xz[i][k + 1] + yz[j + 1][k]);
				res = min(res, xy[i + 1][j] + xz[i][k + 1] + yz[j][k]);
				res = min(res, xy[i + 1][j] + xz[i][k + 1] + yz[j + 1][k]);
				
			}


	cout << res << endl;
}
int main()
{
	int tt;
	cin >> tt;
	while (tt--)
	{
		DP();
	}
	return 0;
}