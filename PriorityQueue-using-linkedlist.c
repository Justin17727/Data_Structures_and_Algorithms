#include <stdio.h>
#include <stdlib.h>
typedef struct priority_queue{
    int val;
    int priority;
    struct priority_queue* next;
}priority_queue;
void enqueue(priority_queue** head, int data, int priority);
int dequeue(priority_queue** head, int* status);
int peek(priority_queue* head, int* status);
void display(priority_queue* head);
int main(){
    int ch, data, prior, success = 0;
    priority_queue* pq = NULL;
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
                enqueue(&pq, data, prior);
                break;
            case 2:
                data = dequeue(&pq, &success);
                if(success){
                    printf("Removed %d from queue\n", data);
                }
                break;
            case 3:
                data = peek(pq, &success);
                if(success){
                    printf("Peeked element: %d\n", data);
                }
                break;
            case 4:
                display(pq);
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice.\n");
        }
        printf("\n");
    }
}
void enqueue(priority_queue** head, int data, int priority){
    priority_queue* K = malloc(sizeof(priority_queue));
    if(K == NULL){
        printf("Overflow!\n");
        return;
    }
    K->val = data;
    K->priority = priority;
    if(*head == NULL){
        *head = K;
        return;
    }
    if((*head)->priority < priority){
        K->next = *head;
        *head = K;
        return;
    }
    priority_queue *ptr = *head, *ptr2 = NULL;
    while(ptr != NULL && ptr->priority >= priority){
        ptr2 = ptr;
        ptr = ptr->next;
    }
    K->next = ptr;
    ptr2->next = K;
}
int dequeue(priority_queue** head, int* status){
    int value = 0;
    if(*head == NULL){
        printf("Underflow!\n");
        *status = 0;
        return value;
    }
    *status = 1;
    value = (*head)->val;
    priority_queue* temp = (*head)->next;
    free(*head);
    *head = temp;
    return value;
}
int peek(priority_queue* head, int* status){
    if(head == NULL){
        *status = 0;
        printf("--Empty--\n");
        return 0;
    }
    *status = 1;
    return head->val;
}
void display(priority_queue* head){
    if(head == NULL){
        printf("--Empty--\n");
        return;
    }
    printf("Data:Priority\n");
    while(head->next != NULL){
        printf("%d:%d, ", head->val, head->priority);
        head = head->next;
    }
    printf("%d:%d\n", head->val, head->priority);
}