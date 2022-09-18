
/*
 * �����������������໥����ĺӰ�X,Y,Z��ÿ�����Ϸֱ���n,m,p�����䣬ÿ���Ӱ��ϵĲ���֮���ǵжԵģ���ͬһ���Ӱ��ϵĲ���֮�䲻����ͨ����
 Ȼ����λ�ڲ�ͬ�Ӱ��ϵ�������������֮�䶼���Ѻõģ����������ڲ���֮�����������ܽ��棩��
 ÿ���ŵķ�����������ĺ��β�ľ���ֵ����ʹ��ÿһ�����䶼��������һ�������Ѻò�����ͨ ���ŵ��ܷ��á�
 *
 * �ύ״̬�� AC
 *
 * AC ����� Memory: 540K Time: 63MS
 *
 * ���ⷽ��1��1����������������顣dp[i][j]��ʾһ��ƥ�䵽i����һ��ƥ�䵽j����������������������
 *
 * ���ⷽ��2 ����ѡ����
 *
 * ���������10
 *
 * ����ԭ�� ����ѡ����
 *
 * �ĵ���� ����ѡ����
 */

#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>

using namespace std;
const int N = 150;
void DP()
{
	int m, n, p;
	int x[N], y[N],z[N];
	int xy[N][N], xz[N][N], yz[N][N];
	cin >> m >> n >> p;
	for (int i = 1; i <= n; i++)cin >> x[i];
	for (int i = 1; i <= m; i++) cin >> y[i];
	for (int i = 1; i <= p; i++) cin>>z[i];
	for (int i = 0; i < 150; i++)
		for (int j = 0; j < 150; j++)
			xz[i][j] = xy[i][j] = yz[i][j] = 999999;
	int res = 999999;

	
	xz[0][p + 1] = 0;
	for (int i = 1; i <= n; i++)
		for (int j = p; j >= 1; j--)
			xz[i][j] = min(min(xz[i - 1][j + 1], xz[i - 1][j]), xz[i][j + 1]) + abs(x[i] - z[j]);
	xy[n + 1][0] = 0;
	for (int i = n; i >= 1; i--)
		for (int j = 1; j <= m; j++)
			xy[i][j] = min(min(xy[i + 1][j - 1], xy[i + 1][j]), xy[i][j - 1]) + abs(x[i] - y[j]);
	yz[m + 1][0] = 0;
	for (int i = m; i >= 1; i--)
		for (int j = 1; j <= p; j++)
			yz[i][j] = min(min(yz[i + 1][j - 1], yz[i + 1][j]), yz[i][j - 1]) + abs(y[i] - z[j]);

	for (int i = 0; i <= n + 1; i++)
		for (int j = 0; j <= m + 1; j++)
			for (int k = 0; k <= p + 1; k++)
			{
				res = min(res, xy[i][j] + xz[i][k] + yz[j][k]);
				res = min(res, xy[i][j] + xz[i][k] + yz[j + 1][k]);
				res = min(res, xy[i + 1][j] + xz[i][k] + yz[j][k]);
				res = min(res, xy[i][j] + xz[i][k + 1] + yz[j][k]);
				res = min(res, xy[i + 1][j] + xz[i][k] + yz[j + 1][k]);
				res = min(res, xy[i][j] + xz[i][k + 1] + yz[j + 1][k]);
				res = min(res, xy[i + 1][j] + xz[i][k + 1] + yz[j][k]);
				res = min(res, xy[i + 1][j] + xz[i][k + 1] + yz[j + 1][k]);
				
			}


	cout << res << endl;
}
int main()
{
	int tt;
	cin >> tt;
	while (tt--)
	{
		DP();
	}
	return 0;
}