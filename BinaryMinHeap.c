#include <stdio.h>
#include <stdlib.h>
void minHeapifyUp(int* arr, int node);
int* insert(int* arr, int data, int* elements, int* size);
int extractMin(int* arr, int* size, int* status);
int findMin(int* arr, int size, int* status);
void display(int* arr, int size);
int main(){
    int choice, data, elements = 0, size = 0, status = 0;
    int* heap = NULL;
    while(1){
        printf("Enter 1 to insert an element.\n");
        printf("Enter 2 to extract min element.\n");
        printf("Enter 3 to peek min element.\n");
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
                data = extractMin(heap, &elements, &status);
                if(status){
                    printf("Removed element: %d\n", data);
                }
                break;
            case 3:
                data = findMin(heap, elements, &status);
                if(status){
                    printf("Min element: %d\n", data);
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
void minHeapifyUp(int* arr, int node){
    int temp = arr[node];
    for(int i = node; i > 0; i = (i - 1) / 2){
        if(arr[(i - 1) / 2] > arr[i]){
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
    minHeapifyUp(arr, (*elements) - 1);
    return arr;
}
int extractMin(int* arr, int* size, int* status){
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
    *size -= 1;
    int temp = arr[0], i = 0;;
    while(i < *size){
        int smallest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        if(left < *size && arr[left] < arr[smallest]){
            smallest = left;
        }
        if(right < *size && arr[right] < arr[smallest]){
            smallest = right;
        }
        if(smallest != i && arr[smallest] < arr[i]){
            arr[i] = arr[smallest];
            arr[smallest] = temp;
        }
        else{
            break;
        }
        i = smallest;
    }
    return value;
}
int findMin(int* arr, int size, int* status){
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