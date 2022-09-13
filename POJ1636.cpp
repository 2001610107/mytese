/*

*/

/*
 * ������������������һ���ļ�������һЩ����������һ����������Ҫ�������� < m/2������һЩ������
 *�������Խ������ٸ�������
 *
 * �ύ״̬�� AC
 *
 * AC ����� Memory:1244K Time:329 MS
 *
 * ���ⷽ��1���ò��鼯����й�ϵ�������������Ե���ʽ��ʾ��Ȼ��ת��Ϊ�������⣬�ö�̬�滮���.
 * dp[k][i][j] = dp[k-1][i-a[k]][j-b[k]] || dp[k-1][i][j]��dp[k][i][j]��ʾ��ǰK�飬
 *�ü���A��i���˺ͼ���B��j���˽����Ƿ�ɹ���ǰK��Ľ���ǰK-1���йء�
 * ��ǰK-1������ֻҪ���ϵ�K��Ϳ��Ը㶨ǰK�顣�Ե�K��������ѡ��ѡ��ѡ��
 *
 * ���ⷽ��2 ����ѡ��
 *
 * ���������11
 *
 * ����ԭ�� ����ѡ����
 *
 * �ĵ���� ����ѡ����
 */

#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 510;
int dp[N][N];
int m, r;
int cnt;
int f[N];
int cnt1[N];
int cnt2[N];
struct P
{
	int a, b;
}p[N];
void init() //��ʼ��
{
	cnt = 0;
	memset(cnt1, 0, sizeof cnt1);
	memset(cnt2, 0, sizeof cnt2);
	memset(dp, 0, sizeof dp);
	for (int i = 0; i < N; i++) f[i] = i;
}
int find(int x)
{
	if (f[x] != x) f[x] = find(f[x]);
	return f[x];
}
void merge(int fa, int fb)
{
	int a = find(fa);
	int b = find(fb);
	if (a != b) f[a] = b;
}
int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		cin >> m >> r;
		init();
		for (int i = 0; i < r; i++)
		{
			int a, b;
			cin >> a >> b;
			merge(a, b + m);//�鿴�Ƿ���ͨ
		}
		for (int i = 1; i <= m; i++) cnt1[find(i)]++;
		for (int i = m + 1; i <=m * 2; i++)cnt2[find(i)]++;
		for (int i = 1; i <= m * 2; i++)
		{
			if (cnt1[i] || cnt2[i])
			{
				p[cnt].a = cnt1[i];
				p[cnt++].b = cnt2[i]; 
			}
		}
		dp[0][0] = 1;
		for (int i = 0; i < cnt; i++)
			for (int j = m / 2; j >=p[i].a; j--)
				for (int k = m / 2; k >= p[i].b; k--)
					if (dp[j - p[i].a][k - p[i].b]) dp[j][k] = 1;
		int i ;
		for (i = m / 2; i >= 0; i--)
		{
			if (dp[i][i]==1) break;
		}
		cout << i << endl;
	}
}