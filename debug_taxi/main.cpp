#include <iostream>

using namespace std;


int n;
int cost[30][30];
int path[30];
bool travel[30];
int f = 0;
int best = 1000000;
int cmin = 10000000;

/*
int discovery(int k)
{
    for(int i = 0; i <= n; i++)
    {
        if(travel[i] == false)
        {
            travel[i] = true;
            path[k] = i;
            int index = path[k-1];
            if(k != 1)
            {
                f += cost[index][index + n] + cost[index + n][i];

            }
            else
                f+= cost[0][i];
            if(k == n)
                {
                    if(best > (f + cost[i][i+n] + cost[i+n][0]))
                        best =  (f + cost[i][i+n] + cost[i+n][0]);
                }
            else
                {
                    discovery(k+1);
                }
            if(k != 1)
            {
                f -= (cost[index][index + n] + cost[index + n][i]);

            }
            else
                f-= cost[0][i];

            travel[i] = false;

        }
    }
}
*/

int discovery(int k)
{
    for(int i = 0; i <= n; i++)
    {
        if(travel[i] == false)
        {
            travel[i] = true;
            path[k] = i;
            int index = path[k-1];
            if(k != 1)
            {
                f += cost[index][index + n] + cost[index + n][i];

            }
            else
                f+= cost[0][i];
            if(k == n)
                {
                    if(best > (f + cost[i][i+n] + cost[i+n][0]))
                        best =  (f + cost[i][i+n] + cost[i+n][0]);
                }
            else if(best > (cmin*(n-k + 1)*2 + f))
                {
                    discovery(k+1);
                }
            if(k != 1)
            {
                f -= (cost[index][index + n] + cost[index + n][i]);

            }
            else
                f-= cost[0][i];

            travel[i] = false;

        }
    }


}

int main()
{
    cin >> n;
    for(int i = 0; i < 2*n + 1; i++)
        for(int j = 0; j < 2*n + 1; j++)
        {
             cin >> cost[i][j];
             if(cost[i][j] && (cmin > cost[i][j]))
                cmin = cost[i][j];
        }

    for(int i = 0; i < n; i++)
        travel[i] = false;
    travel[0] = true;
    discovery(1);
    cout << best;
    return 0;
}
