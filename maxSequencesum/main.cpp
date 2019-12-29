#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int a[1000001];
long maxSum = -10000;

long findMaxSum(int a[], int n)
{
    if(n == 0)
    {

        maxSum = a[n];
        return a[n];
    }
    else
    {
        long temp = max((long)a[n], a[n] + findMaxSum(a, n - 1));
        maxSum = max(maxSum, temp);
        return temp;
    }
}


int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    findMaxSum(a, n - 1);
    cout << maxSum;

    return 0;
}
