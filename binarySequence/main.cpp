#include <iostream>

using namespace std;

int a[1000];
int flag = 0;

void print(int n)
{
    for(int i = 0; i < n; i++)
        cout << a[i];
    flag = 1;
    cout << endl;
}


void TRY(int k, int n)
{
    for(int i = 0; i <= 1; i++)
    {
        a[k] = i;
        if(k == n - 1)
            print(n);
        else
        {
            TRY(k+1, n);
        }
    }
}



void production(int a[], int n)
{
    int i = n - 1;
    while(a[i] != 0)
    {
        i--;
    }

    a[i] = 1;
    for(int j = i + 1; j < n; j++)
    {
        a[j] = 0;
    }

    for(int j = 0; j < n; j++)
        cout << a[j];
    cout << endl;

}

void listing(int a[], int n)
{
    int flag = 0;
    while(1)
    {
        flag = 1;
    for(int i = 0; i < n; i++)
    {
        if(a[i] == 0)
        {
            flag = 0;
            break;
        }
    }
        if(flag == 0)
        {
            production(a, n);
        }
        else
            break;
    }


}



void productionB(int a[], int m, int n)
{
    int i = m;
    while(i)
    {
        if(a[i] != n - m + i)
            break;
        i--;
    }

    a[i]++;

    for(int j = i + 1; j <= n; j++)
    {
        a[j] = a[i] + j - i;
    }

    for(int j = 1; j <= m; j++)
        cout << a[j];
    cout << endl;

}


void listingB(int a[], int n, int m)
{
    int flag = 0;
    while(1)
    {
        flag = 1;
        for(int i = 1; i <= m; i++)
        {
            if(a[i] != n - m + i)
                flag = 0;
        }

        if(flag == 0)
        {
            productionB(a, m, n);
        }
        else
            break;
    }
}



void permutationNext(int a[], int n)
{
    int i = n - 1;
    while(a[i] > a[i+1])
    {
        i--;
    }
    int maxmin = i+1;
    for(int j = i+2; j <= n; j++)
    {
        if(a[j] > a[i] && a[j] < a[maxmin])
           {
              maxmin = j;
           }
    }

    //swap
    int temp = a[maxmin];
    a[maxmin] = a[i];
    a[i] = temp;

    //revert
    int k = i + 1;
    int j = n;
    while(j > k)
    {
        temp = a[k];
        a[k] = a[j];
        a[j] = temp;

        j--;
        k++;
    }

    for(int i = 0; i < n; i++)
        cout << a[i];
    cout << endl;

}

int main()
{
    int n, m;
    cin >> n >> m;
   // TRY(0, n);
  //  if(flag != 1)
   //     cout << -1;

  // listing(a, n);

  for(int i = 1; i <= n; i++)
    a[i] = i;

    permutationNext(a, n);
  //listingB(a, n, m);
    return 0;
}
