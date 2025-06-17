#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int val;
    struct node* next;
}node;
void enqueue(node** front, node** rear, int data);
int dequeue(node** front, node** rear, int* status);
void peek(node* front);
void display(node* front);
int main(){
    int ch, data, dequeued_element = 0;
    node *front = NULL, *rear = NULL;
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
                peek(front);
                break;
            case 4:
                display(front);
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice.");
        }
        printf("\n");
    }
}
void enqueue(node** front, node** rear, int data){
    node* K = malloc(sizeof(node));
    if(K == NULL){
        printf("Overflow!\n");
        return;
    }
    K->val = data;
    K->next = NULL;
    if(*rear == NULL){
        *front = K;
        *rear = K;
        return;
    }
    (*rear)->next = K;
    *rear = K;
}
int dequeue(node** front, node** rear, int* status){
    int data = 0;
    if(*front == NULL){
        printf("Underflow!\n");
        *status = 0;
        return data;
    }
    node* ptr = *front;
    *front = (*front)->next; 
    data = ptr->val;
    free(ptr);
    if(*front == NULL){
        *rear = NULL;
    }
    *status = 1;
    return data;
}
void peek(node* front){
    if(front == NULL){
        printf("--Empty--\n");
        return;
    }
    printf("Peeked element: %d\n", front->val);
}
void display(node* front){
    if(front == NULL){
        printf("--Empty--\n");
        return;
    }
    printf("Queue: ");
    while(front->next != NULL){
        printf("%d, ", front->val);
        front = front->next;
    }
    printf("%d\n", front->val);
}