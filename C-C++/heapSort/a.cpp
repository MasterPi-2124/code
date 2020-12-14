#include<bits/stdc++.h>
using namespace std;

FILE *fi,*fo;
int m,n,u,v;
int a[100];
int visited[9];

void maxHeapify(int a[],int i, int n)
{
    if (2*i <= n)
    {
        int temp = 2*i;
        if (2*ii+1 <= n && a[temp] < a[2*i+1]) temp = 2*i+1;
        if (a[i] < a[temp])
        {
            swap(a[i],a[temp]);
            maxHeapify(a,temp,n);
        }
    }
}

void initMax_Heap(int a[], int n)
{
    for (int i = n/2;i >= 1;i--)
        maxHeapify(a,i,n);
}

void heapSort(int a[])
{
    initMax_Heap(a,n);
    int i = n;
    while(i > 1)
    {
        swap(a[1],a[i]);
        maxHeapify(a,1,i-1);
        i--;
    }
}

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