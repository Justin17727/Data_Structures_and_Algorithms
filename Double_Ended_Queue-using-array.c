#include <stdio.h>
#define MAX 5
int arr[5];
void insertFront(int* front, int* rear, int item);
void insertRear(int* front, int* rear, int item);
int deleteFront(int* front, int* rear, int* status);
int deleteRear(int* front, int* rear, int* status);
void display(int front, int rear);
int main(){
    int ch, data, dequeued_element = 0;
    int front = -1, rear = -1;
    while(1){
        printf("Enter 1 to insert at front\n");
        printf("Enter 2 to insert at rear\n");
        printf("Enter 3 to delete at front\n");
        printf("Enter 4 to delete at rear\n");
        printf("Enter 5 to display\n");
        printf("Enter 6 to exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch(ch){
            case 1:
                printf("Enter data to be inserted: ");
                scanf("%d", &data);
                insertFront(&front, &rear, data);
                break;
            case 2:
                printf("Enter data to be inserted: ");
                scanf("%d", &data);
                insertRear(&front, &rear, data);
                break;
            case 3:
                data = deleteFront(&front, &rear, &dequeued_element);
                if(dequeued_element){
                    printf("Removed %d from deque\n", data);
                }
                break;
            case 4:
                data = deleteRear(&front, &rear, &dequeued_element);
                if(dequeued_element){
                    printf("Removed %d from deque\n", data);
                }
                break;
            case 5:
                display(front, rear);
                break;
            case 6:
                return 0;
            default:
                printf("Invalid choice.");
        }
        printf("\n");
    }
}
void insertFront(int* front, int* rear, int item){
    if((*front + MAX - 1) % MAX == *rear){
        printf("Overflow!\n");
        return;
    }
    if(*front == -1){
        *front = 0;
        *rear = 0;
        arr[*front] = item;
        return;
    }
    *front = ((*front) + MAX - 1) % MAX;
    arr[*front] = item;
}
void insertRear(int* front, int* rear, int item){
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
int deleteFront(int* front, int* rear, int* status){
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
int deleteRear(int* front, int* rear, int* status){
    int item = 0;
    if(*rear == -1){
        printf("Underflow!\n");
        *status = 0;
        return item;
    }
    item = arr[*rear];
    if(*rear == *front){
        *front = -1;
        *rear = -1;
    }
    else{
        *rear = ((*rear) + MAX - 1) % MAX;
    }
    *status = 1;
    return item;
}
void display(int front, int rear){
    if(front == -1){
        printf("--Empty--\n");
        return;
    }
    if(front == rear){
        printf("Deque: %d\n", arr[rear]);
        return;
    }
    printf("Deque: ");
    for(int i = front; i != rear; i = (i + 1) % MAX){
        printf("%d, ", arr[i]);
    }
    printf("%d\n", arr[rear]);
}