#include<bits/stdc++.h>  
using namespace std; 
FILE *fi,*fo;

vector<int> d(vector<vector<int>> p)
{
    pair<int,int> a,b,c;
    int a0=(p[0][0]-p[1][0]);
    int a1=(p[0][1]-p[1][1]);
    int b0=(p[1][0]-p[2][0]);
    int b1=(p[1][1]-p[2][1]);
    int c0=(p[2][0]-p[0][0]);
    int c1=(p[2][1]-p[0][1]);
    a=make_pair(a0,a1);
    b=make_pair(b0,b1);
    c=make_pair(c0,c1);
    vector<int> res;
    if (a.first*b.first+a.second*b.second==0)
    {
        int x=(p[0][0]+p[2][0])-p[1][0];
        int y=(p[0][1]+p[2][1])-p[1][1];
        res.push_back(x);
        res.push_back(y);       
    }
    if (b.first*c.first+b.second*c.second==0)
    {
        int x=(p[0][0]+p[1][0])-p[2][0];
        int y=(p[0][1]+p[1][1])-p[2][1];
        res.push_back(x);
        res.push_back(y);
    }
    if (c.first*a.first+c.second*a.second==0)
    {
        int x=(p[1][0]+p[2][0])-p[0][0];
        int y=(p[1][1]+p[2][1])-p[0][1];
        res.push_back(x);
        res.push_back(y);
    }
    return res; 
}

int main()
{
	fo=freopen("a.out","w",stdout);
	vector<vector<int>> a={{2,8},{2,3},{13,3}};
    vector<int> res;
	res=d(a);

    cout<<res[0]<<" "<<res[1];
	//fprintf(fo,"%lld",o(a));
	//cout<<"asdasd";

	return 0;
}