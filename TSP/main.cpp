#include <iostream>

using namespace std;

int c[20][20];
bool visited[20];
int n;
int f = 0;
int F = 10000000000;
int cmin = 100000000;
int path[20];


void TRY(int k)
{
    for(int i = 0; i < n + 1; i++)
    {
        if(visited[i] == false)
        {
            path[k] = i;
            visited[i] = true;
            f = f + c[path[k - 1]][i];
            if(k == n)
            {
                if((f + c[i][0]) < F)
                    F = f + c[i][0];
            }
            else
            {
                int z = f + (n - k + 1) * cmin;
                if(z < F)
                {
                    TRY(k + 1);
                }
            }

            f = f - c[path[k - 1]][i];
            visited[i] = false;
        }

    }
}

int main()
{
    cin >> n;
    for(int i = 0; i < n + 1; i++)
    {
        visited[i] = false;
        for(int j = 0; j < n + 1; j++)
        {
            cin >> c[i][j];
            if(c[i][j]!=0 && (c[i][j] > cmin))
                cmin = c[i][j];
        }
    }

    visited[0] = true;
    path[0] = 0;
    TRY(1);
    cout << F;
    return 0;
}
