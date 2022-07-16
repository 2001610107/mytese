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