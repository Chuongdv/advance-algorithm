#include <iostream>
#define MONEY 1000
#define SIZE 6
using namespace std;
int a[] = {1, 5, 10, 50, 100, 500};

int changeCoin(int n)
{
    int k = SIZE - 1;
    int counter = 0;
    while(n && k > -1)
    {
        if(n >= a[k])
        {
            n -= a[k];
            counter ++;
        }
        else
        {
            k--;
        }
    }
    if(n == 0)
        return counter;
    else
        return -1;

}

int main()
{
    int n;
    cin >> n;
    cout << changeCoin(MONEY - n);
    return 0;
}
