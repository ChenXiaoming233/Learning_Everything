#include <iostream>
using namespace std;

class Stack
{
private:
    int *data;    // 动态数组存储栈元素
    int top;      // 栈顶索引
    int capacity; // 容量

public:
    // 构造函数
    Stack()
    {
        capacity = 10;
        data = new int[capacity];
        top = -1;
    }

    // 拷贝构造函数
    Stack(const Stack &other)
    {
        cout << "Copy stack" << endl;
        capacity = other.capacity;
        top = other.top;
        data = new int[capacity];
        for (int i = 0; i <= top; i++)
            data[i] = other.data[i];
    }

    // 析构函数
    ~Stack()
    {
        cout << "Delete stack, size=" << top + 1 << endl;
        delete[] data;
    }

    // 入栈
    void push(int value)
    {
        if (top + 1 == capacity)
        {
            // 扩容
            capacity *= 2;
            int *newData = new int[capacity];
            for (int i = 0; i <= top; i++)
                newData[i] = data[i];
            delete[] data;
            data = newData;
        }
        top++;
        data[top] = value;
    }

    // 出栈
    void pop()
    {
        if (top >= 0)
            top--;
    }

    // 打印
    void print()
    {
        for (int i = 0; i <= top; i++)
        {
            cout << data[i];
            if (i < top)
                cout << ", ";
        }
        cout << endl;
    }
};

int main()
{
    Stack stack;
    stack.push(1);
    stack.push(2);

    Stack stack2 = stack; // 打印输出：Copy stack
    stack2.push(3);
    stack2.push(4);
    stack.print();  // 打印输出：2, 1
    stack2.print(); // 打印输出：4, 3, 2, 1

    return 0;
    // 程序结束时会自动调用析构函数，输出：
    // Delete stack, size=4
    // Delete stack, size=2
}