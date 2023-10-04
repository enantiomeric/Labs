#include <stdio.h>

#define MAX_SIZE 100

typedef struct
{
    int data;
    int priority;
} Item;

Item priorityQueue[MAX_SIZE];
int rear = -1;

void enqueue(int data, int priority)
{
    if (rear == MAX_SIZE - 1)
    {
        printf("Priority queue is full. Cannot enqueue.\n");
        return;
    }

    int i = ++rear;
    while (i > 0 && priorityQueue[i - 1].priority > priority)
    {
        priorityQueue[i] = priorityQueue[i - 1];
        i--;
    }

    priorityQueue[i].data = data;
    priorityQueue[i].priority = priority;
}

void dequeue()
{
    if (rear == -1)
    {
        printf("Priority queue is empty. Cannot dequeue.\n");
        return;
    }

    printf("Dequeued item: %d (Priority: %d)\n", priorityQueue[0].data, priorityQueue[0].priority);

    for (int i = 0; i < rear; i++)
    {
        priorityQueue[i] = priorityQueue[i + 1];
    }

    rear--;
}

void displayPriorityQueue()
{
    if (rear == -1)
    {
        printf("Priority queue is empty.\n");
        return;
    }

    printf("Priority queue items:\n");
    for (int i = 0; i <= rear; i++)
    {
        printf("Item: %d (Priority: %d)\n", priorityQueue[i].data, priorityQueue[i].priority);
    }
}

int main()
{
    int choice, data, priority;

    while (1)
    {
        printf("Menu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display Priority Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter data to enqueue: ");
            scanf("%d", &data);
            printf("Enter priority: ");
            scanf("%d", &priority);
            enqueue(data, priority);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            displayPriorityQueue();
            break;
        case 4:
            printf("Exiting program.\n");
            exit(0);
        default:
            printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}