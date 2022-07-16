/* 问题描述:给出n个数，求中间数。
 *
 * 提交状态： AC 
 *
 * AC 结果： Memory: 252K Time: 63MS
 *
 * 解题方法：求一组数据的中位数，对该组数据进行排序，求出中位数
 *
 * 出错次数：0
 *
 * 错误原因 （可选）：
 *
 * 心得体会 （可选）：这道题虽然花了少时间，但是还是有收获的，debug能力在不断提升
 */

#include<iostream>
#include<algorithm>
using namespace std;
int main() {
    int n;
    cin >> n;
    int* milk = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> milk[i];
    }
    sort(milk, milk + n);
    cout << milk[n / 2];
    delete[] milk;
    milk = NULL;
    return 0;


}
