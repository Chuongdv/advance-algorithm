#include <iostream>

using namespace std;

int main()
{
    int a, b;
    long long exp = 1;

    for(int i = 0; i < b; i++)
    {
        exp *= a;
        if(exp > 1000000007)
            exp %= 1000000007;
    }
    return 0;
}
