#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    vector<int> a1;
    vector<int> a2;
    vector<int> a3;
    vector<int> a4;
    vector<int> a5;
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (nums[i] % 5 == 0 and nums[i] % 2 == 0)
            a1.push_back(nums[i]);
        if (nums[i] % 5 == 1)
            a2.push_back(nums[i]);
        if (nums[i] % 5 == 2)
            a3.push_back(nums[i]);
        if (nums[i] % 5 == 3)
            a4.push_back(nums[i]);
        if (nums[i] % 5 == 4)
            a5.push_back(nums[i]);
    }

    int sum1 = 0;
    for (int i = 0; i < a1.size(); i++)
    {
        sum1 += a1[i];
    }

    int sum2 = 0;
    if (!a2.empty())
    {
        a2.push_back(0);
        for (int i = 1; i <= a2.size(); i += 2)
        {
            sum2 += a2[i - 1] - a2[i];
        }
    }
    int num3 = a3.size();

    float avg4 = 0;
    float sum4 = 0;
    for (int i = 0; i < a4.size(); i++)
    {
        sum4 += a4[i];
    }
    avg4 = sum4 / a4.size();

    sort(a5.begin(), a5.end(), greater<int>());

    cout << (a1.size() == 0 ? "N" : to_string(sum1)) << " " << (a2.size() == 0 ? "N" : to_string(sum2)) << " " << (a3.size() == 0.0 ? "N" : to_string(num3)) << " ";
    a4.size() == 0 ? cout << "N " : cout << fixed << setprecision(1) << avg4 << " ";
    cout << (a5.size() == 0 ? "N" : to_string(a5[0]));
}