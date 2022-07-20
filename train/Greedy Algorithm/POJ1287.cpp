/*
 * 问题描述：给出n个点（点号1 ~ n）, m条边双向边，边的数量不定，每两个点可能有多条边
 *
 * 提交状态： AC 
 *
 * AC 结果： Memory: 260K Time: 94MS
 *
 * 解题方法：邻接矩阵来存最短边（权重最小的边），再用最小生成树prime算法的方法求解。
 *
 * 解题方法2 （可选）：也可使用Kruskal算法的方法求解
 *
 * 出错次数：3
 *
 * 错误原因 （可选）：有重边，构造邻接矩阵时忘记选取权重最小的边
 *
 * 心得体会 （可选）：
 */
#include<iostream>
#include<cstring>
using namespace std;
#define maxn 101
#define min(a,b) a<b?a:b
#define INF 0X3f3f3f
int map[maxn][maxn];
int dis[maxn];
bool use[maxn];
int n, m;
void prim()
{
	int ans=0;
	for (int i = 1; i <= n; i++)
	{
		dis[i] = map[1][i];
		use[i] = 0;
	}
	use[1] = 1;
	for (int i = 1; i < n; i++)
	{
		int minx = INF;
		int now = -1;
		for (int j = 1; j <= n; j++)
		{
			if (!use[j] && dis[j] < minx)
			{
				now = j;
				minx = dis[j];
			}
		}
		ans += dis[now];
		use[now] = 1;
		for (int j = 1; j <= n; j++)
		{
			if (!use[j] && dis[j] >map[now][j])
				dis[j] = map[now][j];
		}
	}
	cout << ans << endl;
}
int main()
{
	int p1, p2, weight;
	while (cin >> n && n)
	{
		memset(map, INF, sizeof(map));
		cin >> m;
		for (int i = 1; i <=m; i++)
		{
			cin >> p1 >> p2 >> weight;
			map[p1][p2] = map[p2][p1] = min(map[p1][p2],weight);
		}
		prim();
	}

}
