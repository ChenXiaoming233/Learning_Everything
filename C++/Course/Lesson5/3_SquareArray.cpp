#include <iostream>
#include <algorithm>
using namespace std;

class Square
{
private:
    double side;

public:
    Square(double s = 0) : side(s) {}

    double getSide() const { return side; }

    void print() const
    {
        cout << side;
    }
};

class SquareArray
{
private:
    Square *data;
    int cap;

public:
    SquareArray() : data(nullptr), cap(0) {}

    SquareArray(int n) : cap(n)
    {
        if (n > 0)
            data = new Square[n];
        else
            data = nullptr;
    }

    // 拷贝构造
    SquareArray(const SquareArray &other) : cap(other.cap)
    {
        data = (cap > 0) ? new Square[cap] : nullptr;
        for (int i = 0; i < cap; i++)
            data[i] = other.data[i];
    }

    // 赋值
    SquareArray &operator=(const SquareArray &other)
    {
        delete[] data;
        cap = other.cap;
        if (cap > 0)
        {
            data = new Square[cap];
            for (int i = 0; i < cap; i++)
                data[i] = other.data[i];
        }
        else
            data = nullptr;
        return *this;
    }

    ~SquareArray() { delete[] data; }

    void resize(int newSize)
    {
        Square *newData = (newSize > 0) ? new Square[newSize] : nullptr;
        int copyCount = (newSize < cap) ? newSize : cap;
        for (int i = 0; i < copyCount; i++)
            newData[i] = data[i];
        delete[] data;
        data = newData;
        cap = newSize;
    }

    Square &operator[](int index)
    {
        if (index < 0 || index >= cap)
        {
            cout << "我们的关系越界了！" << endl;
            static Square dummy;
            return dummy;
        }
        return data[index];
    }

    // 获取当前大小
    int size() const
    {
        return cap;
    }

    // 排序正方形对象
    static bool compareBySide(const Square &a, const Square &b)
    {
        return a.getSide() < b.getSide();
    }

    void sort()
    {
        std::sort(data, data + cap, compareBySide);
    }
};

int main()
{
    Square s1(4);
    Square s2(6);
    SquareArray arr(2);
    arr[0] = s2;
    arr[1] = s1;
    arr.sort();
    for (int i = 0; i < arr.size(); i++)
        arr[i].print();

    return 0;
}