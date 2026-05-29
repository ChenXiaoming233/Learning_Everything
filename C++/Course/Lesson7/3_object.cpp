#include <iostream>
#include <string>

using namespace std;

// 物体类
class Object
{
protected:
    string name;
    double weight;
    double length;
    double width;

public:
    Object(string n, double wt, double l, double wd)
        : name(n), weight(wt), length(l), width(wd) {}

    void show()
    {
        cout << "名称: " << name << endl;
        cout << "重量: " << weight << " kg" << endl;
        cout << "长: " << length << " cm" << endl;
        cout << "宽: " << width << " cm" << endl;
    }
};

// 商品类，虚继承Object
class Product : virtual public Object
{
protected:
    double price;
    string brand;

public:
    Product(string n, double wt, double l, double wd, double p, string b)
        : Object(n, wt, l, wd), price(p), brand(b) {}

    void show()
    {
        Object::show();
        cout << "价格: " << price << " 元" << endl;
        cout << "品牌: " << brand << endl;
    }
};

// 交通工具类，虚继承Object
class Vehicle : virtual public Object
{
protected:
    double speed;

public:
    Vehicle(string n, double wt, double l, double wd, double s)
        : Object(n, wt, l, wd), speed(s) {}

    void show()
    {
        Object::show();
        cout << "速度: " << speed << " km/h" << endl;
    }
};

// 汽车类
class Car : public Product, public Vehicle
{
public:
    Car(string n, double wt, double l, double wd, double p, string b, double s)
        : Object(n, wt, l, wd),
          Product(n, wt, l, wd, p, b),
          Vehicle(n, wt, l, wd, s) {}

    void show()
    {
        Object::show();
        Product::show();
        Vehicle::show();
    }
};

int main()
{
    Product p("手机", 0.2, 15, 7, 2999, "Apple");
    cout << "商品信息：" << endl;
    p.show();
    cout << endl;

    Vehicle v("汽车", 1500, 450, 180, 120);
    cout << "交通工具信息：" << endl;
    v.show();
    cout << endl;

    Car car("轿车", 1500, 450, 180, 200000, "Tesla", 180);
    cout << "汽车信息：" << endl;
    car.show();
    cout << endl;

    return 0;
}