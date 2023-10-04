// Aditya Aparadh    22610082    S3
// Program to implement Menu driven Circular queue using arrays 

#include <stdio.h>

#define MAX_SIZE 100

int circularQueue[MAX_SIZE];
int front = -1, rear = -1;

int isFull()
{
    if ((front == 0 && rear == MAX_SIZE - 1) || (front == rear + 1))
    {
        return 1;
    }
    return 0;
}

int isEmpty()
{
    if (front == -1)
    {
        return 1;
    }
    return 0;
}

void enqueue(int item)
{
    if (isFull())
    {
        system("clear");
        printf("Queue Overflow\n");
        return;
    }
    else if (isEmpty())
    {
        front = rear = 0;
    }
    else
    {
        rear = (rear + 1) % MAX_SIZE;
    }
    circularQueue[rear] = item;
    system("clear");
    printf("%d enqueued to the circular queue\n", item);
}

int dequeue()
{
    int item;
    if (isEmpty())
    {
        system("clear");
        printf("Queue is empty. Cannot dequeue item.\n");
        return -1;
    }
    else if (front == rear)
    {
        item = circularQueue[front];
        front = rear = -1;
    }
    else
    {
        item = circularQueue[front];
        front = (front + 1) % MAX_SIZE;
    }
    return item;
}

int getFront()
{
    if (isEmpty())
    {
        system("clear");
        printf("Queue is empty.\n");
        return -1;
    }
    return circularQueue[front];
}

void display()
{
    if (isEmpty())
    {
        system("clear");
        printf("Queue is empty.\n");
        return;
    }
    system("clear");
    printf("Circular Queue elements: ");
    int i = front;
    do
    {
        printf("%d ", circularQueue[i]);
        i = (i + 1) % MAX_SIZE;
    } while (i != (rear + 1) % MAX_SIZE);
    printf("\n");
}

int main()
{
    system("clear");
    int choice, item;

    while (1)
    {
        printf("\nMENU:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Get Front\n");
        printf("4. Display\n\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter element to enqueue: ");
            scanf("%d", &item);
            enqueue(item);
            break;
        case 2:
            item = dequeue();
            if (item != -1)
            {
                system("clear");
                printf("Dequeued element: %d\n", item);
            }
            break;
        case 3:
            item = getFront();
            if (item != -1)
            {
                system("clear");
                printf("Front element: %d\n", item);
            }
            break;
        case 4:
            display();
            break;
        case 0:
            printf("Exiting the program.\n");
            return 0;
        default:
            system("clear");
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
