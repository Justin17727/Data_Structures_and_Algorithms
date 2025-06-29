#include <stdio.h>
#include <stdlib.h>
void maxHeapify(int* arr, int node);
int* insert(int* arr, int data, int* elements, int* size);
int extractMax(int* arr, int* size, int* status);
int findMax(int* arr, int size, int* status);
void display(int* arr, int size);
int main(){
    int choice, data, elements = 0, size = 0, status = 0;
    int* heap = NULL;
    while(1){
        printf("Enter 1 to insert an element.\n");
        printf("Enter 2 to extract max element.\n");
        printf("Enter 3 to peek max element.\n");
        printf("Enter 4 to display the heap.\n");
        printf("Enter 5 to exit.\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter element to be inserted: ");
                scanf("%d", &data);
                heap = insert(heap, data, &elements, &size);
                break;
            case 2:
                data = extractMax(heap, &elements, &status);
                if(status){
                    printf("Removed element: %d\n", data);
                }
                break;
            case 3:
                data = findMax(heap, elements, &status);
                if(status){
                    printf("Max element: %d\n", data);
                }
                break;
            case 4:
                display(heap, elements);
                break;
            case 5:
                free(heap);
                return 0;
            default:
                printf("Invalid choice.\n");
        }
        printf("\n");
    }
}
void maxHeapify(int* arr, int node){
    int temp = arr[node];
    for(int i = node; i > 0; i = (i - 1) / 2){
        if(arr[(i - 1) / 2] < arr[i]){
            arr[i] = arr[(i - 1) / 2];
            arr[(i - 1) / 2] = temp;
        }
    }
}
int* insert(int* arr, int data, int* elements, int* size){
    int* temp;
    if(*elements == *size){
        if(*size == 0){
            *size = 1;
            arr = malloc(sizeof(int));
            if(arr == NULL){
                printf("Could not allocate more space for new node!");
                return arr;
            }
            (*elements)++;
            arr[0] = data;
            return arr;
        }
        (*size) *= 2;
        temp = realloc(arr, (*size) * sizeof(int));
        if(temp == NULL){
            printf("Could not allocate more space for new node!");
            return arr;
        }
        arr = temp;
    }
    arr[*elements] = data;
    (*elements)++;
    maxHeapify(arr, (*elements) - 1);
    return arr;
}
int extractMax(int* arr, int* size, int* status){
    int value = 0;
    if(*size == 0){
        printf("--Empty--\n");
        *status = 0;
        return value;
    }
    *status = 1;
    value = arr[0];
    if(*size == 1){
        *size -= 1;
        return value;
    }
    arr[0] = arr[*size - 1];
    arr[*size - 1] = value;
    *size -= 1;
    int temp = arr[0], i = 0;;
    while(i < *size){
        int b = 2 * i + 1;
        if(b >= *size){
            break;
        }
        else if(b + 1 >= *size){
            if(arr[i] < arr[b]){
                arr[i] = arr[b];
                arr[b] = temp;
            }
            break;
        }
        else{
            b = (arr[b] > arr[b + 1]) ? b : b + 1;
            if(arr[i] < arr[b]){
                arr[i] = arr[b];
                arr[b] = temp;
                i = b;
            }
            else{
                break;
            }
        }
    }
    return value;
}
int findMax(int* arr, int size, int* status){
    if(size == 0){
        *status = 0;
        printf("--Empty--\n");
        return 0;
    }
    *status = 1;
    return arr[0];
}
void display(int* arr, int size){
    if(size == 0){
        printf("--Empty--\n");
        return;
    }
    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}