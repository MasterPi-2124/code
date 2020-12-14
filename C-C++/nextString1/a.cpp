#include<bits/stdc++.h>
using namespace std;

FILE *fi,*fo;
int n,m;
vector<int> a;

vector<int> nextString(int i)
{
    if (i>=0)
    {
        if(a[i]<n-m+i+1)
        {
            a[i]++;
            for (int j=i+1;j<m;j++) a[j]=a[i]+j-i;
            return a;
        }
        else return nextString(i-1);
    }
    return {-1};
}
int main()
{
    fi=freopen("a.inp","r",stdin);
    fo=freopen("a.out","w",stdout);
    cin>>n>>m;
    for (int i=0;i<m;i++)
    {
        int t;
        cin>>t;
        a.push_back(t);
    }
    a=nextString(m-1);
    for(auto i:a)
    {
        cout<<i<<" ";
    }
    return 0;   
}