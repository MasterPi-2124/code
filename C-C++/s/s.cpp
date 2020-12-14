#include<bits/stdc++.h>
using namespace std;

string s;
int d,q;

int main()
{
    cin>>q;
    for(int i=1;i<=q+1;i++)
    {
        d=0;
        getline(cin,s);
        s=s+" ";
        for(int j=0;j<s.length();j++)
        {   
            if (s[j+1]==' ' || s[j+1]=='\t' || s[j+1]=='\n')
            if ((s[j]<='Z'&&s[j]>='A')||(s[j]<='z'&&s[j]>='a')) d++;
        }
        cout<<d;
    }
    return 0;   
}