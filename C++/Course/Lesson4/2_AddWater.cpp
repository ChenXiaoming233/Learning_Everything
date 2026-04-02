#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Cup
{
private:
    double current;  // 当前水量
    double capacity; // 最大容量
    int count;       // 加水次数

public:
    Cup(double curr, double capa)
    {
        if (curr < 0)
            current = 0; // 防止初始水量为负数
        else
            current = curr;
        capacity = capa;
    }

    // 判断是否已满
    bool isFull()
    {
        return current >= capacity;
    }

    // 加水
    double addWater(double v)
    {
        double space = capacity - current; // 剩余空间
        double add;

        if (v <= space)
            add = v;
        else
            // 水会溢出，只能加到满
            add = space;

        current += add;
        count++;
        return add;
    }
};

int main()
{
    double initWater, maxCapacity;
    cin >> initWater >> maxCapacity;

    Cup cup(initWater, maxCapacity);

    // 随机数种子
    srand(time(0));

    // 如果初始已满不加水
    if (cup.isFull())
    {
        cout << "总共加水次数：0次" << endl;
        return 0;
    }

    // 循环加水直到满
    int times = 1;
    while (!cup.isFull())
    {
        double addVol = rand() % 5 + 1;          // 随机加1-5升的水
        double actualAdd = cup.addWater(addVol); // 实际加水量
        times++;
        cout << "第" << times << "次加水：" << actualAdd << "升" << endl;
    }

    cout << "总共加水次数：" << times << "次" << endl;

    return 0;
}