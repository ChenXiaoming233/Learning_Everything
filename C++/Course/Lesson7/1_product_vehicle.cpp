#include <iostream>
#include <string>

using namespace std;

class Product
{
private:
    string name;
    double weight;
    double length;
    double width;
    double price;
    string brand;

public:
    Product(string n, double w, double l, double wd, double p, string b) : name(n), weight(w), length(l), width(wd), price(p), brand(b) {}

    void show()
    {
        cout << "商品名称: " << name << endl;
        cout << "重量: " << weight << " kg" << endl;
        cout << "长: " << length << " cm" << endl;
        cout << "宽: " << width << " cm" << endl;
        cout << "价格: " << price << " 元" << endl;
        cout << "品牌: " << brand << endl;
    }
};

class Vehicle
{
private:
    string name;
    double weight;
    double speed;
    double length;
    double width;

public:
    Vehicle(string n, double w, double s, double l, double wd) : name(n), weight(w), speed(s), length(l), width(wd) {}

    void show()
    {
        cout << "交通工具名称: " << name << endl;
        cout << "重量: " << weight << " kg" << endl;
        cout << "速度: " << speed << " km/h" << endl;
        cout << "长: " << length << " m" << endl;
        cout << "宽: " << width << " m" << endl;
    }
};

int main()
{
    Product p("手机", 0.2, 15, 7, 2999, "Apple");
    cout << "商品信息：";
    p.show();
    cout << endl;

    Vehicle v("汽车", 1500, 120, 4.5, 1.8);
    cout << "交通工具信息：";
    v.show();
    cout << endl;

    return 0;
}