#include <iostream>

using namespace std;

class IntArray
{
private:
    int *data;
    int cap; // 容量

public:
    IntArray() : data(nullptr), cap(0) {}

    // 带参构造
    IntArray(int n) : cap(n)
    {
        if (n > 0)
        {
            data = new int[n];
            for (int i = 0; i < n; i++)
                data[i] = 0;
        }
        else
            data = nullptr;
    }

    // 拷贝构造
    IntArray(const IntArray &other) : cap(other.cap)
    {
        data = (cap > 0) ? new int[cap] : nullptr;
        for (int i = 0; i < cap; i++)
            data[i] = other.data[i];
    }

    // 赋值
    IntArray &operator=(const IntArray &other)
    {
        delete[] data;
        cap = other.cap;
        if (cap > 0)
        {
            data = new int[cap];
            for (int i = 0; i < cap; i++)
                data[i] = other.data[i];
        }
        else
            data = nullptr;
        return *this;
    }

    ~IntArray() { delete[] data; }

    // 重置大小
    void resize(int newSize)
    {
        int *newData = (newSize > 0) ? new int[newSize]() : nullptr;
        int copyCount = (newSize < cap) ? newSize : cap;
        for (int i = 0; i < copyCount; i++)
            newData[i] = data[i];
        delete[] data;
        data = newData;
        cap = newSize;
    }

    // 下标访问
    int &operator[](int index)
    {
        if (index < 0 || index >= cap)
        {
            cout << "我们的关系越界了！" << endl;
            static int dummy = 0;
            return dummy;
        }
        return data[index];
    }

    // 获取大小
    int size() const { return cap; }
};

// 以下为主函数
int main()
{
    IntArray arr;      // 建立存储空间为0的数组对象
    arr[1] = 10;       // 对下标1位置的数组元素进行赋值操作；程序应提示越界访问
    arr.resize(10);    // 把存储空间增大为10，即可以存10个整型数值；注：存储空间的大小可增大，也可缩小
    IntArray arr2(20); // 建立存储空间为20的数组对象
    for (int i = 0; i < arr2.size(); i++)
        arr2[i] = i;
    arr = arr2;                          // 把arr2对象的内容复制给arr对象
    for (int i = 0; i < arr.size(); i++) // 打印输出arr里的数据，即0,1,2,3…19
        cout << arr[i] << ",";

    return 0;
}
