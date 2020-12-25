#include<bits/stdc++.h>
using namespace std;

FILE *fi,*fo;
int n,x;

typedef struct Node
{
    int key;
    struct Node *left, *right, *parent;
};

typedef struct tree
{
    Node *root;

    Node *findMax(Node *x)
    {
        Node *res;
        while (x != NULL)
        {
            res = x;
            x = x -> right;
        }
        return res;
    }

    Node *findMin(Node *x)
    {
        Node *res;
        while (x != NULL)
        {
            res = x;
            x = x -> left;
        }
        return res;
    }

    int Predecessor(Node *x)
    {
        if (x == NULL) return NULL;
        if (x -> left != NULL) return findMax(x -> left) -> key;
        else
        {
            Node *p = x;
            Node *temp = x -> parent;
            while (temp -> right != p && temp != NULL)
            {
                p = temp;
                temp = temp -> parent;
            }
            return temp -> key;
        }
    }

    Node *create(int key)
    {
        Node *node = new Node;
        if (node == NULL)
        {
            printf("ajih");
            exit(1);
        }
        else
        {
            node -> key = key;
            node -> left = NULL;
            node -> right = NULL;
            node -> parent = NULL;
        }
    }
    Node *search(int value)
    {
        Node *temp = root;
        while (temp != NULL)
        {
            if (value == temp -> key) return temp;
            while (value > temp -> key)
            {
                temp = temp -> right;
                if (temp == NULL) return NULL;
            }
            while (value < temp -> key)
            {
                temp = temp -> left;
                if (temp == NULL) return NULL;
            }
        }
    }

    int Successor(Node *x)
    {
        if (x == NULL) return NULL;
        if (x -> right != NULL) return findMin(x -> right) -> key;
        else
        {
            Node *p = x;
            Node *temp = x -> parent;
            while (temp -> left != p && temp != NULL)
            {
                p = temp;
                temp = temp -> parent;
            }
            return temp -> key;
        }
    }

    void insert(int value)
    {
        if (root == NULL) root = create(value);
        else 
        {
            Node *temp = root;
            while (root != NULL)
            {
                while (value < root -> key)
                {
                    Node *u = root -> left;
                    if (u == NULL)
                    {
                        u = create(value);
                        u -> parent = root;
                        root -> left = u;
                        root = temp;
                        return;
                    } else root = root -> left;
                }

                while (value > root -> key)
                {
                    Node *u = root -> right;
                    if (u == NULL)
                    {
                        u = create(value);
                        u -> parent = root;
                        root -> right = u;
                        root = temp;
                        return;
                    } else root = root -> right;
                }
            }
        }
    }

    void remove(Node *x)
    {
        if (x == NULL)
        {
            printf("Not Found.");
            return;
        }
        Node *temp;
        if (x -> left != NULL && x -> right != NULL)
        {
            temp = findMin(x -> right);
            x -> key = temp -> key;
            temp -> parent -> left = NULL;
            delete(temp);
        }
        else if (x -> left == NULL && x -> right == NULL)
        {
            if (x -> parent -> left == x) x -> parent -> left = NULL;
            else x -> parent -> right = NULL;
            delete(x);
        }
        else if (x -> left != NULL && x -> right == NULL)
        {
            if (x -> parent -> left == x) x -> parent -> left = x -> left;
            else x -> parent -> right = x -> left;
            x -> left -> parent = x -> parent;
            delete(x);
        }
        else if (x -> left == NULL && x -> right != NULL)
        {
            if (x -> parent -> left == x) x -> parent -> left = x -> right;
            else x -> parent -> right = x -> right;
            x -> right -> parent = x -> parent;
            delete(x);
        }

    }

	void inOrder(Node* u)
	{
		if (u == NULL) return;
		inOrder(u -> left);
		cout<<u -> key<<" ";
		inOrder(u -> right);
	}

} tree;

tree t;
int main()
{
    fi=freopen("a.inp","r",stdin);
    fo=freopen("a.out","w",stdout);
    cin>>n;
    for (int i = 1; i <= n; i++)
    {
        cin>>x;
        t.insert(x);
    }
    return 0;   
}