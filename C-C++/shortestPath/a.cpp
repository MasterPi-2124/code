#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second

FILE *fi,*fo;
int u,v,m,n,s,f,c;
long long int parent[11],dist[11];
vector<pair<int,int>> w[11];
vector<int> edge,candidate;
stack<int> res;

void Dijkstra()
{
    for (int i = 1; i <= n; i++)
    {
        dist[i] = INT_MAX;
        parent[i] = s;
        if (i != s) candidate.push_back(i);
    }
    for (auto i: w[s]) dist[i.f] = i.s;
    dist[s] = 0;
    edge.push_back(s);
    
    while (candidate.size())
    {
        int temp = INT_MAX;
        int u;
        for (auto v : candidate)
        {
            if (temp > dist[v])
            {
                temp = dist[v];
                u = v;
            }
        }
        for (int i = 0; v < candidate.size(); i++)
        {
            if (candidate[i] == u)
            {
                candidate.erase(candidate.begin()+i);   
                break;
            }
        }
        edge.push_back(u);
        if (u == f) return;

        for (auto i : w[u])
        {
            if (dist[i.f] >= dist[u] + i.s)
            {
                dist[i.f] = dist[u] + i.s;
                parent[i.f] = u;
            }
        }
    }
}

int main()
{
    fi=freopen("a.inp","r",stdin);
    fo=freopen("a.out","w",stdout);
    cin>>n>>m;
    for (int i = 1; i <= m; i++)
    {
        cin>>u>>v>>c;
        w[u].push_back(make_pair(v,c));
        w[v].push_back(make_pair(u,c));
    }
    cin>>s>>f;
    Dijkstra();
    cout<<dist[f]<<endl;
    while (f != s)
    {
        res.push(f);
        f = parent[f];
    }
    cout<<s<<" ";
    while (res.size())
    {
        cout<<res.top()<<" ";
        res.pop();
    }
    return 0;   
}