#include <stdio.h>
#define MAX 10
typedef struct priority_queue{
    int val;
    int priority;
}priority_queue;
void enqueue(priority_queue* arr, int data, int priority, int* size);
int dequeue(priority_queue* arr, int* size, int* status);
int peek(priority_queue* arr, int size, int* status);
void display(priority_queue* arr, int size);
int main(){
    int ch, data, prior, success = 0, size = 0;
    priority_queue pq[MAX];
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
                printf("Enter priority: ");
                scanf("%d", &prior);
                enqueue(pq, data, prior, &size);
                break;
            case 2:
                data = dequeue(pq, &size, &success);
                if(success){
                    printf("Removed %d from queue\n", data);
                }
                break;
            case 3:
                data = peek(pq, size, &success);
                if(success){
                    printf("Peeked element: %d\n", data);
                }
                break;
            case 4:
                display(pq, size);
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice.\n");
        }
        printf("\n");
    }
}
void enqueue(priority_queue* arr, int data, int priority, int* size){
    if(*size == MAX){
        printf("Overflow!\n");
        return;
    }
    int i = 0;
    while(i < *size && arr[i].priority >= priority){
        i++;
    }
    for(int j = *size; j > i; j--){
        arr[j] = arr[j - 1];
    }
    arr[i].val = data;
    arr[i].priority = priority;
    (*size)++;
}
int dequeue(priority_queue* arr, int* size, int* status){
    int value = 0;
    if(*size == 0){
        printf("Underflow!\n");
        *status = 0;
        return value;
    }
    *status = 1;
    value = arr[0].val;
    for(int i = 1; i < *size; i++){
        arr[i - 1] = arr[i];
    }
    (*size)--;
    return value;
}
int peek(priority_queue* arr, int size, int* status){
    if(size == 0){
        *status = 0;
        printf("--Empty--\n");
        return 0;
    }
    *status = 1;
    return arr[0].val;
}
void display(priority_queue* arr, int size){
    if(size == 0){
        printf("--Empty--\n");
        return;
    }
    printf("Data:Priority\n");
    for(int i = 0; i < size - 1; i++){
        printf("%d:%d, ", arr[i].val, arr[i].priority);
    }
    printf("%d:%d\n", arr[size - 1].val, arr[size - 1].priority);
}