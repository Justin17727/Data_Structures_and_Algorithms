#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int val;
    struct node* next;
}node;
void push(node** top, int data);
int pop(node** top, int* status);
void peek(node* top);
void display(node* front);
int main(){
    int ch, data, popped_element = 0;
    node* top = NULL;
    while(1){
        printf("Enter 1 to push\n");
        printf("Enter 2 to pop\n");
        printf("Enter 3 to peek\n");
        printf("Enter 4 to display\n");
        printf("Enter 5 to exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch(ch){
            case 1:
                printf("Enter data to be pushed: ");
                scanf("%d", &data);
                push(&top, data);
                break;
            case 2:
                data = pop(&top, &popped_element);
                if(popped_element){
                    printf("Removed %d from stack\n", data);
                }
                break;
            case 3:
                peek(top);
                break;
            case 4:
                display(top);
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice.");
        }
        printf("\n");
    }
}
void push(node** top, int data){
    node* K = malloc(sizeof(node));
    if(K == NULL){
        printf("Overflow!\n");
        return;
    }
    K->val = data;
    K->next = *top;
    *top = K;
}
int pop(node** top, int* status){
    int data = 0;
    if(*top == NULL){
        printf("Underflow!\n");
        *status = 0;
        return data;
    }
    node* ptr = *top;
    *top = (*top)->next;
    data = ptr->val;
    *status = 1;
    free(ptr);
    return data;
}
void peek(node* top){
    if(top == NULL){
        printf("--Empty--\n");
        return;
    }
    printf("Peeked element: %d\n", top->val);
}
void display(node* top){
    if(top == NULL){
        printf("--Empty--\n");
        return;
    }
    printf("Stack: ");
    while(top->next != NULL){
        printf("%d, ", top->val);
        top = top->next;
    }
    printf("%d\n", top->val);
}