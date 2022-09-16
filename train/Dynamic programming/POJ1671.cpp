/*
 * ������������m����������n��λ�ã��ж����ַ�������mΪ1��n����������ܺ�
 *
 * �ύ״̬�� AC / WA / TLE / ...
 *
 * AC ����� Memory: 160K Time: 1110MS
 *
 * ���ⷽ��1��dp[i][j]��ʾi��λ��j�����֣���ôdp[i][j] = dp[i - 1][j] * j + dp[i][j - 1];
 *
 * ���ⷽ��2 ����ѡ����
 *
 * ���������0
 *
 * ����ԭ�� ����ѡ����
 *
 * �ĵ���� ����ѡ����
 */

#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
const int N = 101;
double dp[N][N];
int n;
void init()
{
	for (int i = 1; i <= N; i++)
	{

		dp[1][i] = 0;
		dp[i][1] = 1;
	}
	for (int i = 2; i <= 100; ++i)
		for (int j = 2; j <= i; ++j)
			dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j] * j;
}
int main()
{
	init();
	while (cin >> n && n)
	{
		double res = 0;
		for (int i = 1; i <= n; i++) 
			res += dp[n][i];
		printf("%d %.0f\n", n, res);
	}
}


/*#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N = 1000;
int solve(int x)
{
	if (x <= 1)
		return x;
	else
	    return solve(x - 1) + solve(x-2);
}
int main()
{
	int f[N];
	f[0] = f[1] = 1;
	int n;
	for (int i = 2; i < N; i++)
		f[i] = f[i - 1] + f[i - 2];
	cin >> n;
	cout << "��̬�滮��";
	for (int i = 0; i < n; i++)
		cout << f[i] << ' ';
	puts("");
	cout << "�ݹ�ʽ��";
	for (int i = 1; i <= n; i++)
		cout << solve(i) << ' ';
	puts("");

}

*/