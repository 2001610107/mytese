
/*
 * 问题描述：只能#上放旗子，并且要求每一横排和每一纵列都只能有一个棋子
 *
 * 提交状态： AC 
 *
 * AC 结果： Memory: 156K Time: 16MS
 *
 * 解题方法1：棋子摆放的位置只能是#, 且不能同行和同列. 采用的是按行递增的顺序来搜索的, 因此不可能出现同行的情况, 对于同列的情况,设置一个变量used[], 
 * 来保存列的访问状态, 对于之前访问过的列, 棋子是不能再放在这一列上的.DFS(start, count) 代表将第k-count棵棋子放在start行上, 然后就剩下count-1棵棋子需要放在start行下面.
 * 当遇到第count棵棋子根本无法放在start行上的情况, DFS就回溯到上一个DFS调用的地方, 重新开始, 而如果遇到count=1, 且第start行的一些列可以放的话, 就将方案数相应增加.
 *
 * 解题方法2 （可选）：
 *
 * 出错次数：5
 *
 * 错误原因 （可选）：
 *
 * 心得体会 （可选）：
 */

#include<iostream>
using namespace std;
int n,k;
char chess[8][8];
int ans;
bool used[8];
void DFS(int start, int count)
{
	for (int i = 0; i < n; i++)
	{
		if (chess[start][i] == '#' && !used[i])
		{
			if (count == 1)
			{
				ans++;
			}
			else
			{
				used[i] = 1;
				for (int j = start + 1; j < n - count +2; j++)
				{
					DFS(j, count - 1);
				}
				used[i] = 0;
			}
		}
	}
}
void solution()
{
	while (cin>>n>>k) {
		if (n == -1 && k == -1) break;
			ans = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> chess[i];
		}
		memset(used, 0, sizeof(used));
		for (int i = 0; i <= n - k; i++)
		{
			DFS(i, k);
		}
		cout << ans << endl;
		}
}
int main()
{
	solution();
	return 0;
}
