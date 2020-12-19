#include<bits/stdc++.h>
using namespace std;

FILE *fi,*fo;
int m,n,u,v,cnt,parent[9],s,f;
vector<pair<int,int>> a;
int visited[9]={0};
stack<int> res;

void BFS(int s)
{
    queue<int> q;
    visited[s] = 1;
    q.push(s);
    while(!q.empty())
    {
        s = q.front();
        q.pop();
        for (auto i:a)
        {
            if(!visited[i.second] && i.first == s)
            {
                visited[i.second] = 1;
                parent[i.second] = s;
                q.push(i.second);
            }
        }
    }
}

void DFS(int s)
{
    visited[s]=1;
    for (auto i:a)
    {
        if(!visited[i.second] && i.first == s)
        {
            parent[i.second] = s;
            if (i.second == f) return;
            DFS(i.second);
        }
    }
}

int main()
{
    fi=freopen("a.inp","r",stdin);
    fo=freopen("a.out","w",stdout);
    cin>>m>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>u>>v;
        a.push_back(make_pair(u,v));
    }
    cin>>s>>f;
    cnt = 0;

    for(int i=1;i<=m;i++)
    {
        if (visited[i] == 0)
        {
            cnt++;
            BFS(i);
        }
    }
    cout<<cnt<<endl;
    cnt = 1;
    memset(visited,0,sizeof(visited));
    BFS(s);
    if (!visited[f]) cout<<"0"<<endl<<"0";
    else{
    int v = f;
    while (v != s)
    {
        cnt++;
        v = parent[v];
    }
    cout<<cnt<<endl;
    cnt = 1;
    memset(visited,0,sizeof(visited));
    DFS(s);

    while (f != s)
    {
        cnt++;
        res.push(f);
        f = parent[f];
        
    }
    cout<<cnt<<endl;
    res.push(s);
    while(res.size())
    {
        cout<<res.top()<<" ";
        res.pop();
    }}
    return 0;   
}