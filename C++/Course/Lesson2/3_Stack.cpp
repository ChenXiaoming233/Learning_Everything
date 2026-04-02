#include <iostream>
using namespace std;

class Stack
{
private:
    int stack[10000];
    int top;

public:
    Stack()
    {
        top = -1; // 初始化为无效位置
    }
    
    void push(int x)
    {
        if (top < 9999)
        {
            top++;
            stack[top] = x;
        }
        else
            cout << "不行不行要爆炸了" << endl;
    }

    void pop()
    {
        if (top >= 0)
            top--;
        else
            cout << "这里已经空空的了" << endl;
    }

    void print()
    {
        if (top == -1)
        {
            cout << "这里空空的" << endl;
            return;
        }
        for (int i = 0; i <= top; i++)
            cout << stack[i] << " ";
        cout << endl;
    }
};

int main()
{
    Stack stack;

    stack.print();
    stack.pop();

    stack.push(1);
    stack.push(2);

    stack.print();

    stack.pop();

    stack.print();

    return 0;
}