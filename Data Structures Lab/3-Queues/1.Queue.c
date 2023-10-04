// Aditya Aparadh    22610082    S3
// Program to implement Menu driven linear queue using arrays

#include <stdio.h>

#define MAX_SIZE 100

int queue[MAX_SIZE];
int front = -1, rear = -1;

int isEmpty()
{
    return (front == -1 && rear == -1);
}

int isFull()
{
    return (rear == MAX_SIZE - 1);
}

void enqueue(int item)
{
    if (isFull())
    {
        system("clear");
        printf("Queue overflow.\n");
        return;
    }
    else if (isEmpty())
    {
        front =0;
        rear = 0;
    }
    else
    {
        rear++;
    }
    queue[rear] = item;
    system("clear");
    printf("%d enqueued to the queue\n", item);

}

int dequeue()
{
    int item;
    if (isEmpty())
    {
        system("clear");
        printf("Queue Underflow\n");
        return -1;
    }
    else if (front == rear)
    {
        item = queue[front];
        queue[front] = NULL;
        front = -1;
        rear = -1;
    }
    else
    {
        item = queue[front];
        queue[front] = NULL;
        front++;
    }
    return item;
}

int getFront()
{
    if (isEmpty())
    {
        printf("Queue is empty.\n");
        return -1;
    }
    return queue[front];
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
    printf("Queue elements: ");
    for (int i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }
    printf("\n");
    
}

int main()
{
    int choice, item;

    while (1==1)
    {
        printf("\nMENU:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Get Front\n");
        printf("4. Display Queue\n\n");
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
            system("clear");
            return 0;
        default:
            system("clear");
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
