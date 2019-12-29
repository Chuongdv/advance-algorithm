
#include <iostream>

using namespace std;

/*
long long int result[100][100];


long long int cnk(long long int n, long long int k, long long int m)
{
    if(k == n || k == 0)
    {
        return 1;
    }
    else
    {
        return (cnk(n - 1, k - 1, m) % m + cnk(n - 1, k, m) % m) % m;
    }
}

long long int ckn(long long int n, long long int k, long long int m)
{
    if(k == n || k == 0)
    {
        result[n][k] = 1;
    }
    else
    {
        if(result[n][k] < 0)
            result[n][k] = ckn(n - 1, k - 1, m)+ ckn(n - 1, k, m);
    }

    return result[n][k] % m;
}

*/

int a[1000][1000];

int ckn(int n, int k, int m)
{

    if(k == n || k == 0)
    {
        a[n][k] = 1;
    }
    else
    {
        if(a[n][k] < 0)
            a[n][k] = ckn(n - 1, k - 1, m)+ ckn(n - 1, k, m);
    }

    return a[n][k] % m;
}

int main()
{
    int t;
    int n[1000], k[1000], m[1000];
    cin >> t;
    for(int i = 0; i < t; i++)
    cin >> n[i] >> k[i] >> m[i];

    for(int i = 0; i < t; i ++)
    {
        for(int j = 0; j < n[i] + 1; j++)
        {
            for(int m = 0; m < k[i] + 1; m++)
                a[j][m] = - 1;
        }
        cout << ckn(n[i], k[i], m[i]) << endl;
    }

}
