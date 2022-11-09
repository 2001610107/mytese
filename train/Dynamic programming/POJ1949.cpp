/*
 * 问题描述：有n个任务，第i个任务需要时间xi来完成，
 *  并且第i个任务必须在它 “前面的” 某些任务完成之后才能开始
 *  给你任务信息，问你最短需要多少时间来完成任务。
 *
 * 提交状态： AC
 *
 * AC 结果： Memory: 308K Time: 1563MS
 *
 * 解题方法1：用一个数组dp来存完成第i个任务时所需的最短的时间，dp[i] = max（dp[j]) +time， 
 j是需要在它前面完成的任务的序号，time是完成当前任务所需时间。
 *
 *
 * 解题方法2 （可选）：
 *
 * 出错次数：8
 *
 * 错误原因 （可选）：
 *
 * 心得体会 （可选）：
 */


#include <iostream>
#include <algorithm>
using namespace std;
 
int dp[10008]; 
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int w, m;
		cin >> w >> m;
		if (m == 0)
		{
			dp[i] = w;
		}
		for (int j = 0; j < m; j++)
		{
			int p;
			cin >> p;
			if (dp[i] < (dp[p] + w))
			{
				dp[i] = (dp[p] + w);
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		if (ans < dp[i])
		{
			
			ans = dp[i];
		}
		//cout<<i<<" "<<dp[i]<<endl;
	}
	cout << ans << endl;
	return 0;
}