#include<bits/stdc++.h>
#include<setjmp.h>
using namespace std;

jmp_buf env;
FILE *fi,*fo;
int n,k,m,cnt,temp;
int a[10000];
bool done;

void print()
{
    for (int i = 1; i <= n; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<"\n";
}

void listString(int i) 
{
    for (int j = 0; j <= 1; j++)
    {
        if (j == 0)
        {
            if (temp < m-1)
            {
                temp++;
                a[i] = j;
            }
            else continue;
        }
        else
        {
            temp = 0;
            a[i] = j;
        }

        if (i == n) 
        {
            cnt++;
            if (cnt == k)
            {
                print();
                return;
            }
        }
        else listString(i+1);
    }
}

int main()
{
    //fi=freopen("a.inp","r",stdin);
    //fo=freopen("a.out","w",stdout);
    cin>>n>>k>>m;
    cnt = 0;
    listString(1);
    if (cnt < k) cout<<"-1";
    return 0;
}