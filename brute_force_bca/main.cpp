#include <bits/stdc++.h>

using namespace std;

int n, m;
int classtime[30];
int conflict[30][30];
int can[30][30];
int result = 100000;
int p[30];

bool ucv(int k, int app)
{
    int i = 1;
    for(i = 1; i <= can[k][0]; i++)
    {
        if(app == can[k][i] - 1)
            return true;
    }
        return false;
}



bool constraint()
{
    /*
    // check teacher study
    for(int i = 0; i < n; i++)
    {
        int j = 1;
        for(j = 1; j <= can[i][0];j++)
        {
            if((can[i][j] - 1) == p[i])
            {
                break;
            }
        }
        if(j > can[i][0])
        {
            return false;
        }
    }
    */
    // check conflict
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(conflict[i][j] == 1)
            {
                if(p[i] == p[j])
                    return false;
            }
        }
    }

    return true;

}

int load[30];
int f()
{
    for(int i = 0; i < m;i++)
        load[i] = 0;

    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        load[p[i]] += classtime[i];
    }

    for(int i = 0; i < m; i++)
    {
        if(ans < load[i])
            ans = load[i];
    }
    return ans;
}

void production(int k)
{
    for(int i = 0; i < m; i++)
    {
        if(ucv(k-1, i))
        {
            p[k-1] = i;
            if(k == n)
            {
                if(constraint())
                    result = min(result, f());
            }
            else
                production(k+1);
        }
    }
}

int main()
{
    cin >> n >> m;


    for(int i = 0; i < n; i++)
    {
        cin >> classtime[i];
    }

    for(int i = 0; i < n; i++)
    {
        cin >> can[i][0];
        for(int j = 1; j <= can[i][0]; j++)
        {
            cin >> can[i][j];
        }
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin>> conflict[i][j];
        }
    }

    production(1);
    cout << result;

}
