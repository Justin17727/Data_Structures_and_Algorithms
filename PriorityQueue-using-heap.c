#include <stdio.h>
#define MAX 10
typedef struct priority_queue{
    int val;
    int priority;
}priority_queue;
void maxHeapifyUp(priority_queue* arr, int node);
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
void maxHeapifyUp(priority_queue* arr, int node){
    priority_queue temp = arr[node];
    for(int i = node; i > 0; i = (i - 1) / 2){
        if(arr[(i - 1) / 2].priority < arr[i].priority){
            arr[i] = arr[(i - 1) / 2];
            arr[(i - 1) / 2] = temp;
        }
    }
}
void enqueue(priority_queue* arr, int data, int priority, int* size){
    if(*size == MAX){
        printf("Overflow!\n");
        return;
    }
    arr[*size].val = data;
    arr[*size].priority = priority;
    (*size)++;
    maxHeapifyUp(arr, (*size) - 1);
}
int dequeue(priority_queue* arr, int* size, int* status){
    int value = 0;
    if(*size == 0){
        printf("Underflow!\n");
        *status = 0;
        return value;
    }
    *status = 1;
    priority_queue temp = arr[0];
    if(*size == 1){
        *size -= 1;
        return temp.val;
    }
    arr[0] = arr[*size - 1];
    arr[*size - 1] = temp;
    *size -= 1;
    value = temp.val;
    temp = arr[0];
    int i = 0;
    while(i < *size){
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        if(left < *size && arr[left].priority > arr[largest].priority){
            largest = left;
        }
        if(right < *size && arr[right].priority > arr[largest].priority){
            largest = right;
        }
        if(largest != i && arr[largest].priority > arr[i].priority){
            arr[i] = arr[largest];
            arr[largest] = temp;
        }
        else{
            break;
        }
        i = largest;
    }
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