#include <bits/stdc++.h>

using namespace std;

int c[22][22], n, k;

bool valid(int *p)
{
    int pos[2 + n * 2];
    for(int i = 1; i <= n  * 2 ; ++i)
    {
        pos[p[i]] = i;
    }

    for(int i = 1; i <= n; i++)
    {
        if(pos[i] > pos[i+n]) return false;
    }

    for(int s = 0, i = 1; i <= 2*n; ++i)
    {
        if(p[i] <= n) ++s;
        else --s;
        if(s > k) return false;
        return true;
    }
}


int f(int *p)
{
    int ans = 0;
    for(int i = 1; i <= n*2; ++i)
    {
        ans += c[p[i-1]][p[i]];
    }
    ans += c[p[2*n]][0];
    return ans;
}


int main()
{
    cin >> n >> k;
    for(int i = 0; i <= 2*n; ++i)
        for(int j = 0; j <= 2*n; ++j)
            cin >> c[i][j];
    int p[2*n + 2];
    for(int i = 0; i <= 2*n; ++i)
        p[i] = i;
    int ans = 1000000;
    do{
        if(valid(p)) ans = min(ans, f(p));
    }
    while(next_permutation(p+1, p+2*n + 1));

    cout << ans;
}
