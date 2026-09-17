#include <stdio.h>
#include <stdlib.h>

struct n
{
    int x;
    struct n * next;
    struct n * prev;
};

typedef struct n node;

node * addSorted(node * r, int x)
{
    if(r == NULL)
    {
        r = (node *)malloc(sizeof(node));
        r -> next = NULL;
        r -> prev = NULL;
        r -> x = x;
        return r;
    }

    if(r -> x > x)
    {
        node * temp = (node *)malloc(sizeof(node));
        temp -> x = x;
        temp -> next = r;
        temp -> prev = NULL;
        r -> prev = temp;
        return temp;
    }
    
    node * iter = r;

    while(iter -> next != NULL && iter -> next -> x < x)
    {
        iter = iter -> next;
    }

    node * temp = (node *)malloc(sizeof(node));
    temp -> x = x;
    temp -> next = iter -> next;
    temp -> prev = iter;
    iter -> next = temp;
    
    if (temp -> next != NULL)
    {
        temp -> next -> prev = temp;
    }

    return r;
}

node * delete(node * r, int x)
{
    if (r == NULL)
    {
        printf("The list is empty.\n");
        return r;
    }

    if(r -> x == x)
    {
        node * temp = r;
        r = r -> next;
        
        if (r != NULL) 
        {
            r -> prev = NULL;
        }
        
        free(temp);
        return r;
    }

    node * iter = r;
    
    while (iter -> next != NULL && iter -> next -> x != x)
    {
        iter = iter -> next;
    }

    if(iter -> next == NULL)
    {
        printf("The number did not find.\n");
        return r;
    }

    node * temp = iter -> next;
    iter -> next = temp -> next;
    
    if (temp -> next != NULL)
    {
        temp -> next -> prev = iter;
    }
    
    free(temp);
    return r;
}

void print(node * r)
{
    if (r == NULL) 
    {
        printf("List is empty.\n");
        return;
    }

    node * iter = r;
    while(iter != NULL)
    {
        printf("%d ", iter -> x);
        iter = iter -> next;
    }
    printf("\n");
}

int main()
{
    node * root;
    root = NULL;

    root = addSorted(root, 400);
    root = addSorted(root, 45);
    root = addSorted(root, 5);
    root = addSorted(root, 75);
    root = addSorted(root, 260);
    root = addSorted(root, 500);
    print(root);

    root = delete(root, 500);
    print(root);

    root = delete(root, 5);
    print(root);

    root = delete(root, 260);
    print(root); 

    return 0;
}