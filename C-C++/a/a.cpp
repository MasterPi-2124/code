#include<bits/stdc++.h>
using namespace std;

FILE* fi,fo;
int n,q;
map<int,int> divisors;

void divisorOf(int n)
{    
    int i=2;
    while(n>1)
    {
       if(n%i==0)
       {
           n/=i;
           divisors[i]++;
       }
       else i++;
    }
}

int main()
{
    fi=freopen("a.inp","r",stdin);
    fscanf(fi,"%d",&q);
    for(int i=1;i<=q;i++)
    {
        map<int,int> a;
        fscanf(fi,"%d",&n);
        divisorOf(n);
        divisorOf(n+1);
        divisorOf(n+2);
        int k1=1,k2=1;
        for (auto i:divisors)
        {
            k1*=(2*i.second+1);
            k2*=(i.second+1);
        }
        k1=k1-floor(k1/2);
        cout<<k1-k2<<endl;
    }
    return 0;   
}
    /*
#include<bits/stdc++.h>
using namespace std;

int n,q;

int main()
{
    fscanf(fi,"q;
    for(int i=1;i<=q;i++)
    {
        fscanf(fi,"n;
        int res=0;
        int t=n*(n+1)*(n+2);
        for (int i=2;i<t;i++)
            if(t%i!=0 && (t*t)%i==0) res++;
        cout<<res<<endl;
    }
    return 0;   
}*/
