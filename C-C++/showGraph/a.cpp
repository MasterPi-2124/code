#include<bits/stdc++.h>
using namespace std;

FILE *fi,*fo;
int u,v,m,n,s,f,c;

int main()
{
    fi=freopen("a.inp","r",stdin);
    fo=freopen("a.out","w",stdout);
    cin>>n>>m>>k;
    for (int i = 1; i <= m; i++)
    {
        cin>>u>>v;
        w[u].push_back(v);
    }

    for (int i = 1; i <= k; i++)
    {
        cin>>f;
    }
    return 0;   
}