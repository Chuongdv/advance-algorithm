#include <iostream>

using namespace std;

int combinationgen(int a[], int n, int m)
{
    int pivot = n;
    for(int i = m - 1, j = 0 ; i >= 0; i--)
        {
            if(a[i] != (n - m + i + 1))
            {
                pivot = i;
                break;
            }
            j++;
        }
    if(pivot == n)
        return 0;
    a[pivot] = a[pivot] + 1;
        for(int i = pivot + 1; i < n; i++)
        {
            a[i] = a[pivot] + (i - pivot);
        }
    return 1;

}


int n;
int m;
int a[10001];
int k;

int main()
{
    cin >> n >> m >> k;
    for(int i = 0; i < m; i++)
    {
        a[i] = i + 1;
    }
    for(int i = 0; i < k - 1; i++)
    {
        if(combinationgen(a, n, m))
        {

        }
        else
        {
            cout << -1;
            return 0;
        }
    }
    for(int i = 0; i < m; i ++)
    {
        cout << a[i] << " ";
    }
}
