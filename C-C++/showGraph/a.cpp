#include<bits/stdc++.h>
using namespace std;

FILE *fi,*fo;
int u,v,m,n,k,f,d;
vector<int> w[100001],x[100001];

int main()
{
    fi=freopen("a.inp","r",stdin);
    fo=freopen("a.out","w",stdout);
    cin>>n>>m>>k;
    for (int i = 1; i <= m; i++)
    {
        cin>>u>>v;
        w[u].push_back(v);
        x[v].push_back(u);
    }
    int d = 1;
    cout<<n<<" "<<m<<endl;
    for (int u = 1; u <= n; u++)
    {
        cout<<d<<" ";
        for (auto v : w[u]) d++;
    }
    cout<<endl;
    for (int u = 1; u <= n; u++)
    {
        for (auto v : w[u])
        {
            cout<<v<<" ";
        }
    }
    cout<<endl;
    
    for (int i = 1; i <= k; i++)
    {
        cin>>f;
        sort(x[f].begin(),x[f].end());
        for (auto v : x[f]) cout<<v<<" ";
        cout<<endl;
    }
    return 0;   
}