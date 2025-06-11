#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int val;
    struct node* next;
}node;
node* insertFirst(node* head, int data, int* size);
node* insertBetween(node* head, int data, int index, int* size);
node* insertLast(node* head, int data, int* size);
node* deleteFirst(node* head, int* size);
node* deleteBetween(node* head, int index, int* size);
node* deleteLast(node* head, int* size);
void display(node* head);
int main(){
    int ch, data, index, size = 0;
    node* head = NULL;
    while(1){
        printf("Enter 1 to insert at first\n");
        printf("Enter 2 to insert in between\n");
        printf("Enter 3 to insert at last\n");
        printf("Enter 4 to delete at first\n");
        printf("Enter 5 to delete in between\n");
        printf("Enter 6 to delete at last\n");
        printf("Enter 7 to display\n");
        printf("Enter 8 to exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch(ch){
            case 1:
                printf("Enter data to be inserted: ");
                scanf("%d", &data);
                head = insertFirst(head, data, &size);
                break;
            case 2:
                printf("Enter data to be inserted: ");
                scanf("%d", &data);
                printf("Enter the index to be inserted at: ");
                scanf("%d", &index);
                if(index > size || index < 0){
                    printf("Enter proper index!");
                }
                else{
                    head = insertBetween(head, data, index, &size);
                }
                break;
            case 3:
                printf("Enter data to be inserted: ");
                scanf("%d", &data);
                head = insertLast(head, data, &size);
                break;
            case 4:
                if(size == 0){
                    printf("No data left to be deleted!");
                }
                else{
                    head = deleteFirst(head, &size);
                }
                break;
            case 5:
                if(size == 0){
                    printf("No data left to be deleted!");
                }
                else{
                    printf("Enter the index to be deleted at: ");
                    scanf("%d", &index);
                    if(index >= size || index < 0){
                        printf("Enter proper index!");
                    }
                    else{
                        head = deleteBetween(head, index, &size);
                    }
                }
                break;
            case 6:
                if(size == 0){
                    printf("No data left to be deleted!");
                }
                else{
                    head = deleteLast(head, &size);
                }
                break;
            case 7:
                display(head);
                break;
            case 8:
                return 0;
            default:
                printf("Invalid choice.");
        }
        printf("\n");
    }
}
node* insertFirst(node* head, int data, int* size){
    node* K = malloc(sizeof(node));
    if(K == NULL){
        printf("Could not allocate memory for new node!");
        return head;
    }
    K->val = data;
    K->next = head;
    (*size) += 1;
    return K;
}
node* insertBetween(node* head, int data, int index, int* size){
    if(index == 0){
        return insertFirst(head, data, size);
    }
    if(index == *size){
        return insertLast(head, data, size);
    }
    node* K = malloc(sizeof(node));
    if(K == NULL){
        printf("Could not allocate memory for new node!");
        return head;
    }
    K->val = data;
    node* ptr = head;
    for(int i = 0; i < index - 1; i++){
        ptr = ptr->next;
    }
    K->next = ptr->next;
    ptr->next = K;
    (*size) += 1;
    return head;
}
node* insertLast(node* head, int data, int* size){
    if(head == NULL){
        return insertFirst(head, data, size);
    }
    node* K = malloc(sizeof(node));
    if(K == NULL){
        printf("Could not allocate memory for new node!");
        return head;
    }
    node* ptr = head;
    while(ptr->next != NULL){
        ptr = ptr->next;
    }
    K->val = data;
    K->next = NULL;
    ptr->next = K;
    (*size) += 1;
    return head;
}
node* deleteFirst(node* head, int* size){
    node* ptr = head->next;
    free(head);
    (*size) -= 1;
    return ptr;
}
node* deleteBetween(node* head, int index, int* size){
    if(index == 0){
        return deleteFirst(head, size);
    }
    if(index == (*size) - 1){
        return deleteLast(head, size);
    }
    node *ptr = head, *ptr2 = NULL;
    for(int i = 0; i < index; i++){
        ptr2 = ptr;
        ptr = ptr->next;
    }
    ptr2->next = ptr->next;
    free(ptr);
    (*size) -= 1;
    return head;
}
node* deleteLast(node* head, int* size){
    node* ptr = head;
    if(ptr->next == NULL){
        free(ptr);
        (*size) -= 1;
        return NULL;
    }
    while(ptr->next->next != NULL){
        ptr = ptr->next;
    }
    free(ptr->next);
    ptr->next = NULL;
    (*size) -= 1;
    return head;
}
void display(node* head){
    if(head == NULL){
        printf("--Empty--\n");
    }
    node* ptr = head;
    while(ptr->next != NULL){
        printf("%d -> ", ptr->val);
        ptr = ptr->next;
    }
    printf("%d\n", ptr->val);
}