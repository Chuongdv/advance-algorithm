#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int n, c[20][20];
int save[1 << 20][20];

int duyet(int x, int p)
{
    if(__builtin_popcount(x) == n) return c[p][0];
    int ans = 100000;
    if(save[x][p] != -1)
        return save[x][p];
    for(int s = 0; s < n; ++s)
    if(!(x >> s & 1))
    {
        ans = min(ans, duyet((1<<s) | x, s) + c[p][s]);
    }
    save[x][p] = ans;
    return ans;
}

int main()
{
    cin >> n;
    ++n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> c[i][j];
    memset(save, 255, sizeof(save));
    cout << duyet(1 << 0, 0);
    return 0;
}
