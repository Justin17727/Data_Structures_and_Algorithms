#include <stdio.h>
#include <stdlib.h>

void minHeapifyUp(int* arr, int node);
int* insert(int* arr, int data, int* elements, int* size);
int extractMin(int* arr, int* size, int* status);
int findMin(int* arr, int size, int* status);
void display(int* arr, int size);

int main(){
    
    int data;                    // data to insert
    int elements = 0, size = 0;  // array parameters, number of elements in it, and maximum it can have currently
    int choice;                  // to indicate user's choice with given options
    int status = 0;              // flag to indicate a success/failure of an operation
    int* heap = NULL;            // pointer to array (heap) memory segment
    
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
                
                // if succeded to delete
                if(status){
                    printf("Removed element: %d\n", data);
                }
                break;
            
            case 3:
                data = findMin(heap, elements, &status);
                
                // if succeded to find
                if(status){
                    printf("Min element: %d\n", data);
                }
                break;
        
            case 4:
                display(heap, elements);
                break;
    
            case 5:
            
                // free the memory and exit
                free(heap);
                return 0;
            
            default:
                printf("Invalid choice.\n");
        }
        printf("\n");
    }
}

// min heapify for single leaf node (last element) violation
void minHeapifyUp(int* arr, int node){
    int temp = arr[node];

    // iterate from child (2 * i) + 1 to parent node i
    for(int i = node; i > 0; i = (i - 1) / 2){

        // if parent is larger than child, swap them
        if(arr[(i - 1) / 2] > arr[i]){
            arr[i] = arr[(i - 1) / 2];
            arr[(i - 1) / 2] = temp;
        }
    }
}

// insert data to last index of the array (heap)
int* insert(int* arr, int data, int* elements, int* size){
    int* temp;

    // if the number of elements given is the same as size of current array
    if(*elements == *size){

        // if array memory is not allocated yet
        if(*size == 0){
            *size = 1;
            arr = malloc(sizeof(int));

            // if malloc failed to allocate memory
            if(arr == NULL){
                printf("Could not allocate more space for new node!");
                return arr;
            }

            (*elements)++;
            arr[0] = data;
            return arr;
        }

        // double the size of the array and relocate it
        (*size) *= 2;
        temp = realloc(arr, (*size) * sizeof(int));

        // if the reallocation of array fails
        if(temp == NULL){
            printf("Could not allocate more space for new node!");
            return arr;
        }

        arr = temp;
    }

    arr[*elements] = data;
    (*elements)++;

    // min heapify the array (heap)
    minHeapifyUp(arr, (*elements) - 1);
    return arr;
}

// extract min value from array (heap)
int extractMin(int* arr, int* size, int* status){
    int value = 0;

    // if array memory is not allocated yet
    if(*size == 0){
        printf("--Empty--\n");
        *status = 0;
        return value;
    }

    // status turned to 1 indicating success
    *status = 1;

    // delete min node at root (0th index element)
    value = arr[0];

    // if array had only one element
    if(*size == 1){
        *size -= 1;
        return value;
    }

    // place the last value (greatest value node) to root (0th index)
    arr[0] = arr[*size - 1];

    // reduce the size of heap to consider
    *size -= 1;

    // initialize temp for root value, and i for node index
    int temp = arr[0], i = 0;

    // traverse the heap, swapping nodes to remove min heap violation
    while(i < *size){

        // the root node is largest, so assuming it as smallest
        int smallest = i;       // smallest value's index
        int left = 2 * i + 1;   // left child index
        int right = 2 * i + 2;  // right child index

        // if left child exists and is smaller than current smallest index value
        if(left < *size && arr[left] < arr[smallest]){
            smallest = left;
        }

        // if right child exists and is smaller than current smallest index value
        if(right < *size && arr[right] < arr[smallest]){
            smallest = right;
        }

        // if smallest value node is not the same as current node and is actually smaller than current node
        if(smallest != i && arr[smallest] < arr[i]){
            arr[i] = arr[smallest];
            arr[smallest] = temp;
        }

        // if not then terminate the loop as no violation
        else{
            break;
        }

        // update current node index to the smallest child index
        i = smallest;
    }

    // return the min value from the array (heap)
    return value;
}

// to find the min value from the heap
int findMin(int* arr, int size, int* status){

    // if array has no elements
    if(size == 0){
        *status = 0;
        printf("--Empty--\n");
        return 0;
    }

    // operation is a success
    *status = 1;
    return arr[0];
}

// display the heap elements
void display(int* arr, int size){

    // if array has no elements
    if(size == 0){
        printf("--Empty--\n");
        return;
    }

    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }

    printf("\n");
}