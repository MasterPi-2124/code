#include<bits/stdc++.h>
using namespace std;

FILE *fi,*fo;
string s;
vector<string>new_s;

typedef struct Node{
    int data;
    Node *next;
} Node;

Node *top;
Node *reverseList(Node *head)
{
    if (head -> next == NULL) return top;
    Node *p = new Node;
    p = head -> next;
    head -> next = p -> next;
    p -> next = top;
    top = p;
    head = reverseList(head);
}

int main()
{
    //fi=freopen("a.inp","r",stdin);
    //fo=freopen("a.out","w",stdout);

    // Initiation
    Node *head = new Node;
    head -> data = 1;
    Node *a = new Node;
    a -> data = 2;
    Node *b = new Node;
    b -> data = 3;
    Node *c = new Node;
    c -> data = 4;
    Node *d = new Node;
    d -> data = 5;
    Node *e = new Node;
    e -> data = 6;
    head -> next = a;
    a -> next = b;
    b -> next = c;
    c -> next = d;
    d -> next = e;
    // Make top = head, so that every time a node is swapped, the node top still points to the first element.
    top = head;
    Node *f = reverseList(head);
    while (f != NULL)
    {
        cout<< f -> data << " ";
        f = f -> next;
    }
    return 0;   
}