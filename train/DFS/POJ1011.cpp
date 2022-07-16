/*
 * 问题描述：n根不同长度的小棍，拼成若干长棍，并且这些长棍的长度相等，并且小棍刚好用完，问拼成长棍的最短长度是？
 *
 * 提交状态： AC
 *
 * AC 结果： Memory: 244K Time: 16MS
 *
 * 解题方法1：先输入n个小木棍的数量，输入小木棍的长度，对小木棍的长度进行降序排序，并且计算这些木棍总和，拼成的长棍的长度从最长的小棍开始遍历，遍历的过程也是判断，用used[i]
 * 来判断是否访问过i木棍，用L表示原始棍子的长度，最小可能是最长的小木棒的长度，最大可能是所有小木棒的总长的一半，用 L 去遍历试探所有的可能，首先要保证所有小木棍的总长是 L 的倍数，
 * 进行深度递归拽索，终止条件：用完了所有的小木棒。拼凑成的所有的根子的长度都是 L ；
 * 剪枝条件：1.每次次搜索一根小木棍的时候，应该从最近接上去的那条小木棒的下一条小木棒开始找，小木棍i没有使用。并且长度不超过正在拼凑的小木棍的长度
 * 2.小木棍的下标i＞0。且小木棍i - 1没有使用，小本棍i与小木棍i - 1等长，则小木棍无法使用，
 * 3.在剩下的N-1根小木棒中能拼凑出待拼凑的长度为1ength[i］的若干个小木棍子，则拼凑成功。
 *  当尝试了各种可能的长度，都无法找到解，则结果只可能是所有小木棍的总长。
 *
 * 解题方法2 （可选）：
 *
 * 出错次数：8
 *
 * 错误原因 （可选）：对深度递归搜索的搜索过程中判断条件掌握不足
 *
 * 心得体会 （可选）：对深度搜索算法有进一步了解，对深度递归搜索的搜索过程中判断条件能适当地设置，debug能力在不断提升
 */


#include<iostream>
#include<algorithm>
#include<cstring>
#include<functional>
using namespace std;

int *length;//记录木棍长度
bool *used;//记录木棍是否被使用，0表示没有使用，1表示使用
int n;
bool DFS(int N, int M, int L, int StickNo)
{  
	if (N == 0 && M == 0)//遍历完所有的木棍，长度所有的木棍的长度都是L
	{
		return true;
	}
	if (M == 0)//拼完一根木棍则开始拼新的木棍
	{
		M = L;
	}
	int nstartno = 0;
	if (M!= L)
	{
		nstartno = StickNo + 1;
	}
	for (int i = nstartno; i < n; i++)//从下标nstartno开始遍历
	{
		if (!used[i] && length[i] <= M)//木棍没有使用，且长度小于正在拼的木棍长度
		{
			if (i > 0 && used[i - 1] == false && length[i] == length[i - 1])
				//如果木棍的下标i＞0。且小木棍i - 1没有使用，木棍1与木棍i - 1等长，则小木棍同样无法使用
			{
				continue;//试拼下一个木棍
			}
			used[i] = true;//否则，木棍可以继续使用
			if (DFS(N - 1, M - length[i], L, i))//如果在剩下的N-1根小木棒中能拼凑出待拼凑的长度为1ength[i］的若干个小木棍，则拼凑成功
			{
				return true;
			}
			else
			{
				used[i] = false;//本次拼接测试不能是使用木棍i，并且恢复其为未使用状态，开始试拼接下一跟木棍
				if (M == L || length[i] == M)
				{
					return false;
				}
			}
	    }//对木棍i拼接测试结束	
	}//遍历完所有的木棍
	return false;
}
int Dfs()
{
	sort(length, length + n, greater<int>());
	int length_sum = 0;//记录木棍总长度
	for (int i = 0; i < n; i++)
	{
		length_sum += length[i];
	}
	int L = 0;//记录原始木棍长,最小可能为最长木棍长度，最大可能为总长的一半
	for (L = length[0]; L <=length_sum / 2; L++)
	{
		if (length_sum % L)
		{
			continue;
		}
		fill(used, used + n, false);//初始化木棍未被使用
		if (DFS(n, L, L, -1))
		{
			return L;
		}	
	}
	if (L > length_sum / 2)//如果没找到解，那么解只能是所有木棍总长度
	{
		return length_sum;
	}
	return 0;
}
void solve()
{
	while (cin >> n && n > 0)
	{
		length = new int[n];
		 used = new bool[n];
		 for (int i = 0; i < n; i++)
		 {
			 cin >> length[i];
		 }
		 cout << Dfs() << endl;
		 delete [] length;
		 delete [] used;
	}
}
int main()
{
	solve();
	return 0;

}
