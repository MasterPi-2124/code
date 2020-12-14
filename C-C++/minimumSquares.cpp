#include<bits/stdc++.h>  
using namespace std; 
FILE *fi,*fo;

int minimumSquares(int n, int m)
{
    int a=min(m,n);
    int b=max(m,n);
    int res=0;
    while(a>1 && b>1)
    {
        int d=b/a;
        res+=d;
        fprintf(fo,"%d ",d);
        int c=a;
        a=b-a*d;
        b=c;
        fprintf(fo,"%d %d\n",a,b);
    }
    if (a && b) res+=max(a,b);
    return res;
}

int main()
{
	fo=freopen("a.out","w",stdout);
	int n=58,m=24;

    //cout<<minimumSquares(n);
	fprintf(fo,"%d",minimumSquares(n,m));
	//cout<<"asdasd";

	return 0;
}