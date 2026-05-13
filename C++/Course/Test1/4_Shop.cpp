#include <iostream>
#include <string>
using namespace std;

// 服装
class Cloth
{
public:
    string size;
    string color;
    double price;

    Cloth(string s, string c, double p)
    {
        size = s;
        color = c;
        price = p;
    }

    void print()
    {
        cout << "服装 尺码:" << size << " 颜色:" << color << " 价格:" << price << endl;
    }

    double getPrice()
    {
        return price;
    }
};

// 电器
class Elec
{
public:
    string name;
    string size;
    double weight;
    double price;

    Elec(string n, string s, double w, double p)
    {
        name = n;
        size = s;
        weight = w;
        price = p;
    }

    void print()
    {
        cout << "电器 名称:" << name << " 尺寸:" << size << " 重量:" << weight << " 价格:" << price << endl;
    }

    double getPrice()
    {
        return price;
    }
};

// 订单
class Order
{
public:
    Cloth *clothes[100];
    Elec *elecs[100];
    int cloatCount;
    int elecCount;

    Order()
    {
        cloatCount = 0;
        elecCount = 0;
    }

    void addCloth(Cloth &c)
    {
        clothes[cloatCount] = &c;
        cloatCount++;
    }

    void addElec(Elec &e)
    {
        elecs[elecCount] = &e;
        elecCount++;
    }

    double getTotal()
    {
        double total = 0;
        for (int i = 0; i < cloatCount; i++)
            total += (*clothes[i]).getPrice();
        for (int i = 0; i < elecCount; i++)
            total += (*elecs[i]).getPrice();
        return total;
    }

    void printAll()
    {
        cout << "订单商品明细：" << endl;
        for (int i = 0; i < cloatCount; i++)
            (*clothes[i]).print();
        for (int i = 0; i < elecCount; i++)
            (*elecs[i]).print();
        cout << "订单总金额：" << getTotal() << endl;
    }
};

int main()
{
    // 创建商品
    Cloth t1("L", "红色", 99.9);
    Elec e1("电饭煲", "30cm", 2.5, 299);

    Order o;
    o.addCloth(t1);
    o.addElec(e1);

    o.printAll();

    return 0;
}