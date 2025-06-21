#include <stdio.h>
#define MAX 5
int arr[5];
void enqueue(int* front, int* rear, int item);
int dequeue(int* top, int* rear, int* status);
void peek(int front, int rear);
void display(int top, int rear);
int main(){
    int ch, data, dequeued_element = 0, front = -1, rear = -1;
    while(1){
        printf("Enter 1 to enqueue\n");
        printf("Enter 2 to dequeue\n");
        printf("Enter 3 to peek\n");
        printf("Enter 4 to display\n");
        printf("Enter 5 to exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch(ch){
            case 1:
                printf("Enter data to be enqueued: ");
                scanf("%d", &data);
                enqueue(&front, &rear, data);
                break;
            case 2:
                data = dequeue(&front, &rear, &dequeued_element);
                if(dequeued_element){
                    printf("Removed %d from queue\n", data);
                }
                break;
            case 3:
                peek(front, rear);
                break;
            case 4:
                display(front, rear);
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice.");
        }
        printf("\n");
    }
}
void enqueue(int* front, int* rear, int item){
    if((*rear + 1) % MAX == *front){
        printf("Overflow!\n");
        return;
    }
    if(*front == -1){
        *front = 0;
    }
    *rear = ((*rear) + 1) % MAX;
    arr[*rear] = item;
}
int dequeue(int* front, int* rear, int* status){
    int item = 0;
    if(*front == -1){
        printf("Underflow!\n");
        *status = 0;
        return item;
    }
    item = arr[*front];
    if(*front == *rear){
        *front = -1;
        *rear = -1;
    }
    else{
        *front = ((*front) + 1) % MAX;
    }
    *status = 1;
    return item;
}
void peek(int front, int rear){
    if(front == -1){
        printf("--Empty--\n");
        return;
    }
    printf("Peeked element: %d\n", arr[front]);
}
void display(int front, int rear){
    if(front == -1){
        printf("--Empty--\n");
        return;
    }
    printf("Queue: ");
    for(int i = front; i != rear; i = (i + 1) % MAX){
        printf("%d, ", arr[i]);
    }
    printf("%d\n", arr[rear]);
}