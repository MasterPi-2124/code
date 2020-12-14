#include<iostream>
using namespace std;

FILE *fi,*fo; 
int n,b;
typedef struct Queue
{
    Queue *prev;
    int data;
    Queue *next;
} Queue;

Queue *top=NULL,*bottom=NULL;

bool isEmpty()
{
    if (top == NULL) return 1;
    return 0;
}

void push(int value)
{
    if(!isEmpty())   
    {
        Queue *new_node=(Queue *)malloc(sizeof(Queue));
        new_node -> data = bottom -> data;
        new_node -> prev = bottom -> prev;
        (bottom -> prev) -> next = new_node;
        bottom -> data = value;
        new_node -> next = bottom;
        bottom -> prev = new_node;
    }
    else
    {
        top -> data = value;
    }
    
}

void pop()
{
    if (isEmpty()) fprintf(fo,"Queue is empty!\n");
    else
    {
        Queue *node=(Queue *)malloc(sizeof(Queue));
        node=top;
        top=top->next;
        node->next=NULL;
        delete node;
    }
}

void print()
{
    if (isEmpty()) printf("Queue is empty!\n");
    else
    {
        Queue *node=top;
        while (node->next!=NULL)
        {
            printf("%d ",node->data);
            node=node->next;
        }
        printf("%d ",node ->data);
    }
    
}

void size()
{
    if (isEmpty()) printf("0\n");
    else
    {
        int i=1;
        Queue *node=top;
        while (node->next!=NULL)
        {
            i++;
            node=node->next;
        }
        printf("%d",i);
    }
    
}

int main()
{
    fi=freopen("a.inp","r",stdin);
    fo=freopen("a.out","w",stdout);
    top=new Queue;
    bottom=new Queue;
    top -> next=bottom;
    bottom -> prev=top;
   // push(1);
    //size();
    //push(2);
    //push(3);
    //push(4);
    //pop();
    print();
    //size();
    return 0;   
}