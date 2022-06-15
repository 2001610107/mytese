#include<iostream>
#define MAX 500001
using namespace std;
typedef long long ll;
ll sum;
ll s[MAX], tmp[MAX];
ll mergesort(ll* s,ll *tmp, int left,int mid,int right)
{
	int i = left;
	int j = mid + 1;
	int index = left;
	ll sum=0;
	while (i <= mid && j <= right) {
		if (s[i] >s[j]) {
			tmp[index++] = s[j];
			j++;
			sum = sum + mid - i + 1;
		}
		else {
			tmp[index++] = s[i];
			i++;
		}
	}
	while (i <= mid)
	{
		tmp[index++] = s[i++];
	}
	while (j <= right)
	{
		tmp[index++] = s[j++];
	}
	for (int i = left; i <= right; i++)
	{
		s[i] = tmp[i];
	}
	return sum;
}
ll solution(ll* s,ll*tmp, int left, int right)
{
	if (left >=right) return 0;
	int mid = (left + right) / 2;
	ll sum = 0;
	sum += solution(s, tmp, left, mid);
	sum += solution(s,tmp, mid + 1, right);
	sum += mergesort(s, tmp,left, mid, right);
	return sum;
}
int main()
{
	int  n;
	while (cin >> n)
	{
		if (!n) {
			break;
		}
		for (int i = 1; i <=n; i++)
		{
			cin >> s[i];
		}
		cout<<solution(s,tmp,1, n)<<endl;


	}
}
