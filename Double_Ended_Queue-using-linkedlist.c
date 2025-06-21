#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int val;
    struct node* next;
}node;
void insertFront(node** front, node** rear, int data);
void insertRear(node** front, node** rear, int data);
int deleteFront(node** front, node** rear, int* status);
int deleteRear(node** front, node** rear, int* status);
void display(node* front);
int main(){
    int ch, data, dequeued_element = 0;
    node *front = NULL, *rear = NULL;
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
                display(front);
                break;
            case 6:
                return 0;
            default:
                printf("Invalid choice.");
        }
        printf("\n");
    }
}
void insertFront(node** front, node** rear, int data){
    node* K = malloc(sizeof(node));
    if(K == NULL){
        printf("Overflow!\n");
        return;
    }
    K->val = data;
    K->next = *front;
    if(*rear == NULL){
        *rear = K;
    }
    *front = K;
}
void insertRear(node** front, node** rear, int data){
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
int deleteFront(node** front, node** rear, int* status){
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
int deleteRear(node** front, node** rear, int* status){
    int data = 0;
    if(*front == NULL){
        printf("Underflow!\n");
        *status = 0;
        return data;
    }
    data = (*rear)->val;
    *status = 1;
    if(*front == *rear){
        free(*rear);
        *front = NULL;
        *rear = NULL;
        return data;
    }
    node* ptr = *front;
    while(ptr->next != *rear){
        ptr = ptr->next;
    }
    ptr->next = NULL;
    free(*rear);
    *rear = ptr;
    return data;
}
void display(node* front){
    if(front == NULL){
        printf("--Empty--\n");
        return;
    }
    printf("Deque: ");
    while(front->next != NULL){
        printf("%d, ", front->val);
        front = front->next;
    }
    printf("%d\n", front->val);
}