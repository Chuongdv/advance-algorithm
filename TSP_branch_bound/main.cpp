#include <iostream>

using namespace std;

int cost[30][30];
int n = 0;
bool travel[30];
int f = 0;
int best = 10000;
int cmin = 10000;
int path[30];


void discovery(int k)
{
    for(int i = 0; i <= n; i++)
    {
        if(travel[i] == false)
        {
            travel[i] = true;
            f+= cost[path[k-1]][i];
            path[k] = i;
            if(k == n)
            {
                if(best > (f + cost[i][0]))
                    best = f + cost[i][0];
            }
            else
            {
                if((f + (n - k + 1) * cmin) < best)
                    discovery(k+1);
            }
            travel[i] = false;
            f-= cost[path[k-1]][i];
        }
    }
}







int main()
{
    cin >> n;
    for(int i = 0; i < n + 1; i++)
    {
        for(int j = 0; j < n + 1; j++)
        {
            cin >> cost[i][j];
            if(cmin > cost[i][j])
            {
                cmin = cost[i][j];
            }
        }
    }

    travel[0] = true;
    path[0] = 0;
    discovery(1);
    cout << best;
    return 0;
}
