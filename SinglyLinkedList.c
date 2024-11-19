#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int val;
    struct node* next;
}node;
int main(){
    int ch, data, index, size=0;
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
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            case 8:
                break;
            default:
                printf("Invalid choice.");
        }
    }
}