/*
 * 问题描述：输入6个数字，分别代表11,22,33,44,55,66规格的箱子的数目，问最少需要多少个6*6的箱子才可以装完所给各种规格的箱子。
 *
 * 提交状态： 超出时间限制
 *
 * AC 结果： Memory: K Time: MS
 *
 * 解题方法1：利用贪心思想，优先装最大规格的箱子，然后因为在装完较大规格的箱子后，该箱子可以存在剩余空间，所以仍应该利用，且仍旧优先装较小规格中较大的箱子。
 * 6*6：占满，没有剩余。
 * 5*5：装一个，有剩余，还可以装11个1*1规格的箱子。
 * 4*4：装一个后可以最多装从5个2*2规格（优先考虑）到20个1*1规格的箱子。
 * 3*3：当该箱子分别装4,3,2,1个3*3规格后，剩余空间最多可以装0,1,3,5个2*2规格的箱子。
 * 2*2、1*1：优先放进前面各较大规格箱子空间的剩余，不够的话再用新箱子。
 * 解题方法2 （可选）：
 *
 * 出错次数：10
 *
 * 错误原因 （可选）：超出时间限制
 *
 * 心得体会 （可选）：
 */

#include<iostream>
using namespace std;

int main()
{
    int pack[7];
    int pack1_count, pack2_count;
    int u[] = { 0,5,3,1 };
    int count; cin >> pack[1] >> pack[2] >> pack[3] >> pack[4] >> pack[5] >> pack[6];
    while (1) {
        if (pack[1] + pack[2] + pack[3] + pack[4] + pack[5] + pack[6] == 0)
            break;
        count = 0;
        count = pack[6] + pack[5] + pack[4] + (pack[3] + 3) / 4;
        pack2_count = 5 * pack[4] + u[pack[3] % 4];
        if (pack[2] > pack2_count) {
            count = count + (pack[2] - pack2_count + 8) / 9;
        }
        pack1_count = 36 * count - 36 * pack[6] - 25 * pack[5] - 16 * pack[4] - 9 * pack[3] - 4 * pack[2];
        if (pack[1] > pack1_count)
        {
            count = count + (pack[1] - pack1_count + 35) / 36;
        }
        cout << count << endl;
        cin >> pack[1] >> pack[2] >> pack[3] >> pack[4] >> pack[5] >> pack[6];
    }

    return 0;
}
