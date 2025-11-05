#include <stdio.h>
#include <stdlib.h>

// structure of a node in doubly linked list
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
void display_loop(node* head, int count);

int main(){
    int ch;             // choice of user
    int data;           // data to be inserted/ number of loops to make for display
    int index;          // index of node to be removed
    int size = 0;       // size of linked list
    node* head = NULL;  // head pointer pointing to first node of linked list

    while(1){
        printf("Enter 1 to insert at first\n");
        printf("Enter 2 to insert in between\n");
        printf("Enter 3 to insert at last\n");
        printf("Enter 4 to delete at first\n");
        printf("Enter 5 to delete in between\n");
        printf("Enter 6 to delete at last\n");
        printf("Enter 7 to display list loop\n");
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
                
                // if entered index out of bounds
                if(index > size || index < 0){
                    printf("Enter proper index!");
                }

                // if valid index
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
                
                // if linked list is empty
                if(size == 0){
                    printf("No data left to be deleted!");
                }

                // if not empty
                else{
                    head = deleteFirst(head, &size);
                }
                break;

            case 5:
                
                // if linked list is empty
                if(size == 0){
                    printf("No data left to be deleted!");
                }

                // if not empty
                else{
                    printf("Enter the index to be deleted at: ");
                    scanf("%d", &index);

                    // if entered index out of bounds
                    if(index >= size || index < 0){
                        printf("Enter proper index!");
                    }

                    // if valid index
                    else{
                        head = deleteBetween(head, index, &size);
                    }
                }
                break;

            case 6:

                // if linked list is empty
                if(size == 0){
                    printf("No data left to be deleted!");
                }

                // if not empty
                else{
                    head = deleteLast(head, &size);
                }
                break;

            case 7:
                printf("Enter the number of times to loop around the list: ");
                scanf("%d", &data);

                // if number of loops is not positive
                if(data <= 0){
                    printf("Enter proper number of loops!");
                }

                // if valid number of loops
                else{
                    display_loop(head, data);
                }
                break;

            case 8:
                return 0;

            default:
                printf("Invalid choice.");
        }
        printf("\n");
    }
}

// insert new node at the beginning of linked list
node* insertFirst(node* head, int data, int* size){

    // allocate new node
    node* K = malloc(sizeof(node));

    // if memory allocation for new node failed
    if(K == NULL){
        printf("Could not allocate memory for new node!");
        return head;
    }

    K->val = data;

    // if linked list is empty
    if(head == NULL){
        K->next = K;  // new node's next node is itself
    }

    // if not empty
    else{
        K->next = head;  // new node's next node is head node

        node* ptr = head->next;

        // traverse until last node
        while(ptr->next != head){
            ptr = ptr->next;
        }
        ptr->next = K;  // last node's next node is new node
    }

    (*size) += 1;
    
    return K;
}

// insert new node at any position (index) of linked list
node* insertBetween(node* head, int data, int index, int* size){
    
    // if first position
    if(index == 0){
        return insertFirst(head, data, size);
    }

    // if last position
    if(index == *size){
        return insertLast(head, data, size);
    }

    // allocate new node
    node* K = malloc(sizeof(node));

    // if memory allocation for new node failed
    if(K == NULL){
        printf("Could not allocate memory for new node!");
        return head;
    }

    K->val = data;
    
    node* ptr = head;
    
    // traverse to the desired position
    for(int i = 0; i < index - 1; i++){
        ptr = ptr->next;
    }

    // link adjustments for new node
    K->next = ptr->next;
    ptr->next = K;

    (*size) += 1;
    
    return head;
}

// insert new node at last position of linked list
node* insertLast(node* head, int data, int* size){
    
    // if linked list is empty
    if(head == NULL){
        return insertFirst(head, data, size);
    }

    // allocate new node
    node* K = malloc(sizeof(node));

    // if memory allocation for new node failed
    if(K == NULL){
        printf("Could not allocate memory for new node!");
        return head;
    }

    node* ptr = head;

    // traverse to last position
    while(ptr->next != head){
        ptr = ptr->next;
    }
    
    K->val = data;
    
    // link adjustments for new node
    K->next = head;
    ptr->next = K;
    
    (*size) += 1;
    
    return head;
}

// delete node at first position of linked list
node* deleteFirst(node* head, int* size){
    (*size) -= 1;

    // if single element in linked list
    if(head->next == head){
        free(head);
        return NULL;
    }

    node* ptr = head->next;  // second node
    node* ptr2 = ptr;        // pointer for last node

    // traverse to last node
    while(ptr2->next != head){
        ptr2 = ptr2->next;
    }

    // link from last node to second node
    ptr2->next = ptr;

    free(head);

    return ptr;
}

// delete node at any position (index) of linked list
node* deleteBetween(node* head, int index, int* size){

    // if first position
    if(index == 0){
        return deleteFirst(head, size);
    }

    // if last position
    if(index == (*size) - 1){
        return deleteLast(head, size);
    }

    node* ptr = head;   // pointer for node at desired position
    node* ptr2 = NULL;  // pointer for previous node of node at desired position (ptr)

    // traverse to the desired position
    for(int i = 0; i < index; i++){
        ptr2 = ptr;
        ptr = ptr->next;
    }

    // previous node's next node should be the next node of node at desired position (ptr)
    ptr2->next = ptr->next;
    
    free(ptr);
    (*size) -= 1;
    
    return head;
}

// delete node at last position of linked list
node* deleteLast(node* head, int* size){
    (*size) -= 1;

    // if single element in linked list
    if(head->next == head){
        free(head);
        return NULL;
    }
    
    node* ptr = head;
    
    // traverse to second last position
    while(ptr->next->next != head){
        ptr = ptr->next;
    }

    free(ptr->next);
    
    // second last node's next node should be first node
    ptr->next = head;
    
    return head;
}

// display node memory locations with values while traversing
void display_loop(node* head, int count){
    
    // if linked list is empty
    if(head == NULL){
        printf("--Empty--\n");
        return;
    }

    node* ptr = head;        // dummy pointer to traverse linked list
    int loops = 0;           // number of loops made
    int node = 1;            // node number in loop

    while(loops != count){
        printf("Node %d: %d (value)| %p (next)\n", node, ptr->val,ptr->next);
        ptr = ptr->next;
        node++;

        // if dummy pointer reaches head node then a loop finishes
        if(ptr == head){
            loops++;
            node = 1;
        }
    }
}