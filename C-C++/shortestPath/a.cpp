#include<bits/stdc++.h>
using namespace std;

FILE *fi,*fo;
int u,v,w,m,n,s,f;
int p[10],d[10];
int a[10][10];
vector<int> edge,candidate;

void Dijkstra()
{
    for (int i = 1; i <= n; i++)
    {
        if (a[i][s] != 0) d[i] = a[i][s];
        else d[i] = INT_MAX;
        p[i] = s;
        if (i != s) candidate.push_back(i);
    }
    d[s] = 0;
    p[s] = s;
    edge.push_back(s);
    while (candidate.size())
    {
        int temp = 999;
        int ii;
        for (int i = 0; i < candidate.size(); i++)
        {
            if (temp > d[candidate[i]]  && a[candidate[i]][edge[edge.size()-1]] > 0)
            {
                temp = d[candidate[i]];
                ii = candidate[i];
            }
        }
        for (int i = 0; i < candidate.size(); i++)
        {
            if (candidate[i] == ii)
            {
                candidate.erase(candidate.begin()+i);
                break;
            }
        }
        edge.push_back(ii);
        for (auto i : candidate)
        {
            if (d[i] >= d[ii] + a[i][ii])
            {
                d[i] = d[ii] + a[ii][i];
                p[i] = ii;
                if (i == f)
                {
                    edge.push_back(f);
                    return;
                }
            }
        }
    }
}

int main()
{
    fi=freopen("a.inp","r",stdin);
    fo=freopen("a.out","w",stdout);
    fscanf(fi,"%d%d",&n,&m);
    /*n=4;m=6;
    a[2][1]=a[1][2]=3;
    a[2][3]=a[3][2]=1;
    a[3][1]=a[1][3]=10;
    a[4][1]=a[1][4]=5;
    a[3][4]=a[4][3]=5;
    a[4][2]=a[2][4]=6;
    s=2;f=4;*/
    for (int i = 1; i <= m; i++)
    {
        fscanf(fi,"%d%d%d",&u,&v,&w);
        a[u][v] = a[v][u] = w;
    }
    cin>>s>>f;
    Dijkstra();
    for (auto i : edge) cout<<i<<" ";

    return 0;   
}