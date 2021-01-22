//Calculate for both float and integer numbers
#include<bits/stdc++.h>
using namespace std;

FILE *fi,*fo;
string s;
vector<string>new_s;

typedef struct Node
{
    int data;
    Node *next;
} Node;

void *reverseList(Node *head)
{
    if (head == NULL) return;
    Node *p = head ->next;
    head = p -> next;
    p -> next = head;
    reverseList(head);
}

int main()
{
    fi=freopen("a.inp","r",stdin);
    fo=freopen("a.out","w",stdout);
    Node *head = new Node;
    head -> data = 1;
    Node *a = new Node;
    a -> data = 2;
    head -> next = a;
    Node *b = new Node;
    b -> data = 3;
    a -> next = b;
    Node *c = new Node;
    c -> data = 4;
    b -> next = c;
    Node *d = new Node;
    d -> data = 5;
    c -> next = d;
    reverseList(head);
    //printf("%f",Calculate(toInfix(s)));
    return 0;   
}