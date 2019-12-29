#include <iostream>

using namespace std;



void combsort(int a[], int n)
{
    int gap = n;
    int temp = 0;
    bool sorted = false;

    while((gap > 1) || (sorted == false))
    {
        gap = (int) (gap / 1.3);
        if(gap < 1)
            gap = 1;
        if(gap == 1)
            sorted = true;
        int i = 0;

        while(i + gap < n)
        {
            if(a[i] > a[i + gap])
            {
                temp = a[i];
                a[i] = a[i + gap];
                a[i+gap] = temp;

                if(gap == 1)
                    sorted = false;
            }
            i++;

        }

    }
}

















int a[1000000];
int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];

    combsort(a, n);
    for(int i = 0; i < n; i++)
        cout << a[i] << " ";
    return 0;
}

