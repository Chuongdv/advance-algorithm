#include <iostream>

using namespace std;








void mergesort(int a, int l, int r)
{
    int midle;
    if(l < r)
    {
        midle = (l + r)/2;
        mergesort(a, l, midle);
        mergesort(a, midle + 1, r);
        mergesequence(a, l, r, midle);
    }
}





int a[1000000];
int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];


    for(int i = 0; i < n; i++)
        cout << a[i] << " ";
    return 0;
}
