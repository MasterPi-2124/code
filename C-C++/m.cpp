#include<bits/stdc++.h>  
using namespace std; 
FILE *fi,*fo;

int a(vector<int> x)
{
    multimap<int,int> map;
    static int check[10000002];
    memset(check,0,sizeof(check));
    for (int i=0;i<x.size();i++)
    {
        int d=0;
        while(x[i]%2==0)
        {
            d++;
            x[i]/=2;
        }
        map.insert(pair<int,int> (x[i],d));
    }
    int res=0;
    for(auto i : map)
    {
        if(!check[i.first])
        {
            auto iterpair = map.equal_range(i.first);
            int d=0;
            for (auto it = iterpair.first; it != iterpair.second; ++it)
            {
                if (d<=it->second)
                {
                    d=it->second;  
                }
            }
            res+=d;
        }
        check[i.first]=1;
    }
    for(auto i : map) cout<<i.first<<" "<<i.second<<endl;
    return res;
}

int main()
{
	fo=freopen("a.out","w",stdout);
	vector<int> n={8,3,10,4};

    cout<<a(n);
	//fprintf(fo,"%lld",o(a));
	//cout<<"asdasd";

	return 0;
}