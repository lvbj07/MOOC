#include <stdio.h>
#include <stdlib.h>

typedef struct avlNode *AvlTree;
struct avlNode {
    int data;
    int height;
    AvlTree left;
    AvlTree right;
};

AvlTree insert(AvlTree t, int x);
int height(AvlTree t);
int max(int a, int b);
AvlTree rotateWithLeftChild(AvlTree t);
AvlTree rotateWithRightChild(AvlTree t);
AvlTree doubleWithLeftChild(AvlTree t);
AvlTree doubleWithRightChild(AvlTree t);

int main()
{
    AvlTree t = NULL;
    int number;
    int cnt;
    scanf("%d", &cnt);
    for (int i = 0; i != cnt; ++i)
    {
        scanf("%d", &number);
        t = insert(t, number);
    }
    printf("%d", t -> data);
    return 0;
}

AvlTree insert(AvlTree t, int x)
{
    if (t == NULL)
    {
        t = malloc(sizeof(struct avlNode));
        t -> data = x;
        t -> height = 0;
        t -> left = NULL;
        t -> right = NULL;
    }
    else
    {
        if (x < t -> data)
        {
            t -> left = insert(t -> left, x);
            if ( height(t -> left) - height(t -> right) == 2)
            {
                if ( x < t -> left -> data )
                {
                    t = rotateWithLeftChild(t);
                }
                else
                {
                    t = doubleWithLeftChild(t);
                }
            }
        }
        else
        {
            t -> right = insert(t -> right, x);
            if ( height(t -> right) - height(t -> left) == 2)
            {
                if ( x > t -> right -> data)
                {
                    t = rotateWithRightChild(t);
                }
                else
                {
                    t = doubleWithRightChild(t);
                }
            }
        }
    }
    t -> height = max(height(t -> left), height(t -> right)) + 1;
    return t;
}

int height(AvlTree t)
{
    if (t == NULL)
    {
        return -1;
    }
    else
    {
        return t -> height;
    }
}

int max(int a, int b)
{
    return a > b ? a : b;
}

AvlTree rotateWithLeftChild(AvlTree k2)
{
    AvlTree k1 = k2 -> left;
    k2 -> left = k1 -> right;
    k1 -> right = k2;
    k2 -> height = max(height(k2 -> left), height(k2 -> right)) + 1;
    k1 -> height = max(height(k1 -> left), height(k2)) + 1;
    return k1;
}

AvlTree rotateWithRightChild(AvlTree k2)
{
    AvlTree k1 = k2 -> right;
    k2 -> right = k1 -> left;
    k1 -> left = k2;
    k2 -> height = max(height(k2 -> left), height(k2 -> right)) + 1;
    k1 -> height = max(height(k1 -> left), height(k2)) + 1;
    return k1;
}

AvlTree doubleWithLeftChild(AvlTree k3)
{
    AvlTree k1 = k3 -> left;
    k3 -> left = rotateWithRightChild(k1);
    return rotateWithLeftChild(k3);
}

AvlTree doubleWithRightChild(AvlTree k3)
{
    AvlTree k1 = k3 -> right;
    k3 -> right = rotateWithLeftChild(k1);
    return rotateWithRightChild(k3);
}
