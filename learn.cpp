#include <iostream>

using namespace std;
long a[1000000];
long long sum[1000001];

int main()
{
	int n;
	long long Max = -1000000000000000;
	cin >> n;
    sum[0] = 0;
	for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        if(i == 0)
        {
            sum[0] = a[0];
        }
        else
            sum[i] = sum[i - 1] + a[i];
    }

    long long Minf = 0;
    int idx;
    for(int i = 0 ; i < n; i++)
    {
       if(Max < (sum[i] - Minf))
        Max = sum[i] - Minf;

        if(Minf > sum[i])
       {
           Minf = sum[i];
           idx = i;
       }
    }

    cout << Max;
	return 0;
}
