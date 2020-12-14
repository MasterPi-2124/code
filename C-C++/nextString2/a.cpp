#include<bits/stdc++.h>
using namespace std;

FILE *fi,*fo;
int n;
vector<int> a;

vector<int> nextString(int i)
{
    if (i==0 && a[i]>a[i+1]) return {-1};
    if (a[i]>a[i-1])
    {
        for (int j=n-1;j>=i;j--)
        {
            if (a[j]>a[i-1])
            {
                swap(a[i-1],a[j]);
                sort(a.begin()+i,a.end());
                return a;
            }
        }
    }
    else return nextString(i-1);
}
int main()
{
    fi=freopen("a.inp","r",stdin);
    fo=freopen("a.out","w",stdout);
    cin>>n;
    for (int i=0;i<n;i++)
    {
        int t;
        cin>>t;
        a.push_back(t);
    }
    a=nextString(n-1);
    for(auto i:a)
    {
        cout<<i<<" ";
    }
    return 0;   
}