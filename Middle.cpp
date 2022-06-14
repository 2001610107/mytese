/*
FJ is surveying his herd to find the most average cow. He wants to know how much milk this 'median' cow gives: half of the cows give as much or more than the median; half give as much or less.
Given an odd number of cows N (1 <= N < 10,000) and their milk output (1..1,000,000), find the median amount of milk given such that at least half the cows give the same amount of milk or more and at least half give the same or less.
Input
* Line 1: A single integer N
* Lines 2..N+1: Each line contains a single integer that is the milk output of one cow.

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
