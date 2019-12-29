#include <iostream>

using namespace std;

int main()
{
    unsigned long long int a, b;
    cin >> a >> b;

    cout << ((a % 1000000007 + b % 1000000007) % 1000000007) << endl;
    return 0;
}
