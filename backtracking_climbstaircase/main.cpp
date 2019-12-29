#include <iostream>

using namespace std;

int path[30];

void production(int n, int k, int level)
{
    for(int i = 1; i <= k; i++)
    {
        path[level] = i;
        n -= i;
        if(n == 0)
        {
            cout << endl;
            for(int j = 0; j <= level; j++)
            {
                cout << path[j] << " ";
            }
        }
        else if(n > 0)
        {
            production(n, k, level+1);
        }
        n+= i;
    }
}


int main()
{
    int n, k;
    cin>> n >> k;
    production(n, k, 0);
    return 0;
}
