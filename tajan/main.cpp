#include <bits/stdc++.h>


using namespace std;
vector <int> adj[100001];
vector <bool> complete;
vector <int> low;
vector <int> num;
stack<int> result;
int n, m;
int t = 0;
int counter = 0;



void SCC(int i)
{
    low[i] = num[i] = t++;
    complete[i] = true;
    result.push(i);
    for(int j = 0; j < adj[i].size(); j++)
    {
        int v = adj[i].at(j);
        if(num[v] == -1)
        {
            SCC(v);
            low[i] = min(low[i], low[v]);
        }
        else if(complete[v] == true )
        {
            low[i] = min(num[v], low[i]);
        }
    }

    if(low[i] == num[i])
    {
        counter++;
        while(result.top() != i)
        {
            complete[i] = false;
            result.pop();
        }
        result.pop();
    }

}



int main()
{

    cin >> n >> m;
    int s, e;
    for(int i = 0 ; i < m; i++)
    {
        cin >> s >> e;
        adj[s].push_back(e);
    }

    for(int i = 0; i <= n; i++)
    {
        low.push_back(0);
        num.push_back(-1);
        complete.push_back(false);
    }

    for(int i = 1; i <= n; i++)
    {
        if(num[i] == -1)
        {
            SCC(i);
        }
    }

    cout << counter;

}
