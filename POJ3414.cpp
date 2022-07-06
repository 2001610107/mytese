#include<iostream>
#include<queue>
#include<cstring>
#define maxn 101
using namespace std;

int a, b, c;
bool used[maxn][maxn];
struct node {
	int a, b,count;
	char path[maxn];//��������
	int plen;
};
string path[] = {
	"FILL(1)",
	"FILL(2)",
	"DROP(1)",
	"DROP(2)",
	"POUR(1,2)",
	"POUR(2,1)"
};//���ֲ�����װ����һ������װ���ڶ���������յ�һ��������յڶ��������ѵ�һ������ˮ�����ڶ��������ѵڶ�������ˮ������һ����
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
		//��һ�ֲ���;FILL(a)
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
		//�ڶ��ֲ�����FILL(b)
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
		//�����ֲ�����DROP(a)
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
		//�����ֲ�����DROP(b)
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
		//�����ֲ���POUR(a,b)
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
		//�����ֲ���:POUR(2,1)
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