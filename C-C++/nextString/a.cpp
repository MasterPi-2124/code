#include<bits/stdc++.h>
using namespace std;

FILE *fi,*fo;
int n;
string s;


int main()
{
    //fi=freopen("a.inp","r",stdin);
    //fo=freopen("a.out","w",stdout);
    cin>>n;
    cin>>s;
    int i=n-1;
    if(s=="1")
    {
        cout<<"-1";
        return 0;
    }
    while(i>=0)
    {
        if(s[i]=='0')
        {
            s[i]='1';
            cout<<s;
            return 0;
        }
        else
        {
            s[i]='0';
            int j=i-1;
            while(j>=0)
            {
                if(s[j]=='1' && j) s[j]='0';
                else if (s[j]=='0')
                {
                    s[j]='1';
                    cout<<s;
                    return 0;
                }
                else
                {
                    cout<<"-1";
                    return 0;
                }
                j--;
            }
        }
    }
    return 0;   
}