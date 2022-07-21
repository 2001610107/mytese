#include<iostream>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<cstring>
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
			int x, y;
			cin >> x >> y;
			p[i] = { x,y };
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