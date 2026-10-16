/*
 * 题目来源：DSX OJ《算法与数据结构实验题 3.9 word》
 * 语言：C++（按 C++17 标准编译验证）
 *
 * 题目大意：
 *   模拟 Word 的输入（input str）、撤销（ctrl+z）、恢复（ctrl+y）三类操作，
 *   按顺序处理 n 条操作后输出文档内容；若文档为空，输出 No output。
 *
 * 解题思路：
 *   用数组 words 当作文档，total 表示文档中当前单词个数。
 *   用数组 removed 当作“撤销栈”，removedTotal 表示栈中元素个数。
 *   被撤销的单词按撤销顺序依次压栈，所以栈顶就是最近一次被撤销的单词。
 *
 *   - input str：把 str 追加到文档末尾，并清空撤销栈。
 *     题目要求“input 操作之前的撤销操作不能被恢复”，因此新的输入会让旧撤销失效。
 *   - ctrl+z：文档非空时，把末尾单词移入撤销栈；文档为空时是非法操作，跳过。
 *   - ctrl+y：撤销栈非空时，把栈顶单词放回文档末尾；栈为空时是非法操作，跳过。
 *   - 其余无法识别的行一律按非法操作跳过。
 *
 * 复杂度：时间复杂度 O(n)，空间复杂度 O(n)，n <= 10000。
 */

#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    string words[10005];   // 当前文档内容，实际长度由 total 决定
    string removed[10005]; // 撤销栈，removedTotal 为栈中元素个数
    int total = 0;
    int removedTotal = 0;

    cin >> n;
    string line;
    getline(cin, line); // 读掉第一行末尾的换行符

    for (int i = 0; i < n; i++)
    {
        getline(cin, line);
        if (!line.empty() && line[line.size() - 1] == '\r')
        {
            line.erase(line.size() - 1); // 兼容 Windows 的 \r\n 换行
        }

        if (line == "ctrl+z")
        {
            // 撤销：把文档最后一个单词压入撤销栈
            if (total > 0)
            {
                removed[removedTotal] = words[total - 1];
                removedTotal++;
                total--;
            }
        }
        else if (line == "ctrl+y")
        {
            // 恢复：把撤销栈顶的单词放回文档末尾
            if (removedTotal > 0)
            {
                words[total] = removed[removedTotal - 1];
                total++;
                removedTotal--;
            }
        }
        else if (line.size() > 6 && line.substr(0, 6) == "input ")
        {
            // 输入：追加单词，并让之前的撤销操作不再可恢复
            words[total] = line.substr(6);
            total++;
            removedTotal = 0;
        }
        // 其他情况属于非法操作，直接跳过
    }

    if (total == 0)
    {
        cout << "No output" << endl;
    }
    else
    {
        for (int i = 0; i < total; i++)
        {
            if (i > 0)
            {
                cout << " ";
            }
            cout << words[i];
        }
        cout << endl;
    }

    return 0;
}
