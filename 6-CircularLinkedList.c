#include <stdio.h>
#include <stdlib.h>

struct n
{
    int x;
    struct n * next;
};

typedef struct n node;

node * add(node * r, int x)
{
    //  if link list is empty
    if(r == NULL)
    {
        r = (node *)malloc(sizeof(node));
        r -> next = r;
        r -> x = x;
        return r;
    }

    node * iter = r;
    while(iter -> next != r)
    {
        iter = iter -> next;
    }
    iter -> next = (node *)malloc(sizeof(node));
    iter -> next -> x = x;
    iter -> next -> next = r;

    return r;
}

node * addSorted(node * r, int x)
{
    //  if link list is empty
    if(r == NULL)
    {
        r = (node *)malloc(sizeof(node));
        r -> next = r;
        r -> x = x;
        return r;
    }

    if(r -> x > x)
    {
        node * temp = (node *)malloc(sizeof(node));
        temp -> x = x;
        temp -> next = r;
        node * iter = r;
        while (iter -> next != r)
        {
            iter = iter -> next;
        }
        iter -> next = temp;

        return temp;
    }
    
    node * iter = r;

    while(iter -> next != r && iter -> next -> x < x)
    {
        iter = iter -> next;
    }

    node * temp = (node *)malloc(sizeof(node));
    temp -> next = iter -> next;
    iter -> next = temp;
    temp -> x = x;
    return r;
}

node * delete(node * r, int x)
{
    node * temp;
    node * iter = r;

    if (r == NULL)
    {
        printf("The list is empty.\n");
        return r;
    }

    if(r -> x == x)
    {
        if(r -> next == r) 
        {
            free(r);
            return NULL;
        }

        while (iter -> next != r)
        {
            iter = iter -> next;
        }
        iter -> next = r -> next;
        temp = r;              
        r = r -> next;            
        free(temp);              
        return r;
    }

    while (iter -> next != r && iter -> next -> x != x)
    {
        iter = iter -> next;
    }

    if(iter -> next == r)
    {
        printf("The number did not find.\n");
        return r;
    }

    temp = iter -> next;
    iter -> next = iter -> next -> next;
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
    printf("%d ", iter -> x);
    iter = iter -> next;

    while(iter != r)
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