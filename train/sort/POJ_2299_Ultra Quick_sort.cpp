
/** 问题描述：给出长度为n的序列，每次只能交换相邻的两个元素，至少要交换几次才使得该序列为递增序列。
 *
 * 提交状态： AC 
 *
 * AC 结果： Memory: 7268K Time: 1313MS
 
 * 解题方法：使用归并排序算法，分而治之，不断将数组从中间位置分开（二分法），将整个数组的排序问题转化为子数组的排序问题。
 *当划分到子数组的长度为1时，开始向上合并，不断将已排序子数组合并。合并两个排序数组的过程中，而每当遇到左子数组当前元素 > 右子数组当前元素时，
 *意味着 「左子数组当前元素 至 末尾元素」 与 「右子数组当前元素」 构成了若干 「逆序对」 
 *考虑在归并排序的合并阶段统计「逆序对」数量，完成归并排序时，也随之完成所有逆序对的统计。
 * 出错次数：3
 *
 * 错误原因 （可选）：对数据长度使用不够熟悉
 *
 * 心得体会 （可选）：这道题虽然花了不少时间，但是还是有收获的，debug能力在不断提升
 */
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
