#include <iostream>
#include <cstring>

using namespace std;

int a[1001];
int b[1001];
int memo[1001][1001];



int calculate(int a[], int b[], int n, int m)
{
    if(n == -1 || m == -1)
    {
        std:: cout << "n" <<n << "m" << m << endl;
        memo[n+1][m + 1] = 0;
        return 0;
    }
    else
    {
        if(a[n] == b[m])
        {
            if(memo[n][m] != -1)
               memo[n][m] = calculate(a, b, n - 1, m - 1);
            memo[n+1][m+1] = memo[n][m] + 1;

        }
        else
        {
            if(memo[n][m + 1] != -1)
            {
                memo[n][m + 1] = calculate(a, b, n - 1, m);
            }
            if(memo[n + 1][m] != -1)
                memo[n + 1][m] = calculate(a, b, n, m - 1);
            memo[n+1][m + 1] = max(memo[n][m + 1] , memo[n+1][m]);
        }
        std::cout << n << " " << m << " "<< memo[n+1][m+1] << endl;
        return memo[n+1][m+1];
    }
}


int main()
{
    int n, m;
    std::cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        std::cin>>a[i];
    }

    for(int i = 0; i < m; i++)
    {
        std::cin>>b[i];
    }

    memset(memo, -1, (n + 1)*(m+1));
  std:: cout << calculate(a, b, n - 1, m - 1);

}
