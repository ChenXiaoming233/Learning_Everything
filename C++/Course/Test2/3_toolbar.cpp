#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 按钮类
class Button
{
public:
    string name;
    string icon;
    Button(string n, string i) : name(n), icon(i) {}
    void click()
    {
        cout << "点击了按钮：" << name << endl;
    }
};

// 分组类
class ToolBarGroup
{
public:
    string groupName;
    vector<Button> buttons; // 所有按钮
    ToolBarGroup(string gn) : groupName(gn) {}

    // 添加按钮
    void add(string name, string icon)
    {
        buttons.push_back(Button(name, icon));
    }

    // 显示按钮
    void show()
    {
        cout << groupName << " 分组包含 " << buttons.size() << " 个按钮：" << endl;
        for (int i = 0; i < buttons.size(); i++)
            cout << buttons[i].name << buttons[i].icon << endl;
    }

    // 点击按钮
    void click(string name)
    {
        for (int i = 0; i < buttons.size(); i++)
            if (buttons[i].name == name)
            {
                buttons[i].click();
                return;
            }
        cout << "未找到按钮：" << name << endl;
    }
};

// 工具栏类
class ToolBar
{
public:
    vector<ToolBarGroup> groups; // 所有分组

    // 添加分组
    void add(string groupName)
    {
        groups.push_back(ToolBarGroup(groupName));
    }

    // 获取最后一个分组
    ToolBarGroup &last()
    {
        return groups.back();
    }

    // 显示工具栏
    void show()
    {
        for (int i = 0; i < groups.size(); i++)
        {
            groups[i].show();
            cout << endl;
        }
    }

    // 点击按钮
    void click(string name)
    {
        for (int i = 0; i < groups.size(); i++)
            groups[i].click(name);
    }
};

int main()
{
    ToolBar toolbar;

    toolbar.add("页");
    toolbar.last().add("封面", "封面图标");
    toolbar.last().add("空白页", "空白页图标");
    toolbar.last().add("分页", "分页图标");

    toolbar.add("表格");
    toolbar.last().add("表格", "表格图标");

    toolbar.add("插图");
    toolbar.last().add("图片", "图片图标");
    toolbar.last().add("剪贴画", "剪贴画图标");
    toolbar.last().add("形状", "形状图标");
    toolbar.last().add("SmartArt", "SmartArt图标");
    toolbar.last().add("图表", "图表图标");
    toolbar.last().add("屏幕截图", "屏幕截图图标");

    toolbar.add("链接");
    toolbar.last().add("超链接", "超链接图标");
    toolbar.last().add("书签", "书签图标");
    toolbar.last().add("交叉引用", "交叉引用图标");

    toolbar.show();

    toolbar.click("SmartArt");
    toolbar.click("超链接");

    return 0;
}
