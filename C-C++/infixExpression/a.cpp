//Calculate for both float and integer numbers
#include<bits/stdc++.h>
using namespace std;

FILE *fi,*fo;
string s;
vector<string>new_s;

bool check(char x, char y)
{
    if (((x=='*'|| x=='/') && (y=='+'|| y=='-'))
      || ((x=='^') && (y=='+'|| y=='-'))
      || ((x=='^') && (y=='*'|| y=='/'))) return 1;
    return 0;
}

vector<string> toInfix(string s)
{
    stack<char> a;
    int i=0;
    while(i<s.size())
    {
        if(isdigit(s[i]))
        {
            string x="";
            int j=i;
            while(isdigit(s[j]) || (s[j]=='.' && isdigit(s[j+1])))
            {
                x=x+s[j];
                j++;
            }
            new_s.insert(new_s.end(),x);
            i=j-1;
        }
        else if (s[i]=='(') a.push(s[i]);
        else if (s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/' || s[i]=='^')
        {
            while (a.size() && !check(s[i],a.top()) && a.top()!='(')
            {
                string c="";
                c=c+a.top();
                new_s.insert(new_s.end(),c);
                a.pop();
            }
            a.push(s[i]);
        }
        else if(s[i]==')')
        {
            while (a.top()=='+' || a.top()=='-' || a.top()=='*' || a.top()=='/' || a.top()=='^')
            {
                string c="";
                c=c+a.top();
                new_s.insert(new_s.end(),c);
                a.pop();
            }
            if(a.top()=='(') a.pop();
        }
        i++;
    }
    while(a.size())
    {
        string c="";
        c=c+a.top();;
        new_s.insert(new_s.end(),c);
        a.pop();
    }
    return new_s;
}

double Calculate(vector<string> s)
{
    stack<double> temp;
    int i=0;
    while(i<s.size())
    {
        if (isdigit(s[i][0]))
        {
            double d=stod(s[i]);
            temp.push(d);
        }
        else
        {
            double a1=temp.top();
            temp.pop();
            double a2=temp.top();
            temp.pop();
            if (s[i]=="+") temp.push(a1+a2);
            else if(s[i]=="-") temp.push(a2-a1);
            else if(s[i]=="*") temp.push(a1*a2);
            else if(s[i]=="/") temp.push(a2/a1);
            else if(s[i]=="^") temp.push(pow(a2,a1));
        }
        i++;
    }
    return temp.top();
}

int main()
{
    fi=freopen("a.inp","r",stdin);
    fo=freopen("a.out","w",stdout);
    cin>>s;
    for (auto i:toInfix(s))
    cout<<i<<" ";
    cout<<endl;
    cout<<Calculate(toInfix(s))<<endl;
    printf("%f",Calculate(toInfix(s)));
    return 0;   
}