#include<bits/stdc++.h>
using namespace std;

FILE *fi,*fo;
int n;
string s,s1,input;
map<string, string> a;



int main()
{
    fi=freopen("a.inp","r",stdin);
    fo=freopen("a.out","w",stdout);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin>>s;
        s.pop_back();
        getline(cin,s1);
        a[s] = s1;
    }
    cin >> input;
    int d = 1;
    for (auto i : a)
    {
        if (input == i.first)
        {
            d = 2;
            cout << i.first << ":" << i.second << endl;
            continue;
        }
        if (d != 1 && d <= 5)
        {
            cout << i.first << ":" << i.second << endl;
            d++;
        }
    }
    if (d == 1) cout<<"no data";
    return 0;   
}