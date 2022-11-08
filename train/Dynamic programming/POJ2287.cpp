
/*
 * 问题描述：给出田忌和王的 N 匹马，安排赛马顺序使得得分最多，赢一场+200，输一场-200...
 *
 * 提交状态： AC
 *
 * AC 结果： Memory: 5920K Time: 688MS
 *
 * 解题方法1：dp[i][j] 表示 进行到 第 i 场比赛，用 j 匹慢马获得的最大收益。
则 dp[i][j] = max(dp[i - 1][j] + score(a[i - j], b[i], dp[i - 1][j - 1] + score(a[n - j + 1], b[i]));

 * 解题方法2 （可选）：
 *
 * 出错次数：7
 *
 * 错误原因 （可选）：
 *
 * 心得体会 （可选）：
 */

#include <iostream>
#include <cstring>

#include <algorithm>
using namespace std;

bool cmp(int x, int y) {
	return x > y;
}
int score(int x, int y) {
	if (x > y) return 1;
	if (x == y) return 0;
	return -1;
}
int a[1200], b[1200], dp[1200][1200];
int main() {
	int n;
	while (cin>>n, n) {
		for (int i = 1; i <= n; i++) cin>>a[i];
		for (int i = 1; i <= n; i++) cin>>b[i];
		sort(a + 1, a + 1 + n, cmp);
		sort(b + 1, b + 1 + n, cmp);
		memset(dp, -10000, sizeof(dp));
		dp[0][0] = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j <= n; j++) {
				if (j == 0) dp[i][j] = max(dp[i][j],
					dp[i - 1][j] + score(a[i - j], b[i]));
				else {
					dp[i][j] = max(dp[i - 1][j] + score(a[i - j], b[i]),
						dp[i - 1][j - 1] + score(a[n - j + 1], b[i]));
				}
			}
		}
		int ans = dp[n][0];
		for (int i = 1; i <= n; i++)
			if (ans < dp[n][i]) ans = dp[n][i];
		cout<<ans * 200<<endl;
	}
	return 0;
}