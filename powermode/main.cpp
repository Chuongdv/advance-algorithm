#include <iostream>

using namespace std;

/*
long int res[10000];

long int power(int a, int b)
{
    int c = b%2;
    int d = b/2;
    if(b == 0)
    {
      return 1;
    }
    if(b == 1)
    {
        return a;
    }

    if(res[d] == 0)
    {
        res[d] = power(a, d);
    }

    if(c == 0)
    {
        res[b] = (res[d]*res[d]) % 1000000007;
    }
    else
        res[b] = (a*res[d] % 1000000007) *(res[d] % 1000000007) % 1000000007;

    return res[b];

}
*/


long powmod(long a, long b)
{
    long result = 1;

    unsigned long long p = a % 1000000007;
    b = b % 1000000007;

   // unsigned long long  p = a;

    while(b)
    {
        if(b%2)
        {
            result = (result*p) % 1000000007;
        }
        p = (p*p) % 1000000007;
        b /= 2;
    }
    return result;
}


int main()
{
    long a, b;
    cin >> a >> b;
    cout << powmod(a, b);
    return 0;
}
