#include <iostream>

using namespace std;





int parttion(double a[], int p, int q)
{
    double pivot = a[q];
    double temp = 0;
    int index = p - 1;
    for(int i = p ; i < q; i++)
    {
        if(a[i] < pivot)
        {
            index++;
            temp = a[i];
            a[i] = a[index];
           a[index] = temp;
        }



    }
        a[q] = a[index + 1];
        a[index + 1] = pivot;
        return (index + 1);
}




void quicksort(double a[], int p, int q)
{
    int idx;
    if(p < q)
    {
        idx = parttion(a, p, q);
        if(p < idx)
        quicksort(a, p, idx - 1);
        if(q > idx)
        quicksort(a, idx + 1, q);
    }

}


double a[1000000];


int main()
{
    int n;
    cin>> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i] ;
        a[i] *=100;
    }
    //quicksort(a, 0, n - 1);

    for(int i = 0; i < n; i++)
    {
        cout << (a[i] /100) << " ";
    }
    return 0;
}
