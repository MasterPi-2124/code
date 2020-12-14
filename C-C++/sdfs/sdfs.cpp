#include<iostream>
using namespace std;

FILE *fi,*fo; 
int n,b;
typedef struct Stack
{
    int data;
    Stack *next;
} Stack;

Stack *top;

bool isEmpty()
{
    if (top==NULL) return 1;
    return 0;
}

void push( int value)
{
    Stack *new_node=(Stack *)malloc(sizeof(Stack));
    new_node -> data=value;
    new_node -> next=top;
    top=new_node;
}

void pop()
{
    if (isEmpty()) fprintf(fo,"Stack is empty!");
    else
    {
        Stack *node=(Stack *)malloc(sizeof(Stack));
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
        Stack *node=top;
        while (node->next!=NULL)
        {
            fprintf(fo,"%d ",node->data);
            node=node->next;
        }
        fprintf(fo,"%d ",node ->data);
    }
    
}

int main()
{
    fi=freopen("a.inp","r",stdin);
    fo=freopen("a.out","w",stdout);
    /*fscanf(fi,"%d %d",&n,&b);
    while(n)
    {
        push(n%b);
        n/=b;
    }*/
    push(1);
    print();
    //Stack *a=(Stack *)malloc (sizeof(Stack));
    //print();
    return 0;   
}