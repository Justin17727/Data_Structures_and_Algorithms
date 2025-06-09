#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int* create_array(int n);
int* insert_element(int* a, int n, int k, int b);
int* delete_element(int* a, int n, int k);
void display(int* a, int n);
int main(){
    int choice, size, b, c, d;
    int *p = NULL, *k = NULL;
    while(1){
        printf("Enter 1 to create an array.\n");
        printf("Enter 2 to insert an element at any position in array.\n");
        printf("Enter 3 to delete an element from a position in array.\n");
        printf("Enter 4 to display the array.\n");
        printf("Enter 5 to exit.\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                free(p);
                printf("Enter size of array: ");
                scanf("%d", &size);
                p = create_array(size);
                if(p == NULL){
                    printf("Not able to create array.");
                }
                printf("\n");
                break;
            case 2:
                if(p == NULL){
                    printf("Create an array first!");
                }
                else{
                    printf("Enter the element to be inserted: ");
                    scanf("%d", &c);
                    printf("Enter the position at which the element should be inserted: ");
                    scanf("%d", &d);
                    if(d > size || d < 0){
                        printf("Enter proper position!");
                    }
                    else{
                        k = insert_element(p, size, d, c);
                        if(k == NULL){
                            printf("Not able to insert element!");
                        }
                        else{
                            free(p);
                            p = k;
                            size += 1;
                        }
                    }
                }
                printf("\n\n");
                break;
            case 3:
                if(p == NULL){
                    printf("Create an array first!");
                }
                else{
                    printf("Enter the element's position to be deleted: ");
                    scanf("%d", &d);
                    if(d >= size || d < 0){
                        printf("Enter proper position!");
                    }
                    else{
                        k = delete_element(p, size, d);
                        if(k == NULL){
                            printf("Not able to delete element!");
                        }
                        else{
                            free(p);
                            p = k;
                            size -= 1;
                        }
                    }
                }
                printf("\n\n");
                break;
            case 4:
                if(p == NULL){
                    printf("Create an array first!");
                }
                else{
                    display(p, size);
                }
                printf("\n\n");
                break;
            case 5:
                free(p);
                return 0;
            default:
                printf("Invalid choice.\n\n");
        }
    }
}
int* create_array(int n){
    int* p = calloc(n, sizeof(int));
    for(int i = 0; i < n; i++){
        printf("Enter element %d: ", i + 1);
        scanf("%d", p + i);
    }
    return p;
}
int* insert_element(int* a, int n, int k, int b){
    int *p = calloc(n + 1, sizeof(int));
    if(p == NULL){
        return NULL;
    }
    else{
        for(int i = 0; i < k; i++){
            p[i] = a[i];
        }
        p[k] = b;
        for(int i = n; i > k; i--){
            p[i] = a[i - 1];
        }
        return p;
    }
}
int* delete_element(int* a, int n, int k){
    int *p = calloc(n - 1, sizeof(int));
    if(p == NULL){
        return NULL;
    }
    else{
        for(int i = 0; i < k; i++){
            p[i] = a[i];
        }
        for(int i = k; i < n - 1; i++){
            p[i] = a[i + 1];
        }
        return p;
    }
}
void display(int* a, int n){
    for(int i = 0; i < n; i++){
        printf("%d\t", a[i]);
    }
}