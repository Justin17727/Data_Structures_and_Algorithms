#include <stdio.h>
#define MAX 100
int arr[100];
void push(int* top, int item);
int pop(int* top, int item, int* status);
void peek(int top);
void display(int top);
int main(){
    int ch, data, popped_element = 0, top = -1;
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
                data = pop(&top, data, &popped_element);
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
void push(int* top, int item){
    if(*top == MAX - 1){
        printf("Overflow!\n");
        return;
    }
    arr[++(*top)] = item;
}
int pop(int* top, int item, int* status){
    if(*top == -1){
        printf("Underflow!\n");
        *status = 0;
        return item;
    }
    item = arr[(*top)--];
    *status = 1;
    return item;
}
void peek(int top){
    if(top == -1){
        printf("--Empty--\n");
        return;
    }
    printf("Peeked element: %d\n", arr[top]);
}
void display(int top){
    if(top == -1){
        printf("--Empty--\n");
        return;
    }
    printf("Stack: ");
    for(int i = top; i > 0; i--){
        printf("%d, ", arr[i]);
    }
    printf("%d\n", arr[0]);
}