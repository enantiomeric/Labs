#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} NODE;

typedef struct
{
    NODE *start;
    NODE *end;
    int length;
} LIST;

void insertNodeBeginning(LIST *list, int data)
{

    NODE *n = (NODE *)malloc(sizeof(NODE));
    n->data = data;
    if (list->length == 0)
    {
        n->next = NULL;
        list->start = n;
        list->end = n;
    }
    else
    {
        n->next = list->start;
        list->start = n;
    }
    list->length++;
}

void insertNodeEnd(LIST *list, int data)
{

    NODE *n = (NODE *)malloc(sizeof(NODE));
    n->data = data;
    n->next = NULL;
    if (list->length == 0)
    {
        n->next = NULL;
        list->start = n;
        list->end = n;
    }
    else
    {
        list->end->next = n;
        list->end = n;
    }
    list->length++;
}

void PrintList(LIST *list)
{

    NODE *n = list->start;

    while (n->next != NULL)
    {
        printf("%d  ->  ", n->data);
        n = n->next;
    }
    printf("%d  -> NULL\n", list->end->data);
}

void deleteNodeBeginning(LIST *list)
{
    if (list->length == 0)
    {
        printf("List Empty");
    }
    else
    {
        NODE *temp = (NODE *)malloc(sizeof(NODE));
        temp = list->start;
        list->start = list->start->next;
        free(temp);
    }
}

void deleteNodeEnd(LIST *list)
{
    if (list->length == 0)
    {
        printf("List Empty");
    }
    else
    {

        NODE *temp = (NODE *)malloc(sizeof(NODE));
        NODE *n = (NODE *)malloc(sizeof(NODE));
        // NODE *n;

        temp = list->end;

        n = list->start;
        while (n->next != list->end)
        {
            system("timeout 1");
            n = n->next;
        }
        list->end = n;
        free(temp);
        free(n);
    }
}

int main()
{
    LIST *myList = (LIST *)malloc(sizeof(LIST));
    insertNodeBeginning(myList, 55);
    insertNodeBeginning(myList, 230);
    insertNodeEnd(myList, 68);
    insertNodeBeginning(myList,33);
    deleteNodeEnd(myList);
    PrintList(myList);
}