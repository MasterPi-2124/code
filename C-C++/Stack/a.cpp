#include<iostream>
using namespace std;

FILE *fi,*fo; 
int n,b;
typedef struct Node{
    int data;
    Node *next;
}Node;

typedef struct Stack
{
    Node *top;

    bool isEmpty()
    {
        if (top==NULL) return 1;
        return 0;
    }

    void push( int value)
    {
        Node *new_node=(Node *)malloc(sizeof(Node));
        new_node -> data=value;
        new_node -> next=top;
        top=new_node;
    }

    void pop()
    {
        if (isEmpty()) fprintf(fo,"Stack is empty!");
        else
        {
            Node *node=(Node *)malloc(sizeof(Node));
            node=top;
            top=top->next;
            node->next=NULL;
            delete node;
        }
    }

    void print()
    {
        if (isEmpty()) fprintf(fo,"Stack is empty!");
        else
        {
            Node *node=top;
            while (node->next!=NULL)
            {
                fprintf(fo,"%d ",node->data);
                node=node->next;
            }
            fprintf(fo,"%d ",node ->data);
        }

    }
} Stack;

int main()
{
    fi=freopen("a.inp","r",stdin);
    fo=freopen("a.out","w",stdout);
    Stack t;
    /*fscanf(fi,"%d %d",&n,&b);
    while(n)
    {
        push(n%b);
        n/=b;
    }*/
    t.push(1);
    t.print();
    //Stack *a=(Stack *)malloc (sizeof(Stack));
    //print();
    return 0;   
}