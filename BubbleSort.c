#include <stdio.h>

void bubbleSort(int* arr, int size);

int main(){
    int n;  // number of elements in array
    
    // input array size
    printf("Enter the number of elements to be sorted: ");
    scanf("%d", &n);
    int arr[n];
    
    // input array elements
    for(int i = 0; i < n; i++){
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    
    bubbleSort(arr, n);  // sort the array elements
    
    // display array elements
    printf("Sorted array:\n");
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
}

// bubble sort implementation
void bubbleSort(int* arr, int size){

    // for every element
    for(int i = 0; i < size; i++){

        // for element at 0th index till last sorted index
        for(int j = 0; j < size - i - 1; j++){
            
            // if next element smaller than current element then swap
            if(arr[j] > arr[j + 1]){
                
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}