/*
 * 问题描述：有S颗卫星和P个哨所，有卫星的两个哨所之间可以任意通信；否则，一个哨所只能和距离它小于等于D的哨所通信。给出卫星的数量和P个哨所的坐标，求D的最小值。
 *
 * 提交状态： 
 *
 * AC 结果： Memory: 2192K Time:219 MS
 *
* 解题方法1：两个点都能通信，可以转化成最小生成树，kruskal 算法，依次选择最小生成树的最短的 p - s 条边， 最后一条边就是答案；
 *
 * 解题方法2 （可选）：
 *
 * 出错次数：7
 *
 * 错误原因 （可选）：
 *
 * 心得体会 （可选）：
 */
#include<iostream>
#include<algorithm>
#include<iomanip>
#include<cmath>
using namespace std;
const int maxn = 510, M = maxn * maxn / 2;
struct Node {
	int x;
	int y;
}p[maxn];
struct Map {
	int from;
	int to;
	double weight;
	bool operator<(const Map& o)const {
		return weight < o.weight;
	}
}e[M];
int pt[maxn];
int find(int x)
{
	return pt[x] == x ? x : (pt[x] = find(pt[x]));
}
double get(int i,int j)
{
	double x = p[i].x - p[j].x;
	double y = p[i].y - p[j].y;
	return sqrt(x * x + y * y);
}
int main()
{
	int train_count;
	cin >> train_count;
	while (train_count--)
	{
		int m = 0;
		int s, n;
		cin >> s >> n;
		for (int i = 1; i <= n; i++)
		{
			pt[i] = i;
		}
		for (int i = 1; i <= n; i++)
		{
			cin >>p[i].x >> p[i].y;
		}
		for (int i = 1; i <= n; i++)
		{
			for (int j = i + 1; j <= n; j++)
			{
				e[++m].from = i;
				e[m].to = j;
				e[m].weight=get(i,j);
			 }
		}
		sort(e + 1, e + 1 + m);
		double ans = 0;
		int cnt = n;
		for (int i = 1; i <= m; i++)
		{
			if (cnt <= s) break;
			int f_from = find(e[i].from);
			int f_to = find(e[i].to);
			if (f_from != f_to)
			{
				pt[f_from] = f_to;
				ans = e[i].weight;
				cnt--;
			}
		}
		cout << setiosflags(ios::fixed) << setprecision(2) << ans << endl;
 	}
}
