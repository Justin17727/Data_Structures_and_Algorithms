#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int arr[100];
void insert_element(int data, int pos, int size);
void delete_element(int pos, int size);
void display(int size);
int main(){
    int choice, size=0, val, index;
    while(1){
        printf("Enter 1 to insert an element at any position in array.\n");
        printf("Enter 2 to delete an element from a position in array.\n");
        printf("Enter 3 to display the array.\n");
        printf("Enter 4 to exit.\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                if(size == 100){
                    printf("No space left!");
                }
                else{
                    printf("Enter the element to be inserted: ");
                    scanf("%d", &val);
                    printf("Enter the position at which the element should be inserted: ");
                    scanf("%d", &index);
                    if(index>size || index<0){
                        printf("Enter proper position!");
                    }
                    else{
                        insert_element(val, index, size);
                        size++;
                    }
                }
                printf("\n\n");
                break;
            case 2:
                if(size == 0){
                    printf("No data left to be deleted!");
                }
                else{
                    printf("Enter the element's position to be deleted: ");
                    scanf("%d", &index);
                    if(index >= size || index<0){
                        printf("Enter proper position!");
                    }
                    else{
                        delete_element(index, size);
                        size--;
                    }
                }
                printf("\n\n");
                break;
            case 3:
                display(size);
                printf("\n\n");
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice.\n\n");
        }
    }
}
void insert_element(int data, int pos, int size){
    for(int i=size; i>pos; i--){
        arr[i]=arr[i-1];
    }
    arr[pos]=data;
}
void delete_element(int pos, int size){
    for(int i=pos; i<size-1; i++){
        arr[i]=arr[i+1];
    }
}
void display(int size){
    for(int i=0; i<size; i++){
        printf("%d\t", arr[i]);
    }
}