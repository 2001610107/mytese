/*
 * 问题描述：求一个图的最小生成树，输入N个节点，用大写字母表示了节点，给节点与节点之间有权值，求这些边的权值之和最小。
 *
 * 提交状态： AC 
 *
 * AC 结果： Memory: 224K Time: 0MS
 *
 * 解题方法：先将字母转化为数字。再用最小生成树prime算法的方法求解。
 *
 * 解题方法2 （可选）：也可使用Kruskal算法的方法求解
 *
 * 出错次数：3
 *
 * 错误原因 （可选）：
 *
 * 心得体会 （可选）：
 */
方法1：prime算法
#include<iostream>
#define maxn 30
#define INF 0X3f3f3f
using namespace std;
int map[maxn][maxn];
bool use[maxn];
int dis[maxn];
int n, k,weight;
void prim()
{   int ans=0;
	for (int i = 0; i < n; i++)
	{
		dis[i] = map[0][i];
	}
	dis[0] = 0;
	use[0] = 1;
	for (int v = 0; v < n - 1; v++)
	{
		int minx = INF;
		int now = -1;
		for (int i = 0; i < n; i++)
		{
			if (!use[i] && dis[i] < minx)
			{
				now = i;
				minx = dis[i];
			}
		}
		ans += dis[now];
		use[now] = 1;
		for (int i = 0; i < n; i++)
		{
			if (!use[i] && dis[i] > map[now][i])
				dis[i] = map[now][i];
		}
	}
	cout << ans << endl;
}
int main()
{    char x,y;
	while (cin >> n && n)
	{
		memset(use, 0, sizeof(use));
		memset(map, INF, sizeof(map));
		for (int i = 0; i < n - 1; i++)
		{
			cin >> x >> k;
			for (int j = 0; j < k; j++)
			{
				cin >> y>> weight;
				int from = x - 'A';
				int to = y - 'A';
				map[from][to] = map[to][from] = weight;
			}
		}
		prim();
	}
}
方法2——kruskal算法
 * AC 结果： Memory: 224K Time: 16MS
#include<iostream>
#include<algorithm>
using namespace std;
const int N = 80;
struct node {
	int from;
	int to;
	int weight;
}map[N];	
int n;
int now;
int pre[30];
bool cmp(node a, node b)
{
	return a.weight < b.weight;
}
int finds(int x) {
	if (pre[x] == x) return pre[x];
	pre[x] = finds(pre[x]);
	return pre[x];
}
void kruskal()
{
	int ans = 0;
	for (int i = 0; i < 30; i++)
		pre[i] = i;
	sort(map, map + now, cmp);//
	for (int i = 0; i < now; i++)
	{
		int from = finds(map[i].from);
		int to = finds(map[i].to);
		if (from != to)
		{
			pre[from] = to;
			ans += map[i].weight;
		}
	}
	cout << ans << endl;
}
int main()
{
	while (cin >> n && n)
	{    now = 0;
		for (int i = 0; i < n - 1; i++)
		{    char x, y;
		      int k;
			cin >> x >> k;
			for (int j = 0; j < k; j++)
			{
				int weight;
				cin >> y >> weight;
				map[now].from = x - 'A';
				map[now].to = y - 'A';
				map[now++].weight = weight;
			}
		}
		kruskal();
	}
}
