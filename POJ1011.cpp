#include<iostream>
#include<algorithm>

using namespace std;
int a[100], Min = 0, n, sum;
bool visited[100];

bool cmp(int i, int j) {
    return  i> j;
}

bool dfs(int index, int cur, int total) {
    if (total == Min)
        return true;
    for (int i = index; i < n; i++)
        if (!visited[i] && a[i] <= cur) {
            visited[i] = true;
            if (a[i] == cur) {
                if (dfs(1, Min, total - a[i]))
                    return true;
            } else if (dfs(i + 1, cur - a[i], total - a[i]))
                return true;
            visited[i] = false;
            if (a[i] == cur)
                return false;
            if (cur == Min)
                return false;
            while (a[i] == a[i + 1])
                i++;
        }
    return false;
}

int main() {
    while (cin >> n && n != 0) {
        sum = 0;
        for (int i = 0; i < 100; i++)
            visited[i] = false;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            sum += a[i];
        }
        sort(a, a + n, cmp);
        for (Min = a[0]; Min <= sum; Min++) {
            if (sum % Min == 0 && dfs(0, Min, sum)) {
                cout << Min << endl;
                break;
            }
        }
    }
}
