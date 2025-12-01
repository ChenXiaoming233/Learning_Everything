#include <bits/stdc++.h>

using namespace std;

bool isPrime(int n)
{
    if (n <= 1)
        return false;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
            return false;
    return true;
}

int CountPrime(int n)
{
    vector<bool> isPrimeNum(n, true);
    isPrimeNum[0] = false;
    isPrimeNum[1] = false;
    for (int i = 2; i * i <= n; i++)
    {
        if (isPrimeNum[i])
        {
            for (int j = i * i; j < n; j += i)
            {
                isPrimeNum[j] = false;
            }
        }
    }

    int count = 0;
    for (int i = 2; i < n; i++)
    {
        if (isPrimeNum[i] == true)
        {
            count++;
        }
    }
    return count;
}