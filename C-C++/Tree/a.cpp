#include<bits/stdc++.h>
using namespace std;
FILE *fi,*fo;

typedef struct Node{
	int data;
	struct Node* neighbor;
	struct Node* child;

	Node(int value)
	{
        data = value;
        neighbor = NULL;
		child = NULL;
    }
} Node;

typedef struct Tree
{
	Node* root;
	int n = 1;
	void insert_child(int value, Node* u)
	{
		Node* new_node = new Node(value);
		u->child=new_node;
		n++;
	}
	void insert_neighbor(int value, Node* u)
	{
		if (u==root)
		{
			cout<<"Can't insert a neighbor to a root.";
			return;
		}
		else
		{
			Node* new_node = new Node(value);
			new_node->neighbor=u->neighbor;
			u->neighbor=new_node;
		}
		n++;
	}

	void remove(Node* u)
	{
		if (u == root)
		{
			root = NULL;
			n = 0;
			return;
		}
		Node* it = root;
		if (it->neighbor == u)
		{
			it->neighbor = u->neighbor;
			free(u);
			n--;
		}
		if (it->child == u)
		{
			it->child = u->neighbor;
			free(u);
			n--;
		}
		remove(u->child);
		remove(u->neighbor);
	}

	void preOrder(Node* u)
	{
		if (u == NULL)
			return;
		cout<<u->data<<" ";
		preOrder(u->child);
		preOrder(u->neighbor);
	}

	int size()
	{
		return n;
	}

	void inOrder(Node* u)
	{
		if (u -> child == NULL)
		{
			cout<<u -> data<<" ";
			return;
		}
		inOrder(u -> child);
		cout<<u -> data<<" ";
		Node *temp = u -> child;
		while (temp -> neighbor != NULL)
		{
			temp = temp -> neighbor;
			inOrder(temp);
		}
	}

	void postOrder(Node* u)
	{
		if (u == NULL)
			return;
		postOrder(u->child);
		cout<<u->data<<" ";
	    postOrder(u->neighbor);
	}

} Tree;

int main()
{
    fi=freopen("a.inp","r",stdin);
    fo=freopen("a.out","w",stdout);
   	Tree t;
	t.root = new Node(1);
	Node* root=t.root;
    t.insert_child(2,root);
	Node* a = root->child;
    t.insert_neighbor(9,a);
	t.insert_child(3,a);
	t.insert_neighbor(4,a->child);
	t.insert_child(10,a->neighbor);
	t.insert_neighbor(11,a->neighbor->child);
	t.insert_child(5,a->child->neighbor);
	t.insert_neighbor(6,a->child->neighbor->child);
	t.insert_neighbor(7,a->child->neighbor->child->neighbor);
	t.insert_child(8,a->child->neighbor->child->neighbor->neighbor);
	t.insert_child(12,a->neighbor->child->neighbor);
	
	cout<<"InOrder: ";
	t.inOrder(root);
	cout<<endl<<"PostOrder: ";
	t.postOrder(root);
	cout<<endl<<"PreOrder: ";
	t.preOrder(root);
    return 0;
}