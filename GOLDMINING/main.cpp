#include <bits/stdc++.h>

using namespace std;

int a[100001];
long memo[100001];


int main()
{
    int n, l1, l2;
    cin >> n >> l1 >> l2;
    for(int i = 0; i < n; i++)
    {
         cin >> a[i];

    }

    for(int i = 0; i < l1; i++)
    {
         memo[i] = a[i];
    }
    long maxximum = 0;

    for(int i = 0; i < n; i++)
    {

        for(int j = l1; j <= l2; j++)
        {
            if((i-j) >= 0)
                memo[i] = max((memo[i - j] + a[i]), memo[i]);
        }
        maxximum = max(maxximum, memo[i]);
    }

    cout << maxximum;


}
