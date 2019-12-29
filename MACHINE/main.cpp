#include <bits/stdc++.h>

using namespace std;

int s[1000001];
int f[1000001];

int main()
{
int n;
cin >> n;
for(int i = 0; i < n; i++)
{
    cin >> s[i] >> f[i];
}

int result = 0;

for(int i = 0; i < n; i++)
{
    for(int j = i; j < n; j++)
    {
        if(s[i] > f[j] || s[j] > f[i])
        {
            int temp = (f[i] - s[i]) + (f[j] - s[j]);
            result = max(result, temp);
        }
    }
}

std::cout <<result;



}
