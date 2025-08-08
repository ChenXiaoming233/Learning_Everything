# Sorting_排序

## 快速排序

```C++
#include <iostream>
#include <vector>
#include <algorithm>  

using namespace std;

int medianThree(vector<int>& nums, int left, int right) {
    int mid = (left + right) / 2;
    int l = nums[left];
    int m = nums[mid];
    int r = nums[right];
    if ((l < m && m < r) || (r < m && m < l)) {
        return mid;
    }
    else if ((m < l && l < r) || (r < l && l < m)) {
        return left;
    }
    else {
        return right;
    }
}

int partition(vector<int>& nums, int left, int right) {
    int med = medianThree(nums, left, right);
    swap(nums[med], nums[left]);
    int i = left;
    int j = right;
    while (i < j) {
        while (i < j && nums[j] >= nums[left]) {
            j--;
        }
        while (i < j && nums[i] <= nums[left]) {
            i++;
        }
        swap(nums[i], nums[j]);
    }
    swap(nums[left], nums[i]);
    return i;
}

void quickSort(vector<int>& nums, int left, int right) {
    while (left < right) {
        int pivot = partition(nums, left, right);
        if (pivot - left < right - pivot) {
            quickSort(nums, left, pivot - 1);
            left = pivot + 1;
        }
        else {
            quickSort(nums, pivot + 1, right);
            right = pivot - 1;
        }
    }
}

int main() {
    int n = 0;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    
    quickSort(nums, 0, n - 1);
    
    for (int i = 0; i < n; i++) {
        if (i < n - 1) {
            cout << nums[i] << " ";
        }
        else {
            cout << nums[i];
        }
    }
    return 0;
}
```



## STL:sort

我们设我们排序的数组为 a，排序区间为 [l,r)（即所有满足 l≤x<r 的整数 x），且从小到大排序。则调用方法为：
`sort(a + l, a + r)。`

> *应该在头文件中加上 #include <algorithm> 或者 #include <bits/stdc++.h>（万能头文件）*

### cmp 外部比较函数

如果我们不想从小到大排序，而是想从大到小排序，或者以其他方式进行排序，那么我们就应该写一个比较函数（一般命名为 `cmp`）来改变排序方法。

比较函数是一个独立的函数， *定义两个与数组类型相同的变量作为参数，再返回两个数字的比较就可以了* 。例如我们想要把一个类型为 int 的数组从大到小排序，我们应该这么定义这个比较函数：

```C++
bool cmp(int a, int b){
	return a > b;
}
```
如果是从小到大排序，就用小于号连接两数；如果是从大到小排序，就用大于号连接两数。*注意比较函数中的大于号、小于号不应改为大于等于号、小于等于号*，否则会出现栈溢出等问题，导致意外的结果（例如运行时错误）。

写完这个函数，只需要在调用 sort 函数时在第三个参数写上函数名就可以了：
```c++
sort(a + l, a + r, cmp);
```

同样，结构体也可以用它排序。

```c++
struct node{
	int x, y;
}c[1005]; // 定义结构体

bool cmp(node a, node b){
	if(a.x != b.x){ // 如果两个 x 不等则以 x 的大小排序
		return a.x > b.x;
	}
	return a.y > b.y; // 否则以 y 的大小排序
}

sort(c + 1, c + 1001, cmp);

```

### 重载运算符

重载运算符存在于结构体内部，相对于比较函数来说虽然难写，不过速度确实快了很多。在比较函数排序中，每一次比较都要拷两个结构体过去，这样的速度是非常慢的；如果是重载运算符，比较规则就本身就在结构体里面了，排序的时间会很快。

重载小于运算符的模板：

```c++
bool operator<(const Node &other)const{
		return a<other.a; // a 是要比较的元素
}
```

`operator<`: 重载运算符的特殊语法，表示要重载`<`运算符；

`(const Person& other)`: 参数列表，表示我们要与另一个`Person`对象`"other"`比较；

`const`: 表示这个成员函数不会修改当前对象的任何成员变量；

应用重载运算符的结构体：

```c++
struct Node{
	double x,y,z;
	bool operator<(const Node &other)const{ // 重载小于运算符
		return z<other.z;
	}
} 
```

### 比较大数

可以通过`string`存储`long long `都无法存储的大数。

如果直接 `return a.count > b.count`，由于 `string` 的比较运算符 `>` 是按字典序而非数值来比较大小，例如：`"99" > "100" → true`（因为 ``'9' > '1'``），但实际上 `99 < 100`。

```c++
bool cmp(const Person& a, const Person& b){
    if (a.count.length() != b.count.length()){
        return a.count.length() > b.count.length(); // 先比较 string 长度（即数字位数）
    }
    return a.count > b.count; // 位数相同，直接比较字符串（字典序降序）
}
```



