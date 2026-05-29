#ifndef ARRAY_H
#define ARRAY_H

#include <algorithm>

using namespace std;

/*
文件格式：
第一行为一个整数，表示数组中元素的个数；
后面每行为一个元素的值。
*/

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

    // 从文件读取数据的构造函数
    Array(const string &filename)
    {
        // 初始化空数组
        capa = 50;
        sizen = 0;
        data = new T[capa];

        ifstream infile(filename);

        // 打开失败则打开默认文件
        if (!infile.is_open())
        {
            cout << "无法打开给定文件，将打开默认文件" << endl;
            infile.open("c:\\data.txt");
        }

        // 读取数据：第一行是元素个数
        int n;
        infile >> n;

        // 如果读取失败，直接返回
        if (infile.fail() || n <= 0)
        {
            cerr << "警告: 文件格式错误，数组为空" << endl;
            infile.close();
            return;
        }

        // 读取元素
        T value;
        for (int i = 0; i < n; i++)
        {
            infile >> value;
            if (infile.fail()) // 失败则停止
            {
                cerr << "警告: 读取第 " << i + 1 << " 个元素时出错" << endl;
                break;
            }
            push_back(value);
        }
        infile.close();
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