/*
 * ������������n�����񣬵�i��������Ҫʱ��xi����ɣ�
 *  ���ҵ�i������������� ��ǰ��ġ� ĳЩ�������֮����ܿ�ʼ
 *  ����������Ϣ�����������Ҫ����ʱ�����������
 *
 * �ύ״̬�� AC
 *
 * AC ����� Memory: 308K Time: 1563MS
 *
 * ���ⷽ��1����һ������dp������ɵ�i������ʱ�������̵�ʱ�䣬dp[i] = max��dp[j]) +time�� 
 j����Ҫ����ǰ����ɵ��������ţ�time����ɵ�ǰ��������ʱ�䡣
 *
 *
 * ���ⷽ��2 ����ѡ����
 *
 * ���������8
 *
 * ����ԭ�� ����ѡ����
 *
 * �ĵ���� ����ѡ����
 */


#include <iostream>
#include <algorithm>
using namespace std;
 
int dp[10008]; 
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int w, m;
		cin >> w >> m;
		if (m == 0)
		{
			dp[i] = w;
		}
		for (int j = 0; j < m; j++)
		{
			int p;
			cin >> p;
			if (dp[i] < (dp[p] + w))
			{
				dp[i] = (dp[p] + w);
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		if (ans < dp[i])
		{
			
			ans = dp[i];
		}
		//cout<<i<<" "<<dp[i]<<endl;
	}
	cout << ans << endl;
	return 0;
}