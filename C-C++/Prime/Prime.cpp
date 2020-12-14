#include<bits/stdc++.h>
using namespace std;

FILE *fi,*fo; 
int n,b;

bool isPrime(int n)
{
    if (n==0 || n==1) return 0;
    for (int i=2;i<=sqrt(n);i++) 
     if (n%i==0) return 0;
    return 1;
}

int main()
{
    //fi=freopen("a.inp","r",stdin);
    //fo=freopen("a.out","w",stdout);
    cin>>n;
    if (isPrime(n)) cout<<"YES";
    else cout<<"NO";
    return 0;   
}