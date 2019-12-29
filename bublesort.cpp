#include <iostream>

using namespace std;

int a[1000000];
int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int temp = 0;
    int invariant = 0;
    do
    {
        invariant = 0;
        for(int i = 1; i < n; i++)
        {
            if(a[i] < a[i - 1])
            {
                temp = a[i];
                a[i] = a[i-1];
                a[i - 1] = temp;
                invariant = 1;
            }
        }
    }
    while(invariant == 1);
    for(int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}
