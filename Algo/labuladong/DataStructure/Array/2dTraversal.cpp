// #旋转矩阵 #螺旋矩阵
#include <bits/stdc++.h>

using namespace std;

// 将二维矩阵原地 **顺时针** 旋转 90 度
void rotate(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    // 先沿 **左上 - 右下** 对角线镜像对称二维矩阵
    for (int i = 0; i < n; i++)
    {
        // ! 注意 int j = i
        for (int j = i; j < n; j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    // 然后反转二维矩阵的每一行
    for (int i = 0; i < n; i++)
    {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}


// 将二维矩阵原地 **逆时针** 旋转 90 度
void rotate2(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    // 沿 **左下 - 右上** 对角线镜像对称二维矩阵
    for (int i = 0; i < n; i++)
    {
        // ! 注意 j < n - i
        for (int j = 0; j < n - i; j++)
        {
            swap(matrix[i][j], matrix[n - j - 1][n - i - 1]);
        }
    }
    // 然后反转二维矩阵的每一行
    for (int i = 0; i < n; i++)
    {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}


// 对于任意矩形，不要求原地旋转：
vector<vector<int>> rotateRect(const vector<vector<int>> &matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();
    vector<vector<int>> res(n, vector<int>(m));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // 顺时针旋转 90 度映射
            res[j][m - i - 1] = matrix[i][j];
            // 逆时针旋转 90 度映射
            // res[n - j - 1][i] = matrix[i][j];
            // 旋转 180 度映射
            // res[m - 1 - i][n - 1 - j] = matrix[i][j];
        }
    }
    return res;
}

// 螺旋矩阵遍历
vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    int upper_bound = 0, lower_bound = m - 1;
    int left_bound = 0, right_bound = n - 1;
    vector<int> res;
    // res.size() == m * n 则遍历完整个数组
    while (res.size() < m * n) {
        if (upper_bound <= lower_bound) {
            // 在顶部从左向右遍历
            for (int j = left_bound; j <= right_bound; j++) {
                res.push_back(matrix[upper_bound][j]);
            }
            // 上边界下移
            upper_bound++;
        }
        
        if (left_bound <= right_bound) {
            // 在右侧从上向下遍历
            for (int i = upper_bound; i <= lower_bound; i++) {
                res.push_back(matrix[i][right_bound]);
            }
            // 右边界左移
            right_bound--;
        }
        
        if (upper_bound <= lower_bound) {
            // 在底部从右向左遍历
            for (int j = right_bound; j >= left_bound; j--) {
                res.push_back(matrix[lower_bound][j]);
            }
            // 下边界上移
            lower_bound--;
        }
        
        if (left_bound <= right_bound) {
            // 在左侧从下向上遍历
            for (int i = lower_bound; i >= upper_bound; i--) {
                res.push_back(matrix[i][left_bound]);
            }
            // 左边界右移
            left_bound++;
        }
    }
    return res;
}

