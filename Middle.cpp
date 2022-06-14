/*
FJ is surveying his herd to find the most average cow. He wants to know how much milk this 'median' cow gives: half of the cows give as much or more than the median; half give as much or less.
Given an odd number of cows N (1 <= N < 10,000) and their milk output (1..1,000,000), find the median amount of milk given such that at least half the cows give the same amount of milk or more and at least half give the same or less.
Input
* Line 1: A single integer N
* Lines 2..N+1: Each line contains a single integer that is the milk output of one cow.
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
