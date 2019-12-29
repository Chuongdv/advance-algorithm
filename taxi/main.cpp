#include <iostream>

using namespace std;


int n;
int cost[30][30];
int travel[30];
int f = 0;
int best = 1000000;


int discovery(int k, int p)
{
    if(k == n)
    {
        return cost[p][p+n] + cost[p+n][0];
    }
    else
    {
        for(int i = 0; i <= n; i++)
        {
            if(travel[i] == false)
            {
                travel[i] = true;
                if(k == 1)
                    f =  discovery(k+1, i) + cost[0][i];
                else
                    f =  discovery(k+1, i) + cost[p][p+n] + cost[p+n][i];
                if(f < best)
                    best = f;
                travel[i] = false;
            }
        }
    }
}


int main()
{
    cin >> n;
    for(int i = 0; i < 2*n + 1; i++)
        for(int j = 0; j < 2*n + 1; j++)
            cin >> cost[i][j];
    for(int i = 0; i < n; i++)
        travel[i] = false;
    travel[0] = true;
    discovery(1, 0);
    cout << best;
    return 0;
}
