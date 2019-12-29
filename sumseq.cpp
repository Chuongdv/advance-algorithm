#include <iostream>

using namespace std;

long long a[1000000];
int main()
{
    long n;
    long long s = 0;
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        if(s > 1000000000)
            s = (s + a[i]) % 1000000007;
        else
            s+= a[i];
    }

    cout << (s%1000000007);
    return 0;
}
