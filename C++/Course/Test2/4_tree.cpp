#include <iostream>
#include <string>
#include <map>
using namespace std;

class TreeNode
{
public:
    bool isLeaf;                 // 是否为叶子节点
    string leafResult;           // 叶子节点的判别结果
    string innerName;            // 内部节点的属性名
    map<string, TreeNode *> sub; // 子节点映射

    TreeNode() : isLeaf(true) {}

    // 添加子节点
    void add(string value, TreeNode *sub1)
    {
        sub[value] = sub1;
    }

    // 遍历到叶子节点
    string search(string color, string size, string action, string age)
    {
        // 叶子节点，直接返回判别结果
        if (isLeaf)
            return leafResult;

        // 根据属性名选取属性值
        string value;
        if (innerName == "颜色")
            value = color;
        else if (innerName == "尺寸")
            value = size;
        else if (innerName == "行为")
            value = action;
        else if (innerName == "年龄")
            value = age;
            
        return sub[value]->search(color, size, action, age);
    }
};

// 创建叶子节点
TreeNode *addLeaf(string result)
{
    TreeNode *node = new TreeNode();
    node->isLeaf = true;
    node->leafResult = result;
    return node;
}

// 创建一个内部节点
TreeNode *addNode(string attribute)
{
    TreeNode *node = new TreeNode();
    node->isLeaf = false;
    node->innerName = attribute;
    return node;
}

TreeNode *buildTree()
{
    // 根节点
    TreeNode *root = addNode("颜色");

    // 紫色分枝
    // 紫色 -> 行为
    TreeNode *purpleAction = addNode("行为");
    purpleAction->add("DIP", addLeaf("不会")); // 按压 -> 不会
}

int main()
{
    TreeNode *tree = buildTree();

    // 16组测试数据（与题目表格一致）
    // 最后一列：T = 会，F = 不会
    string colors[] = {"YELLOW", "YELLOW", "YELLOW", "YELLOW",
                       "YELLOW", "YELLOW", "YELLOW", "YELLOW",
                       "PURPLE", "PURPLE", "PURPLE", "PURPLE",
                       "PURPLE", "PURPLE", "PURPLE", "PURPLE"};
    string sizes[] = {"SMALL", "SMALL", "SMALL", "SMALL",
                      "LARGE", "LARGE", "LARGE", "LARGE",
                      "SMALL", "SMALL", "SMALL", "SMALL",
                      "LARGE", "LARGE", "LARGE", "LARGE"};
    string actions[] = {"STRETCH", "STRETCH", "DIP", "DIP",
                        "STRETCH", "STRETCH", "DIP", "DIP",
                        "STRETCH", "STRETCH", "DIP", "DIP",
                        "STRETCH", "STRETCH", "DIP", "DIP"};
    string ages[] = {"ADULT", "CHILD", "ADULT", "CHILD",
                     "ADULT", "CHILD", "ADULT", "CHILD",
                     "ADULT", "CHILD", "ADULT", "CHILD",
                     "ADULT", "CHILD", "ADULT", "CHILD"};
    string actual[] = {"T", "F", "F", "F", "T", "F", "F", "F",
                       "T", "F", "F", "F", "T", "F", "F", "F"};

    return 0;
}
