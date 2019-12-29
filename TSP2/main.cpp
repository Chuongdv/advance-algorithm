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
    for(int i = 0; i <= n; i++)
    {
        if(travel[i] == false)
        {
            travel[i] = true;
            path[k] = i;
            f += cost[path[k - 1]][i];

            if(k == n)
            {
                if(best > (f + cost[i][0]))
                {
                    best = f + cost[i][0];
                }
            }
            else{
                if((f + (n - k + 1)*cmin) < best)
                {
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
    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= n; j++)
        {
            cin >> cost[i][j];
            if(cost[i][j] && (cmin > cost[i][j]))
                cmin = cost[i][j];
        }
    }
    travel[0] = true;
    path[0] = 0;
    TSP(1);
    cout << best;
    return 0;
}
