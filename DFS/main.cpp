#include <bits/stdc++.h>

using namespace std;


vector <int> adj[10001];
vector <bool> visited;

void DFS(int u)
{
 //   cout << "travel: " << u << endl;
    for(int i = 0; i < adj[u].size(); i++)
    {
        int v = adj[u][i];
        if(visited[v] != true)
        {
            visited[v] = true;
            DFS(v);
        }
    }
}


int main()
{
    int n, m;
    cin >> n >> m;
    int from, to;

    for(int i = 0; i < m; i++)
    {
        cin >> from >> to;
        adj[from].push_back(to);
        adj[to].push_back(from);
    }

    for(int i = 1; i <= n; i++)
        visited.push_back(false);
    int counter = 0;
    for(int i = 1; i <= n; i++)
    {
        if(visited[i] != true)
        {
            counter ++;
            DFS(i);
        }
    }
    cout << counter;


    return 0;
}
