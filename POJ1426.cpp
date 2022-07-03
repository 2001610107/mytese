#include "iostream"

#define ll long long
using namespace std;
int n, flag;
ll m;

void DFS(int x, ll m) {
    if (x > 19 || flag == 1)
        return;
    if (m % n == 0) {
        flag = 1;
        cout << m << endl;
        return;
    }
    DFS(x + 1, m * 10);
    DFS(x + 1, m * 10 + 1);

}

int main() {
    while (cin >> n) {
        if (n == 0)
            break;
        flag = 0;
        DFS(1, 1);
    }
}