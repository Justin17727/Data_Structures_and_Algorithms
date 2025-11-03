#include <stdio.h>

#define MAX 5  // max size of array (queue)

int arr[5];  // array for queue

void enqueue(int* front, int* rear, int item);
int dequeue(int* front, int* rear, int* status);
void peek(int front, int rear);
void display(int front, int rear);

int main(){
    
    int ch;                     // choice of user
    int data;                   // data to enqueue or given by dequeue
    int dequeued_element = 0;   // status flag signifying successful dequeue operation
    int front = -1, rear = -1;  // front and rear pointers of queue
    
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

// enqueue data to queue
void enqueue(int* front, int* rear, int item){

    // if next value pointed by rear is occupied
    if((*rear + 1) % MAX == *front){
        printf("Overflow!\n");
        return;
    }

    // if queue is empty
    if(*front == -1){
        *front = 0;  // set front pointer to 0
    }

    // increment rear value to point to next index
    *rear = ((*rear) + 1) % MAX;

    // place value in array in that index
    arr[*rear] = item;
}

// dequeue data from queue
int dequeue(int* front, int* rear, int* status){
    
    int item = 0;  // data removed

    // if queue is empty
    if(*front == -1){
        printf("Underflow!\n");
        *status = 0;  // signal unsuccessful dequeue
        return item;  // non-significant value returned
    }

    item = arr[*front];  // value being removed

    // if only one element in queue then set both pointers to -1
    if(*front == *rear){
        *front = -1;
        *rear = -1;
    }

    // if not then update front pointer
    else{
        *front = ((*front) + 1) % MAX;
    }

    *status = 1;  // signal successful dequeue
    return item;
}

// peek next value to be dequeued
void peek(int front, int rear){

    // if queue is empty
    if(front == -1){
        printf("--Empty--\n");
        return;
    }

    // display element at the front (pointed by front pointer)
    printf("Peeked element: %d\n", arr[front]);
}

// display queue elements
void display(int front, int rear){
    
    // if queue is empty
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