#include<bits/stdc++.h>
using namespace std;
string str;
FILE *fi,*fo;
string res;

string removeDuplicate(string s)
{
    string temp;
    int n=s.length();
    if (n==1) return s;
    if (s[0]!=s[1]) 
    {
        temp=s[0];
        s.erase(s.begin());
    }
    else s.erase(s.begin());
    return temp+removeDuplicate(s);
}

typedef struct Node{
    struct Node *prev;
    string name;
    int birth;
    int mark;
    struct Node *next;
} student;

student *tail;

void printDS(int c)
{
    student *node=tail;
    while (node->prev!=NULL)
    {
        if ((2020 - node->birth) > c && (1&(2020 - node->birth))) 
        cout<<node->name<<" "<<node->mark<<"\n";
        node=node->prev;
    }
}

int main()
{
    string name;
    int mark,birth;
    fi=freopen("a.inp","r",stdin);
    fo=freopen("a.out","w",stdout);
    getline(cin,str);
    cout<<removeDuplicate(str)<<"\n";
    student *new_node;
    tail = new student;
    for (int i=1;i<=4;i++)
    {
        new_node = new student;
        cin>>name;
        cin>>birth;
        cin>>mark;
        new_node->name=name;
        new_node->birth=birth;
        new_node->mark=mark;
        tail->next=new_node;
        new_node->prev=tail;
        tail=new_node;
    }
    printDS(18);
    

    return 0;  }