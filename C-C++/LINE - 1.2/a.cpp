#include<bits/stdc++.h>
using namespace std;

FILE *fi,*fo;
int n,u,v,d,m,res;
vector<pair<int,int>> a;
bool ahihi(pair<int,int> a, pair<int,int> b)
{
    if (a.first < b. first) return 1;
    return 0;
}
int search(int l,int r, int n)
{
    if (l+1 == r)
    {
        if (abs(a[l].first - n) < abs(a[r].first - n)) return a[l].second;
        else if (abs(a[l].first - n) > abs(a[r].first - n)) return a[r].second;
        else return min(a[l].second, a[r].second);
    }
    int m = (l+r)/2;
    if (a[m].first > n) return search(l,m,n);
    else if (a[m].first < n) return search(m,r,n);
    else return a[m].second;
}
int main()
{
    fi=freopen("a.inp","r",stdin);
    fo=freopen("a.out","w",stdout);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> u >> v;
        a.push_back(make_pair(v,u));
    }
    sort(a.begin(),a.end(),ahihi);
    while (cin>>m)
    {
        cout<<search(0,n-1,m)<<endl;
    }
    return 0;   
}