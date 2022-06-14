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