/*
* 问题描述：火车推倒计划质量的求解公式中的分子为1，分母为t0,td的距离总和。t0,td的距离就是两个输入字符串的字母不同位置的个数。想要推导计划的质量最高就是使分母最小。即t0,td的距离总和最小。
*
* 提交状态： AC
*
* AC 结果： Memory: 7960K Time:375 MS
*
* 解题方法1：以任意两个字符串为结点，以字符串字母不同位置的个数为两节点之间边的权值，求解最小生成树,用prime算法求解即可
 *
 * 解题方法2 （可选）也可使用kruskal算法求解
 *
 * 出错次数：5
 *
 * 错误原因 （可选）：
 *
 * 心得体会 （可选）：
 */
方法1——prime算法
#include<iostream>
using namespace std;
typedef long long ll;
#define INF 0x3f3f3f
const int maxn = 2005;
char s[maxn][10];
short int map[maxn][maxn];
bool use[maxn];
int dis[maxn];
int n;
void prime()
{
		int ans = 0;
		memset(use, 0, sizeof(use));
		use[0] = 1;
		for (int i = 0; i <n; i++)
		{
			dis[i] = map[0][i];
		}
		
		for (int i = 1; i <n; i++)
		{
			int minx = INF;
			int now = -1;
			for (int j = 0; j < n; j++)
			{
				if (!use[j] && dis[j] < minx)
				{
					now = j;
					minx = dis[j];
				}
			}
			ans += dis[now];
			use[now] = 1;
			for (int j = 0; j < n; j++)
			{
				if (!use[j] && dis[j] > map[now][j])
					dis[j] = map[now][j];
			}
		}
		cout << "The highest possible quality is 1/" << ans << "." << endl;
}
int main()
{
	
	while (cin >> n && n != 0)
	{
		
		cin >> s[0];
		for (int i = 1; i < n; i++)
		{
			cin >> s[i];
			for (int j = 0; j < i; j++)
			{
				int count = 0;
				for (int k = 0; k < 7; k++)
				{
					if (s[i][k] != s[j][k]) count++;
				}
				map[i][j] = map[j][i]=count;
			}
		}
		prime();
	}
}
方法2——krusal算法
#include<iostream>
#include<algorithm>
using namespace std;
const  int manx = 2005;
struct node {
	int from;
	int to;
	int weight;
}map[manx*(manx>>1)];
int n,m;
char str[manx][7];
int pre[manx];
bool cmp(node a, node b) {
	return a.weight < b.weight;
}
int finds(int x)
{
	return pre[x] == x ? x : finds(pre[x]);
}
void krusal()
{
	int ans = 0;
	for (int i = 0; i <= n; i++)
		pre[i] = i;
	for (int i = 0; i < m; i++)
	{
		int from = finds(map[i].from);
		int to = finds(map[i].to);
		if (from != to)
		{
			pre[from] = to;
			ans += map[i].weight;
		}
	}
	cout << "The highest possible quality is 1/" << ans << "." << endl;
}
int main()
{
	while (cin >> n && n)
	{
		for (int i = 0; i < n; i++)
		{
			cin >> str[i];
			for (int j = 0; j < i; j++)
			{
				int count = 0;
				for (int k = 0; k < 7; k++)
				{
					if (str[i][k] != str[j][k]) count++;
				}
				map[m].from = i;
				map[m].to = j;
				map[m++].weight = count;
			}
		}
		sort(map, map + m, cmp);
		krusal();
	}
}
