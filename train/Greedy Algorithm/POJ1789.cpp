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