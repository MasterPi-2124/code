#include<bits/stdc++.h>
using namespace std;

FILE *fi,*fo;
int m,n,u,v;
vector<pair<int,int>> a;
int visited[9];

void DFS(int s)
{
    visited[s]=1;
    for (auto i:a)
    {
        if(!visited[i.second] && i.first == s)
        {
            DFS(i.second);
        }
    }
    cout<<s<<" ";
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
   /* for (int i=1;i<=m;i++)
    {
        if (!visited[i]) DFS(i);
    }*/
    DFS(1);
    return 0;   
}