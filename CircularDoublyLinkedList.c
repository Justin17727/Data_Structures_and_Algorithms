#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    struct node* prev;
    int val;
    struct node* next;
}node;
node* insertFirst(node* head, int data, int* size);
node* insertBetween(node* head, int data, int index, int* size);
node* insertLast(node* head, int data, int* size);
node* deleteFirst(node* head, int* size);
node* deleteBetween(node* head, int index, int* size);
node* deleteLast(node* head, int* size);
void display_front_loop(node* head, int count);
void display_back_loop(node* head, int count);
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
        printf("Enter 7 to display list loop from beginning\n");
        printf("Enter 8 to display list loop from end\n");
        printf("Enter 9 to exit\n");
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
                printf("Enter the number of times to loop around the list: ");
                scanf("%d", &data);
                if(data <= 0){
                    printf("Enter proper number of loops!");
                }
                else{
                    display_front_loop(head, data);
                }
                break;
            case 8:
                printf("Enter the number of times to loop around the list: ");
                scanf("%d", &data);
                if(data <= 0){
                    printf("Enter proper number of loops!");
                }
                else{
                    display_back_loop(head, data);
                }
                break;
            case 9:
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
    (*size) += 1;
    if(head == NULL){
        K->prev = K;
        K->next = K;
        return K;
    }
    K->next = head;
    K->prev = head->prev;
    if(head->next == head){
        head->next = K;
    }
    else{
        head->prev->next = K;
    }
    head->prev = K;
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
    (*size) += 1;
    K->val = data;
    node* ptr = head;
    for(int i = 0; i < index; i++){
        ptr = ptr->next;
    }
    K->next = ptr;
    K->prev = ptr->prev;
    ptr->prev->next = K;
    ptr->prev = K;
    return head;
}
node* insertLast(node* head, int data, int* size){
    if(head == NULL || head->next == head){
        return insertFirst(head, data, size);
    }
    node* K = malloc(sizeof(node));
    if(K == NULL){
        printf("Could not allocate memory for new node!");
        return head;
    }
    (*size) += 1;
    K->val = data;
    K->next = head;
    K->prev = head->prev;
    head->prev->next = K;
    head->prev = K;
    return head;
}
node* deleteFirst(node* head, int* size){
    (*size) -= 1;
    if(head->next == head){
        free(head);
        return NULL;
    }
    head->prev->next = head->next;
    head->next->prev = head->prev;
    node* ptr = head->next;
    free(head);
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
        ptr = ptr->next;
    }
    ptr->prev->next = ptr->next;
    ptr->next->prev = ptr->prev;
    free(ptr);
    (*size) -= 1;
    return head;
}
node* deleteLast(node* head, int* size){
    (*size) -= 1;
    if(head->next == head){
        free(head);
        return NULL;
    }
    node* ptr = head->prev;
    ptr->prev->next = head;
    head->prev = ptr->prev;
    free(ptr);
    return head;
}
void display_front_loop(node* head, int count){
    if(head == NULL){
        printf("--Empty--\n");
        return;
    }
    node* ptr = head;
    int loops = 0, node = 1;
    while(loops != count){
        printf("Node %d: %d (value)| %p (next)\n", node, ptr->val,ptr->next);
        ptr = ptr->next;
        node++;
        if(ptr == head){
            loops++;
            node = 1;
        }
    }
}
void display_back_loop(node* head, int count){
    if(head == NULL){
        printf("--Empty--\n");
        return;
    }
    node* ptr = head->prev;
    int loops = 0, node = 1;
    while(loops != count){
        printf("Node %d: %d (value)| %p (previous)\n", node, ptr->val,ptr->prev);
        ptr = ptr->prev;
        node++;
        if(ptr == head->prev){
            loops++;
            node = 1;
        }
    }
}