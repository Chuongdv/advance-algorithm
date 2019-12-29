#include <iostream>

using namespace std;


int partion(int a[], int l, int r)
{
    int pivot = a[r];
    int i = l - 1;
    int temp = 0;
    for(int j = l; j < r; j++)
    {
        if(a[j] < pivot)
        {
            i++;
            temp = a[j];
            a[j] = a[i];
            a[i] = temp;
        }
    }

    a[r] = a[i+1];
    a[i + 1] = pivot;
    return i + 1;
}





void quicksort(int a[], int l, int r)
{
    int idx = 0;
    if(l < r)
    {
        idx = partion(a, l, r);
        if(l < idx)
        quicksort(a, l, idx - 1);
        if(idx < r)
        quicksort(a, idx + 1, r);
    }
}


int a[1000000];
int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin>> a[i];
    }

     quicksort(a, 0, n - 1);
     /*   int temp = 0;

    for(int i = n - 1; i > 0; i--)
    {
        for(int j = 0; j < i; j++)
        {
            if(a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j+1];
                a[j + 1] = temp;

            }
        }
    }
    */
    for(int i = 0; i < n; i ++)
        cout << a[i] << " ";
    return 0;
}
