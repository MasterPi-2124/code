#include<bits/stdc++.h>
using namespace std;

FILE *fi,*fo; 

string extendString(string s)
{
    string res,temp;
    int d=0;
    for(int i=0;i<s.length();i++)
    {
        if (isdigit(s[i]))
        {
            d=d*10+(s[i]-'0');
            temp=temp+s[i];
        }
        else if (s[i]=='{')
        {
            if(d!=0)
            {
                int j=i+1;
                temp="";
                while(s[j]!='}')
                {
                    res=res+s[j];
                    temp=temp+s[j];
                    j++;
                }
                d--;
                while(d)
                {
                    res=res+temp;
                    d--;
                }
                i=j;
                temp="";
            }
            else
            {
                while(s[i]!='}') i++;
            }
        }
        else if (s[i]!='}' && d==0) res=res+s[i];
        else if (s[i]!='{' && d!=0)
        {
            //cout<<d<<endl;
            res=res+temp+s[i];
            temp="";
            d=0;
        }
    }
    if(d) res=res+temp;
    return res;
}

int main()
{
    fi=freopen("a.inp","r",stdin);
    fo=freopen("a.out","w",stdout);
    string s;
    //fscanf(fi,"%[^\n]",s);
    getline(cin,s);
    string res=extendString(s);
    cout<<extendString(s);
    //fprintf(fo,"%s\n%d",res,res.length());
   // cout<<s;
    return 0;   
}