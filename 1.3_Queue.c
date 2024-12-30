#include<stdio.h>
#include<stdlib.h>

int q[50], size;
int rear = -1;
int front = -1;
int item, i;

void enqueue();
void dequeue();
void display();

int main() {
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    printf("Enter the array elements: ");
    for(i = 0; i < size; i++) {
        scanf("%d", &q[i]);
        printf("%d ", q[i]);
    }
    printf("\n");

    while(1) {
        int ch;
        printf("\nEnter your choice:\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        scanf("%d", &ch);

        switch(ch) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    }

    return 0;
}

void enqueue() {
    printf("Enter the element to be inserted: ");
    scanf("%d", &item);

    if(rear == size - 1) {
        printf("Overflow\n");
    } else {
        if(front == -1) front = 0;
        rear++;
        q[rear] = item;
        printf("Element inserted: %d\n", item);
    }
}

void dequeue() {
    if(front == -1) {
        printf("Underflow\n");
    } else if(front == rear) {
        printf("The deleted element is %d\n", q[front]);
        front = rear = -1;
    } else {
        printf("The deleted element is %d\n", q[front]);
        front++;
    }
}

void display() {
    if(front == -1) {
        printf("Underflow\n");
    } else {
        printf("Queue elements: ");
        for(i = front; i <= rear; i++) {
            printf("%d ", q[i]);
        }
        printf("\n");
    }
}
