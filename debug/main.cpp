#include <iostream>

using namespace std;

int cost[100][100];
bool travel[100];
int path[100];
int f = 0;
int cmin = 100000000;
int n;
int best = 1000000;


void TSP(int k)
{
    for(int i = 1; i <= n; i++)
    {
        if(travel[i] == false)
        {
            travel[i] = true;
            f += cost[path[k - 1]][i];
            if(k == n - 1)
            {
                if(best > f)
                {
                    best = f + cost[i][1];
                }
            }
            else{
                if((f + (n - k + 1)*cmin) < best)
                {
                    path[k] = i;
                    TSP(k+1);
                }
            }
            f -= cost[path[k-1]][i];
            travel[i] = false;
        }
    }
}



int main()
{
    cin >> n;
    n += 1;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> cost[i][j];
            if(cost[i][j] && (cmin > cost[i][j]))
                cmin = cost[i][j];
        }
    }
    travel[1] = true;
    path[0] = 1;
    TSP(1);
    cout << best;
    return 0;
}
