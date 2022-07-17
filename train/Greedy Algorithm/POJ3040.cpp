/*
 * 问题描述：约翰有n种面值的钱币，第i种的面值为v_i，数量有b_i，每个星期要给奶牛至少c元，问用现在的钱最多给奶牛多少周。
 *
 * 提交状态： AC 
 *
 * AC 结果： Memory: 228K Time: 0MS
 *
 * 解题方法1：采用贪心思想，首先，将大于等于c的面额的钱直接每个星期给奶牛一张，将面额大于等于c的钱去除，然后从大到小开始选择，要选择的金额尽可能的接近c，如果刚好能够凑足c就作为当前的一种方案，
 * 如果不能凑足c那就再从小的开始选，要选出一种的总额不少于c但尽量接近c作为当前的方案， 一直选到选择的金额不能凑足c为止。

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
#include<algorithm>
#define INF 0x3f3f3f
typedef long long ll;
using namespace std;
ll use[30];
struct  node
{
	ll v, b;
};
node a[25];
int cmp(node a, node b)
{
	return a.v < b.v;
}
void solution()
{
	ll  n, c, count,cnt,m;
	while (cin >> n >> c&&n!=0&&c!=0)
	{
		for (ll i = 0; i < n; i++)
		{
			cin >> a[i].v >> a[i].b;
		}
		sort(a, a + n, cmp);
		count = 0;
		for (ll i = n - 1; i >= 0; i--)
		{
			if (a[i].v > c)
			{
				count += a[i].b;
				a[i].b = 0;
			}
		}
		while (true)
		{
			bool sign=0;
			cnt = c;
			memset(use, 0, sizeof(use));
			for (ll i = n - 1; i >= 0; i--)
			{
				if (a[i].b)
				{
					ll temp = cnt / a[i].v;
					    m = min(temp, a[i].b);
					cnt -= m * a[i].v;
					use[i] = m;
					if (cnt == 0)
					{
						sign = 1;
						break;
					}
				}
			}
			if (cnt > 0)
			{
				for (ll i = 0; i < n; i++)
				{
					if(a[i].b>use[i])
					{
						while (use[i] < a[i].b)
						{
							cnt -= a[i].v;
							use[i]++;
							if (cnt <= 0)
							{
								sign = 1;
								break;
							}
						}
					}
					if (sign)
						break;
				}
			}
			if (!sign)
				break;
			m = INF;
			for (ll i = 0; i < n; i++)
			{
				if (use[i])
				{
					m = min(m, a[i].b / use[i]);
				}
			}
			count += m;
			for (ll i = 0; i < n; i++)
			{
				if (use[i])
				{
					a[i].b -= m * use[i];
				}
			}
		}
		cout << count << endl;
	}
}
int main()
{
	solution();
}
