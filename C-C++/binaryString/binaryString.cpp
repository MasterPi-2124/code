#include<bits/stdc++.h>
using namespace std;

FILE *fi,*fo; 
int n,k,res;
long long check[10000];

long long countBinary(int n,int k)
{
    if(n<k) return 1<<n;
    else if (n==k) return (1<<n)-1;
    for(int i=1;i<=k;i++)
        if (!check[n-i])
        {
            check[n-i]=countBinary(n-i,k);
            res+=check[n-i];
        }
        else res+=check[n-i];
    return res;
}

int main()
{
    //fi=freopen("a.inp","r",stdin);
    //fo=freopen("a.out","w",stdout);
    cin>>n>>k;
    res=0;
    memset(check,0,sizeof(check));
    cout<<countBinary(n,k);
    return 0;   
}