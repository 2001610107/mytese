/*

*/

/*
 * 问题描述：两个人数一样的监狱，有一些囚犯不能在一起，两个监狱要等数量（ < m/2）交换一些囚犯，
 *问最多可以交换多少个囚犯；
 *
 * 提交状态： AC
 *
 * AC 结果： Memory:1244K Time:329 MS
 *
 * 解题方法1：用并查集求出有关系的人数，以数对的形式表示，然后转化为背包问题，用动态规划求解.
 * dp[k][i][j] = dp[k-1][i-a[k]][j-b[k]] || dp[k-1][i][j]。dp[k][i][j]表示对前K组，
 *用监狱A的i个人和监狱B的j个人交换是否成功。前K组的解与前K-1组有关。
 * 当前K-1组解决后，只要加上第K组就可以搞定前K组。对第K组有两种选择：选或不选。
 *
 * 解题方法2 （可选）
 *
 * 出错次数：11
 *
 * 错误原因 （可选）：
 *
 * 心得体会 （可选）：
 */

#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 510;
int dp[N][N];
int m, r;
int cnt;
int f[N];
int cnt1[N];
int cnt2[N];
struct P
{
	int a, b;
}p[N];
void init() //初始化
{
	cnt = 0;
	memset(cnt1, 0, sizeof cnt1);
	memset(cnt2, 0, sizeof cnt2);
	memset(dp, 0, sizeof dp);
	for (int i = 0; i < N; i++) f[i] = i;
}
int find(int x)
{
	if (f[x] != x) f[x] = find(f[x]);
	return f[x];
}
void merge(int fa, int fb)
{
	int a = find(fa);
	int b = find(fb);
	if (a != b) f[a] = b;
}
int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		cin >> m >> r;
		init();
		for (int i = 0; i < r; i++)
		{
			int a, b;
			cin >> a >> b;
			merge(a, b + m);//查看是否联通
		}
		for (int i = 1; i <= m; i++) cnt1[find(i)]++;
		for (int i = m + 1; i <=m * 2; i++)cnt2[find(i)]++;
		for (int i = 1; i <= m * 2; i++)
		{
			if (cnt1[i] || cnt2[i])
			{
				p[cnt].a = cnt1[i];
				p[cnt++].b = cnt2[i]; 
			}
		}
		dp[0][0] = 1;
		for (int i = 0; i < cnt; i++)
			for (int j = m / 2; j >=p[i].a; j--)
				for (int k = m / 2; k >= p[i].b; k--)
					if (dp[j - p[i].a][k - p[i].b]) dp[j][k] = 1;
		int i ;
		for (i = m / 2; i >= 0; i--)
		{
			if (dp[i][i]==1) break;
		}
		cout << i << endl;
	}
}