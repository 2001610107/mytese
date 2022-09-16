/*
 * 问题描述：把m种数字填入n个位置，有多少种方法，求m为1到n的情况数的总和
 *
 * 提交状态： AC .
 *
 * AC 结果： Memory: 336K Time: 0MS
 *
 * 解题方法1：dp[i][j]表示i个位置j种数字，那么dp[i][j] = dp[i - 1][j] * j + dp[i][j - 1];
 *
 * 解题方法2 （可选）：
 *
 * 出错次数：6
 *
 * 错误原因 （可选）：
 *
 * 心得体会 （可选）：
 */

#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
const int N = 101;
double dp[N][N];
int n;
void init()
{
	for (int i = 1; i <= N; i++)
	{

		dp[1][i] = 0;
		dp[i][1] = 1;
	}
	for (int i = 2; i <= 100; ++i)
		for (int j = 2; j <= i; ++j)
			dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j] * j;
}
int main()
{
	init();
	while (cin >> n && n)
	{
		double res = 0;
		for (int i = 1; i <= n; i++) 
			res += dp[n][i];
		printf("%d %.0f\n", n, res);
	}
}


/*#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N = 1000;
int solve(int x)
{
	if (x <= 1)
		return x;
	else
	    return solve(x - 1) + solve(x-2);
}
int main()
{
	int f[N];
	f[0] = f[1] = 1;
	int n;
	for (int i = 2; i < N; i++)
		f[i] = f[i - 1] + f[i - 2];
	cin >> n;
	cout << "动态规划：";
	for (int i = 0; i < n; i++)
		cout << f[i] << ' ';
	puts("");
	cout << "递归式：";
	for (int i = 1; i <= n; i++)
		cout << solve(i) << ' ';
	puts("");

}

*/
