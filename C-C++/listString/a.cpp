#include<bits/stdc++.h>
using namespace std;

FILE *fi,*fo;
int n,k,m,cnt,temp;
vector<int> a;
string s;

void print()
{
    for (auto i:a)
    {
        cout<<i<<" ";
    }
    cout<<"\n";
    a=new vector<int>;
}

void listString()
{
    m=2;n=6;
    for (int j=0;j<=1;j++)
    {
        if (j==0 && temp<=m)
        {
            temp++;
            a.push_back(j);
            if (a.size()==n) print();
            else listString();
        }
        else if(j==1)
        {
            temp=0;
            a.push_back(j);
        }
    }
}

int main()
{
    fi=freopen("a.inp","r",stdin);
    fo=freopen("a.out","w",stdout);
    cin>>n>>k>>m;
    listString();
    return 0;
}