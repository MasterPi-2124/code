#include<bits/stdc++.h>
using namespace std;

FILE *fi,*fo;
int m,n,u,v;
vector<pair<int,int>> a;
int visited[9];

void BFS(int s)
{
    queue<int> q;
    visited[s] = 1;
    q.push(s);
    while(!q.empty())
    {
        s = q.front();
        cout<<q.front()<<" ";
        q.pop();
        for (auto i:a)
        {
            if(!visited[i.second] && i.first == s)
            {
                visited[i.second] = 1;
                q.push(i.second);
            }
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
    for(int i=1;i<=m;i++){
        visited[i]=0;
    }
    BFS(8);
    return 0;   
}