#include<iostream>
#include<queue>
#include<cstring>
#define maxn 101
using namespace std;

int a, b, c;
bool used[maxn][maxn];
struct node {
	int a, b,count;
	char path[maxn];//操作流程
	int plen;
};
string path[] = {
	"FILL(1)",
	"FILL(2)",
	"DROP(1)",
	"DROP(2)",
	"POUR(1,2)",
	"POUR(2,1)"
};//六种操作，装满第一个壶、装满第二个壶、清空第一个壶、清空第二个壶、把第一个壶的水倒到第二个壶、把第二个壶的水倒到第一个壶
void print_result(int count, char p[], int n)
{
	cout << count << endl;
	for (int i = 0; i < n; i++)
	{
		cout << path[(int)p[i]] << endl;
	}
}
void BFS()
{
	queue<node>q;
	memset(used, true, sizeof(used));
	node pot;
	pot.a = 0;
	pot.b = 0;
	pot.count=0;
	pot.plen = 0;
    memset(pot.path, 0, sizeof(pot.path));
	q.push(pot);
	used[pot.a][pot.b] = false;
	while (!q.empty())
	{
		pot = q.front();
		q.pop();
		if (pot.a == c || pot.b == c)
		{
			print_result(pot.count, pot.path, pot.plen);
			return;
		}
		node now;
		now = pot;
		now.count++;
		now.plen++;
		//第一种操作;FILL(a)
		if (a - pot.a > 0)
		{
			now.a = a;
			now.b = pot.b;
			if (used[now.a][now.b])
			{
				now.path[pot.plen] = 0;
				q.push(now);
				used[now.a][now, b] = false;
			}
		}
		//第二种操作：FILL(b)
		if (b - pot.b > 0)
		{
			now.b= b;
			now.a = pot.a;
			if (used[now.a][now.b])
			{
				now.path[pot.plen] = 1;
				q.push(now);
				used[now.a][now, b] = false;
			}
		}
		//第三种操作：DROP(a)
		if (pot.a)
		{
			now.a = 0;
			now.b = pot.b;
			if (used[now.a][now.b])
			{
				now.path[pot.plen] = 2;
				q.push(now);
				used[now.a][now.b] = false;
			}
		}
		//第四种操作：DROP(b)
		if (pot.b)
		{
			now.b = 0;
			now.a = pot.a;
			if (used[now.a][now.b])
			{
				now.path[pot.plen] = 3;
				q.push(now);
				used[now.a][now.b] = false;
			}
		}
		//第五种操作POUR(a,b)
		if (pot.a && (pot.b < b))
		{
			if (pot.a > (b - pot.b))
			{
				now.a=pot.a-(b-pot.b);
				now.b = b;
			}
			else {
				now.a = 0;
				now.b = pot.b + pot.a;
			}
			if (used[now.a][now.b])
			{
				now.path[pot.plen] = 4;
				q.push(now);
				used[now.a][now.b] = false;
			}
		}
		//第六种操作:POUR(2,1)
		if (pot.b && (pot.a < a))
		{
			if (pot.b > (a - pot.a))
			{
				now.b = pot.b - (a - pot.a);
				now.a = a;
			}
			else {
				now.b = 0;
				now.a = pot.a + pot.b;
			}
			if (used[now.a][now.b])
			{
				now.path[pot.plen] = 5;
				q.push(now);
				used[now.a][now.b] = false;
			}
		}
	}
	cout << "impossible" << endl;
}
int main()
{
	while (cin >> a >> b >> c)
	{
      BFS();
    }
}