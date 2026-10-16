#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<long long> w(n + 2, -1);
    vector<long long> prefix(n + 1, 0);
    for (int i = 1; i <= n; ++i)
    {
        cin >> w[i];
        prefix[i] = prefix[i - 1] + w[i];
    }

    long long answer = 0;
    stack<int> indices;
    indices.push(0);

    for (int i = 1; i <= n + 1; ++i)
    {
        while (indices.top() != 0 && w[indices.top()] >= w[i])
        {
            int position = indices.top();
            indices.pop();

            int left = indices.top() + 1;
            int right = i - 1;
            long long sum = prefix[right] - prefix[left - 1];
            answer = max(answer, w[position] * sum);
        }
        indices.push(i);
    }

    cout << answer << '\n';
    return 0;
}
