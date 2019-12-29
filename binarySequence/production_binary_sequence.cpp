#include <iostream>
#include <string>

using namespace std;

string a;
void production(int n)
{
    int i = n - 1;
    while(a[i] != '0')
    {
        i--;
        if(i == -1)
        {
            cout << -1;
            return;
        }
    }

    a[i] = '1';
    for(int j = i + 1; j < n; j++)
    {
        a[j] = '0';
    }

    for(int j = 0; j < n; j++)
        cout << a[j];
    cout << endl;

}

int main()
{

    int n;
    cin >> n >> a;
    production(n);
    return 0;
}
