#include<iostream>
#include<queue>
typedef long long ll;
using namespace std;

int  solution()
{
	int n, length;
  	cin >> n;
	priority_queue<int, vector<int>, greater<int>>q;
	for (int i = 0; i < n; i++)
	{
		cin >> length;
		q.push(length);
	}
	if (q.size() == 1)
	{
		cout << q.top();
		return 0;
	}
	ll ans = 0;
	while (q.size() != 1)
	{
		ll min_1, min_2;
		min_1 = q.top();
		q.pop();
		min_2 = q.top();
		q.pop();
		ans += min_1 + min_2;
		q.push(min_1 + min_2);
	}
	cout << ans << endl;
	return 0;
}
int main()
{
	solution();
}
