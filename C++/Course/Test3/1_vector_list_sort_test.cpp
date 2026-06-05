#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <ctime>
#include <cstdlib>
using namespace std;

void test(int n)
{
    // 创建测试对象
    vector<int> vi0(n);
    for (int i = 0; i < n; i++)
        vi0[i] = rand();
    vector<int> vi = vi0;
    list<int> li(vi0.begin(), vi0.end());

    // 测试 vector
    int start = clock();
    sort(vi.begin(), vi.end(), greater<int>());
    int end = clock();
    cout << "n=" << n << "时，vector 排序用时: " << (double)(end - start) / 1000 << "s" << endl;

    // 测试 list
    li.assign(vi0.begin(), vi0.end());
    start = clock();
    sort(li.begin(), li.end(), greater<int>());
    end = clock();
    cout << "n=" << n << "时，list 排序用时:   " << (double)(end - start) / 1000 << "s" << endl;

    // 测试 list 复制到 vector 再排序再复制回 list
    li.assign(vi0.begin(), vi0.end());
    start = clock();
    vi.assign(li.begin(), li.end());
    sort(vi.begin(), vi.end(), greater<int>());
    li.assign(vi.begin(), vi.end());
    end = clock();
    cout << "n=" << n << "时，交换与排序操作用时：" << (double)(end - start) / 1000 << "s" << endl;
}

int main()
{
    test(100000);
    test(1000000);
    test(10000000);
    return 0;
}
