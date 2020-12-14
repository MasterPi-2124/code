#include<bits/stdc++.h>
using namespace std;

FILE *fi,*fo;
int m,n,u,v;
int a[100];
int visited[9];

typedef struct priorityQueue
{
    int a[100];

    void maxHeapify(int i, int n)
    {
        if (2*i <= n)
        {
            int temp = 2*i;
            if (2*i+1 <= n && a[temp] < a[2*i+1]) temp = 2*i+1;
            if (a[i] < a[temp])
            {
                swap(a[i],a[temp]);
                maxHeapify(a,temp,n);
            }
        }
    }

    int max()
    {
        return a[1];
    }

    void increaseKey(int k,int i)
    {
        if (k < a[i])
        {
            cout<<"error.";
            return;
        }
        a[i] = k;
        while (a[i/2] < a[i] && i > 1)
        {
            swap(a[i/2],a[i]);
            i = i/2;
        }
    }

    int getMax()
    {
        int res = a[1];
        if (size() < 1)
        {
            cout<<"error.";
            return;
        }
        a[1]=a[n];
        max
        return res;
    }
};

int main()
{
    fi=freopen("a.inp","r",stdin);
    fo=freopen("a.out","w",stdout);
    cin>>n;
    for (int i = 1;i <= n;i++)
        cin>>a[i];
    heapSort(a);
    for (int i = 1;i <= n;i++)
        cout<<a[i]<<" ";
    return 0;   
}