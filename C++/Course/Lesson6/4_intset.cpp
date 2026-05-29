#include <iostream>

using namespace std;

class IntSet
{
private:
    int *data;
    int cap;   // 容量
    int sizen; // 大小

public:
    IntSet() : data(nullptr), cap(0), sizen(0) {}

    // 检查元素唯一性
    bool only(int val) const
    {
        for (int i = 0; i < sizen; i++)
            if (data[i] == val)
                return true;
        return false;
    }

    // 插入元素
    void insert(int val)
    {
        if (only(val))
        {
            cout << "重复元素，不能增加" << endl;
            return;
        }
        if (sizen >= cap)
        {
            cout << "集合已满，无法插入" << endl;
            return;
        }
        data[sizen++] = val;
    }

    // 带参构造
    IntSet(int n) : cap(n), sizen(0)
    {
        data = (n > 0) ? new int[n] : nullptr;
    }

    // 拷贝构造
    IntSet(const IntSet &other) : cap(other.cap), sizen(other.sizen)
    {
        data = (cap > 0) ? new int[cap] : nullptr;
        for (int i = 0; i < sizen; i++)
            data[i] = other.data[i];
    }

    // 赋值
    IntSet &operator=(const IntSet &other)
    {
        delete[] data;
        cap = other.cap;
        sizen = other.sizen;
        if (cap > 0)
        {
            data = new int[cap];
            for (int i = 0; i < sizen; i++)
                data[i] = other.data[i];
        }
        else
            data = nullptr;
        return *this;
    }

    ~IntSet() { delete[] data; }

    // 下标访问
    int &operator[](int index)
    {
        if (index < 0 || index >= sizen)
        {
            cout << "我们的关系越界了！" << endl;
            static int dummy = 0;
            return dummy;
        }
        return data[index];
    }

    // 获取大小
    int size() const { return sizen; }

    // 获取容量
    int capacity() const { return cap; }
};

int main()
{
    IntSet set(10);
    set.insert(1);
    set.insert(2);
    set.insert(3);
    set.insert(3); // 提示不能增加

    for (int i = 0; i < set.size(); i++)
        cout << set[i] << " "; // 输出: 1 2 3

    return 0;
}