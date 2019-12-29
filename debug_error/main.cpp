#include <iostream>

using namespace std;


int n = 0;
int m = 0;
int cost[100][100];
int path[100];
int bus[100][100];
bool travel[100];
int f = 0;
int cou[100];
int best = 100000;

void discovery(int k)
{

    for(int i = 0; i <= 2*n; i++)
    {
        if(travel[i] == false)
        {
            travel[i] = true;
            path[k] = i;
            f+= cost[path[k-1]][i];
            for(int j = 0; j < m; j++)
            {
                bus[k][j] = bus[k-1][j];
                cou[k] = cou[k-1];
            }
            if(i > n)
            {
                for(int j = 0; j < m; j++)
                {
                    if((bus[k][j] + n) == i)
                    {
                        bus[k][j] = -1;
                        cou[k] -= 1;
                        if(k == 2*n)
                        {
                            if(best > (f+cost[i][0]))
                                best = f + cost[i][0];

                            cout <<"result: " ;
                            for(int hihi = 0; hihi <= 2*n; hihi++)
                                cout << path[hihi]<< " ";
                            cout << endl;
                            cout << j << endl;
                            for(int hihi = 0; hihi < m; hihi ++)
                                cout << bus[hihi] << " ";
                            cout << endl;

                        }
                        else
                            discovery(k+1);
                        break;
                    }
                }
            }
            else
            {
                if(cou[k-1] < m)
                for(int j = 0; j < m; j++)
                {
                    if(bus[k][j] == -1)
                    {
                        bus[k][j] = i;
                        cou[k]+= 1;
                        discovery(k+1);
                        break;
                    }
                }
            }

            f-= cost[path[k-1]][i];
            travel[i] = false;
        }
    }
}



int main()
{
    cin >> n >> m;
    for(int i = 0; i < 2*n + 1; i++)
    {
        for(int j = 0; j < 2*n + 1; j++)
            cin >> cost[i][j];
        cou[i] = 0;
    }
    for(int i = 0;i <= 2*n; i++)
    for(int j = 0; j < m; j++)
        bus[i][j] = -1;
    travel[0] = true;
    path[0] = 0;
    discovery(1);
    cout << best;
    return 0;
}
