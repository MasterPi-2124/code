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
};

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
		if (u == NULL)
			return;
		preOrder(u->child);
		cout<<u->data<<endl;
		preOrder(u->neighbor);
	}

	void postOrder(Node* u)
	{
		if (u == NULL)
			return;
		preOrder(u->child);
	    preOrder(u->neighbor);
		cout<<u->data<<endl;
	}

} Tree;

int main()
{
    fi=freopen("a.inp","r",stdin);
    fo=freopen("a.out","w",stdout);
   	Tree t;
	t.root = new Node(1);
	Node* root=t.root;
    t.insert_child(11,root);
	Node* a = root->child;
    t.insert_neighbor(12,a);
	t.insert_child(111,a);
	t.insert_neighbor(112,a->child);
	a = a->neighbor;
	t.insert_child(121,a);
	t.insert_neighbor(122,a->child);
	t.preOrder(root);
	cout<<t.size();
//	t.remove(a);
	//t.preOrder(root);
	//cout<<t.size();	
    return 0;
}