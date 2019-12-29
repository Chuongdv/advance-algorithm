#include <stdio.h>
#include <iostream>

using namespace std;

int a[1000001];
int n;

int partion(int a[], int l, int r)
{
    int pivot = a[r];
    int temp = 0;
    int i = l, j = l;
    while(i < r)
    {
        if(a[i] < pivot)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            j++;
        }
        i++;
    }
    temp = a[j];
    a[j] = pivot;
    a[r] = temp;
    return j;

}


void quicksort(int a[], int l, int r)
{
    int pivot = 0;
    if(l < r)
    {
        pivot = partion(a, l, r);
        if(pivot > l)
            quicksort(a, l, pivot - 1);
        if(pivot < r)
            quicksort(a, pivot + 1, r);

    }

}

int main()
{
    int n;
    cin>>n;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    quicksort(a, 0, n - 1);

    for(int i = 0; i < n; i++)
        cout << a[i] << " ";
}
