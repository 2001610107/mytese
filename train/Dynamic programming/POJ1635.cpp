/* 
 * 问题描述：给定两棵树，用一串0或1的序列表示，0表示生成一个子节点，1表示返回父节点。判断这样的两棵树是否同构。
 *
 * 提交状态： AC
 *
 * AC 结果： Memory: 728K Time:329 MS
 *
* 解题方法1：用树的最小表示求解，将每个子树按字典序排序，最后得到的树如果完全相同，即为同构
 *
 * 解题方法2 （可选）
 *
 * 出错次数：10
 *
 * 错误原因 （可选）：
 *
 * 心得体会 （可选）：
 */


#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;

string solve (string s)
{
	if (!s.size())
		return "";
	vector<string> v;
	int cnt = 0, pre = 0;
	for(int i = 0; i < (int)s.size(); ++i)
	{
		cnt += s[i] == '0' ? 1 : -1;
		if (!cnt)
		{
			v.push_back("0" + solve(s.substr(pre + 1, i - pre - 1)) + "1");
			pre = i + 1;
		}
	}
	
	sort(v.begin(),v.end());
	string res = "";
	for (int i = 0; i < (int)v.size(); ++i)
		res += v[i];
	return res;

}
int main()
{
	string stra, strb;
	int n;
	cin >> n;
	while (n--)
	{
		cin >> stra>> strb;
		puts(solve(stra) == solve(strb) ? "same" : "different");
	}
}

