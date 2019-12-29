#include <bits/stdc++.h>

using namespace std;

struct edge{
    int u;
    int v;
    int weight;

    edge(int u, int v, int weight)
    {
        this->u = u;
        this->v = v;
        this->weight = weight;
    }
};

vector<edge> edges;

struct union_find{
    vector<int> parent;
    vector<int> ranker;

    union_find(int n)
    {
        parent = vector<int>(n);
        ranker = vector<int>(n);
        for(int i = 0; i < n; i++)
        {
            parent.at(i) = i;
            ranker[i] = 0;
        }
    }

    int find(int x)
    {
        if(x == parent[x])
            return x;
        else
        {
            parent[x] = find(parent[x]);
            return parent[x];
        }
    }

    void unite(int x, int y)
    {

        if(ranker[x] > ranker[y])
            parent[find(y)] = find(x);
        else if(ranker[x] < ranker[y])
        {
            parent[find(x)] = find(y);
        }
        else
        {
            ranker[x] += 1;
            parent[find(y)] = find(x);
        }

       // parent[find(y)] = find(x);
    }
};

bool compareEdges(const edge &a, const edge &b)
{
    return a.weight < b.weight;
}

vector<edge> mst(int n, vector<edge> &edges)
{
    union_find uf(n+1);
    sort(edges.begin(), edges.end(), compareEdges);
    vector<edge> result;
    for(int i = 0; i < edges.size(); i++)
    {
        int u = edges.at(i).u;
        int v = edges.at(i).v;
        if(uf.find(u) != uf.find(v))
        {
            uf.unite(u, v);
            result.push_back(edges.at(i));
        }
    }
    return result;
}


int main()
{
    int n, m;
    vector<edge> edges;
    cin>>n >> m;
    int u, v, w;
    for(int i = 0; i < m; i++)
    {
        cin >> u >> v >> w;
        edge temp(u, v, w);
        edges.push_back(temp);
    }

    vector<edge> result = mst(n, edges);
    long long sum = 0;
    for(int i = 0; i < result.size(); i++)
    {
        sum += result.at(i).weight;
    }
    cout << sum;

}
