/*
 * 问题描述：一块整的木板，每次切都会花费当前整木板长度的费用，求最少的花费。
 *
 * 提交状态： AC
 *
 * AC 结果： Memory: 376K Time:63 MS
 *
* 解题方法1：采取贪心思想和优先队列，每次找到最小的两块木板将其入队，并将其长度累加在总费用中，并将其合并后，与剩下的木板比较，直至合并为一个木板。
 *
 * 解题方法2 （可选）
 *
 * 出错次数：2
 *
 * 错误原因 （可选）：
 *
 * 心得体会 （可选）：
 */
#include<iostream>
#include<queue>
typedef long long ll;
using namespace std;

int  solution()
{
	int n, length;
  	cin >> n;
	priority_queue<int, vector<int>, greater<int>>q;
	for (int i = 0; i < n; i++)
	{
		cin >> length;
		q.push(length);
	}
	if (q.size() == 1)
	{
		cout << q.top();
		return 0;
	}
	ll ans = 0;
	while (q.size() != 1)
	{
		ll min_1, min_2;
		min_1 = q.top();
		q.pop();
		min_2 = q.top();
		q.pop();
		ans += min_1 + min_2;
		q.push(min_1 + min_2);
	}
	cout << ans << endl;
	return 0;
}
int main()
{
	solution();
}
