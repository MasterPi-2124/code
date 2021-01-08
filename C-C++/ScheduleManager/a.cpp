#include<bits/stdc++.h>
using namespace std;

FILE *fi,*fo;
int n,m,d,f,s;
string g;
typedef struct Time{
    string name;
    int day;
    int start;
    int finish;
} Time;
vector<Time> a[50];
vector<Time> res;

void scheduleManager(int i)
{
    int check = 1;
    for (auto j : a[i])
    {
        for (auto k : res)
        {
            if ((k.day == j.day) && ((j.start < k.finish && j.start >= k.start) || (j.finish > k.start && j.start <= k.start)))
            {
                check = 0;
                break;
            }
            else check = 1;
        }
        if (check)
        {
            res.push_back(j);
            scheduleManager(i+1);
        }
        else continue;
    }
    if (!check)
    {
        res.pop_back();
        return;
    }
    if (res.size() == n)
    {
        for (auto j : res)
        {
            cout<<j.name<<" "<<j.day<<" "<<j.start<<" "<<j.finish<<endl;
            i++;
        }
        cout<<endl;
        res.erase(res.begin(),res.end());
        return;
    }
}

int main()
{
    fi=freopen("a.inp","r",stdin);
    fo=freopen("a.out","w",stdout);

    cin>>n;
    for (int i = 1; i <= n; i++)
    {
        cin>>m;
        for (int j = 1; j <= m; j++)
        {
            cin>>g;
            cin>>d>>s>>f;
            Time temp;
            temp.name = g;
            temp.day = d;
            temp.start = s;
            temp.finish = f;
            a[i].push_back(temp);
        }
    }

    int i = 1;
    scheduleManager(i);
    return 0;   
}