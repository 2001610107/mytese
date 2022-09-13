
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

