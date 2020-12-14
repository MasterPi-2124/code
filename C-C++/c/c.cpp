#include<bits/stdc++.h>
using namespace std;

FILE *fi,*fo;
string s;
int d,q;

int main()
{
    fi=freopen("a.inp","r",stdin);
    //fo=freopen("a.out","w",stdout);
    fscanf(fi,"%d",&q);
    for(int i=1;i<=q;i++)
    {
        d=0;
        fscanf(fi,"%[^\n]",s);
        //getline(cin,s);
        /*for(int j=0;j<s.length();j++)
        {
            if (s[j]==' ' || s[j]=='\t' || s[j]=='\n') d++;
        }*/
        //fprintf(fo,"%s",s);
        cout<<s;
    }
    return 0;   
}