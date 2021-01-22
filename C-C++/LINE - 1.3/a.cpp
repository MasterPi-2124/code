#include<bits/stdc++.h>
#define media "media:"
#define link "link:"
#define image "image:"
#define collapse "collapse:"
using namespace std;

FILE *fi,*fo;
int check;
string s,s1;
stack<string> a;
int main()
{
    fi=freopen("a.inp","r",stdin);
    fo=freopen("a.out","w",stdout);
    int d = 0;
    while (getline(cin,s))
    {
        while (s.length())
        {
            check = 0;
            if (s[0] != '[' && s[0] != ']')
            {
                while(s.length())
                {
                    s1 = s1 + s[0];
                    if (s1 == media)
                    {
                        check = 1;
                        cout << s1 << " ";
                        s1 = "";
                    }
                    else if (s1 == link)
                    {
                        check = 1;
                        cout << s1 << " ";
                        s1 = "";
                    }
                    else if (s1 == image)
                    {
                        check = 1;
                        cout << s1 << " ";
                        s1 = "";
                    }
                    else if (s1 == collapse)
                    {
                        check = 1;

                        cout << s1 << endl;
                        s1 = "";
                    }
                    s.erase(s.begin());
                    if (s[0] == '[' || s[0] == ']') break;
                }
                while (s1[0] == ' ') 
                    s1.erase(s1.begin());
                while(s1[s1.size()-1] == ' ')
                    s1.erase(s1.end());
                if (!check && s1.size())
                    cout << "text: " << s1 << endl;
                else if (s1.size())
                    cout << s1 << endl;
                s1 = "";
            }
            else if (s[0] == '[')
            {
                while(s.length())
                {
                    s1 = s1 + s[0];
                    s.erase(s.begin());
                    if (s[0] != '[') break;
                }
                a.push(s1);
                s1 = "";
            }
            else
            {
                while(s.length())
                {
                    s1 = s1 + s[0];
                    s.erase(s.begin());
                    if (s[0] != ']') break;
                }
                a.pop();
                s1 = "";
            }
        }
    }
    return 0;   
}