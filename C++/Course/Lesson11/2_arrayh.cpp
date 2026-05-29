#ifndef ARRAY_H
#define ARRAY_H

#include <algorithm>

using namespace std;

template <class T>
class Array
{
private:
    T *data;   // 指向动态数组的指针
    int capa;  // 数组容量
    int sizen; // 数组大小

public:
    // 构造函数
    Array(int cap = 50)
    {
        capa = cap; // 记录总容量
        sizen = 0;
        data = new T[capa]; // 堆上分配内存
    }

    // 析构函数
    ~Array()
    {
        delete[] data;
    }

    // 拷贝构造函数
    Array(const Array &other)
    {
        capa = other.capa;
        sizen = other.sizen;

        data = new T[capa];

        // 深拷贝
        for (int i = 0; i < sizen; i++)
            data[i] = other.data[i];
    }

    // 赋值运算符重载
    Array &operator=(const Array &other)
    {
        delete[] data;

        capa = other.capa;
        sizen = other.sizen;
        data = new T[capa];
        for (int i = 0; i < sizen; i++)
            data[i] = other.data[i];

        return *this;
    }

    // 下标运算符重载
    const T &operator[](int index) const
    {
        if (index < 0 || index >= sizen)
            throw "Index out of range!"; // 抛异常
        return data[index];
    }

    // 获取大小
    int size() const
    {
        return sizen;
    }

    // 尾增元素
    void push_back(const T &value)
    {
        // 检查是否需要扩容
        if (sizen == capa)
            resize(capa * 2);
        data[sizen] = value;
        sizen++;
    }

    // 调整容量
    void resize(int newcapa)
    {
        // 新容量不能小于当前元素个数
        if (newcapa <= sizen)
            return;

        T *newData = new T[newcapa];

        for (int i = 0; i < sizen; i++)
            newData[i] = data[i];

        delete[] data;
        data = newData;
        capa = newcapa;
    }
};

#endif