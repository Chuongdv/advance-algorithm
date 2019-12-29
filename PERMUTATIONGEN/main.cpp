#include <iostream>

using namespace std;
int a[10001];
long k, n;

bool check(int a[], int n)
{
    for(int i = n; i >= 1; i--)
    {
        if(i != a[n - i])
            return true;
    }
    return false;
}

int permutationgen(int n, int a[])
{
    if(check(a, n))
    {
        int pivot = 0;
        for(int i = n - 2; i >=0; i--)
        {
            if(a[i] < a[i+1])
            {
                pivot = i;
                break;
            }
        }
        int imax = pivot + 1;
        for(int i = pivot+1; i < n ; i++)
        {
            if(a[i] < a[imax] && a[i] > a[pivot])
            {
                imax = i;
            }
        }
        swap(a[imax], a[pivot]);
        while((pivot + 1) < (n - 1))
        {
            swap(a[pivot+1], a[n-1]);
            pivot++;
            n--;
        }
        return 1;
    }
    return -1;
}


int main()
{
  cin >> n >> k;
  if(n <= 0 || k <= 0)
  {
      cout << -1;
      return 0;
  }
    for(int i = 0; i < n; i++)
    {
        a[i] = i + 1;
    }
    for(int i = 1; i <= k - 1; i++)
    {
        if(permutationgen(n ,a) == -1)
        {
            cout << "-1";
            return 0;
        }
    }
    for(int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}
