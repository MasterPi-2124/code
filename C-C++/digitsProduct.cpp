#include<bits/stdc++.h>  
using namespace std; 
FILE *fi,*fo;


int o(int n)
{
    if (n==0) return 10;
    if (n<10) return n;
    map<int,int> d;
    while(n)
    {
        if (n%2==0) {n/=2;d[2]++;}
        if (n%3==0) {n/=3;d[3]++;}
        if (n%5==0) {n/=5;d[5]++;}
        if (n%7==0) {n/=7;d[7]++;}
        if (n%2 && n%3 && n%5 && n%7 && n>=11) return -1;
        if (n==1) break;
    }
    int res=0;
    int a9=d[3]/2;
    int a8=d[2]/3;
    int a6=min(d[3]%2,d[2]%3);
    int a4=(d[2]%3-a6)/2;
    int a3=d[3]%2-a6;
    int a2=(d[2]%3-a6)%2;

    for(int i=1;i<=a2;i++) res=res*10+2;
    for(int i=1;i<=a3;i++) res=res*10+3;
    for(int i=1;i<=a4;i++) res=res*10+4;
    for(int i=1;i<=d[5];i++) res=res*10+5;
    for(int i=1;i<=a6;i++) res=res*10+6;
    for(int i=1;i<=d[7];i++) res=res*10+7;
    for(int i=1;i<=a8;i++) res=res*10+8;
    for(int i=1;i<=a9;i++) res=res*10+9;

    return res;
}

int main()
{
	fo=freopen("a.out","w",stdout);
	int a=3233;
	cout<<o(a);
	return 0;
}