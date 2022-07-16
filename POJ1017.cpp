#include<iostream>
using namespace std;

int main()
{
    int pack[7];
    int pack1_count, pack2_count;
    int count;
    while (cin >> pack[1] >> pack[2] >> pack[3] >> pack[4] >> pack[5] >> pack[6]) {
        if (pack[1] == 0 && pack[2] == 0 && pack[3] == 0 && pack[4] == 0 && pack[5] == 0 && pack[6] == 0)
        {
            break;
        }
        count = 0;
        count = pack[6] + pack[5] + pack[4] + (pack[3] + 3) / 4;
        pack2_count = 5 * pack[4];
        if (pack[3] % 4 == 3)
        {
            pack2_count += 1;
        }
        else if (pack[3] % 4 == 2)
        {
            pack2_count += 3;
        }
        else if (pack[3] % 4 == 1)
        {
            pack2_count += 5;
        }
        if (pack[2] > pack2_count) {
            count = count + (pack[2] - pack2_count + 8) / 9;
        }
        pack1_count = 36 * count - 36 * pack[6] - 25 * pack[5] - 16 * pack[4] - 9 * pack[3] - 4 * pack[2];
        if (pack[1] > pack1_count)
        {
            count = count + (pack[1] - pack1_count + 35) / 36;
        }
        cout << count << endl;
    }

    return 0;
}
