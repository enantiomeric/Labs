#include <stdio.h>

#define MAX_SIZE 100

int dequeue[MAX_SIZE];
int front = -1, rear = -1;

int isFrontEmpty()
{
    return (front == -1);
}

int isRearEmpty()
{
    return (rear == -1);
}

int isFull()
{
    return ((front == 0 && rear == MAX_SIZE - 1));
}

void enqueueFront(int item)
{
    if (isFull())
    {
        system("clear");
        printf("Queue is full. Cannot enqueue item.\n");
        return;
    }
    if (front == -1)
    {
        front = rear = 0;
    }
    else if (front == 0)
    {
        front = MAX_SIZE - 1;
    }
    else
    {
        front--;
    }
    dequeue[front] = item;
    system("clear");
    printf("%d enqueued to the front of the dequeue\n", item);
}

void enqueueRear(int item)
{
    if (isFull())
    {
        system("clear");
        printf("Queue is full\n");
        return;
    }
    if (front == -1)
    {
        front = rear = 0;
    }
    else if (rear == MAX_SIZE - 1)
    {
        rear = 0;
    }
    else
    {
        rear++;
    }
    dequeue[rear] = item;
    system("clear");
    printf("%d enqueued to the rear of the dequeue\n", item);
}

int dequeueFront()
{
    int item;
    if (isFrontEmpty())
    {
        system("clear");
        printf("Front of the dequeue is empty. Cannot dequeue item.\n");
        return -1;
    }
    item = dequeue[front];
    if (front == rear)
    {
        front = rear = -1;
    }
    else if (front == MAX_SIZE - 1)
    {
        front = 0;
    }
    else
    {
        front++;
    }
    return item;
}

int dequeueRear()
{
    int item;
    if (isRearEmpty())
    {
        system("clear");
        printf("Rear of the dequeue is empty. Cannot dequeue item.\n");
        return -1;
    }
    item = dequeue[rear];
    if (front == rear)
    {
        front = rear = -1;
    }
    else if (rear == 0)
    {
        rear = MAX_SIZE - 1;
    }
    else
    {
        rear--;
    }
    return item;
}

int getFront()
{
    if (isFrontEmpty())
    {
        system("clear");
        printf("Front of the dequeue is empty.\n");
        return -1;
    }
    return dequeue[front];
}

int getRear()
{
    if (isRearEmpty())
    {
        system("clear");
        printf("Rear of the dequeue is empty.\n");
        return -1;
    }
    return dequeue[rear];
}

void display()
{
    if (isFrontEmpty() && isRearEmpty())
    {
        system("clear");
        printf("Dequeue is empty.\n");
        return;
    }
    system("clear");
    printf("Dequeue elements: ");
    int i = front;
    do
    {
        printf("%d ", dequeue[i]);
        if (i == rear && front != rear)
        {
            break;
        }
        if (i == MAX_SIZE - 1)
        {
            i = 0;
        }
        else
        {
            i++;
        }
    } while (i != rear);
    printf("%d\n", dequeue[rear]);
}

int main()
{
    int choice, item;
    system("clear");
    while (1 == 1)
    {
        printf("\nDequeue Menu:\n");
        printf("1. Enqueue Front\n");
        printf("2. Enqueue Rear\n");
        printf("3. Dequeue Front\n");
        printf("4. Dequeue Rear\n");
        printf("5. Get Front\n");
        printf("6. Get Rear\n");
        printf("7. Display Dequeue\n\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter element to enqueue at the front: ");
            scanf("%d", &item);
            enqueueFront(item);
            break;
        case 2:
            printf("Enter element to enqueue at the rear: ");
            scanf("%d", &item);
            enqueueRear(item);
            break;
        case 3:
            item = dequeueFront();
            if (item != -1)
            {
                system("clear");
                printf("Dequeued element from the front: %d\n", item);
            }
            break;
        case 4:
            item = dequeueRear();
            if (item != -1)
            {
                system("clear");
                printf("Dequeued element from the rear: %d\n", item);
            }
            break;
        case 5:
            item = getFront();
            if (item != -1)
            {
                system("clear");
                printf("Front element: %d\n", item);
            }
            break;
        case 6:
            item = getRear();
            if (item != -1)
            {
                system("clear");
                printf("Rear element: %d\n", item);
            }
            break;
        case 7:
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
