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
