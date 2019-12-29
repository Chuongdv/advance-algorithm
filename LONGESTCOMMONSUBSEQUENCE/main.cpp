#include <bits/stdc++.h>

using namespace std;

int a[10001];
int b[10001];
int memo[10001][10001];
int main()
{
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        memo[i][0] = 0;
        cin >> a[i];
    }
    for(int i = 1; i <= m; i++)
    {
        cin >> b[i];
        memo[0][i] = 0;
    }

    memo[0][0] = 0;


    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(a[i] == b[j])
            {
                memo[i][j] = memo[i - 1][j - 1] + 1;
            }
            else
            {
                memo[i][j] = max(memo[i - 1][j], memo[i][j - 1]);
            }
        }
    }

    cout << memo[n][m];

}
