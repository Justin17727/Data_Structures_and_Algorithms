#include <stdio.h>
void heapSort(int* arr, int size);
void maxHeapify(int* arr, int size, int k);
void extractMax(int* arr, int size);
void makeMaxHeap(int* arr, int size);
int main(){
    int n;
    printf("Enter the number of elements to be sorted: ");
    scanf("%d", &n);
    int arr[n];
    for(int i=0; i<n; i++){
        printf("Enter element %d: ", i+1);
        scanf("%d", &arr[i]);
    }
    heapSort(arr, n);
    printf("Sorted array:\n");
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
}
void extractMax(int* arr, int size){
    int temp = arr[size - 1];
    arr[size - 1] = arr[0];
    arr[0] = temp;
}
void makeMaxHeap(int* arr, int size){
    for(int i = 1; i < size; i++){
        int j = i;
        while(j > 0 && arr[(j - 1) / 2] < arr[j]){
            int temp = arr[j];
            arr[j] = arr[(j - 1) / 2];
            arr[(j - 1) / 2] = temp;
            j = (j - 1) / 2;
        }
    }
}
void maxHeapify(int* arr, int size, int k){
    while(2 * k + 1 < size){
        int b = 2 * k + 1;
        if(2 * k + 2 < size && arr[2 * k + 2] > arr[b]){
            b = 2 * k + 2;
        }
        if(arr[k] >= arr[b]){
            return;
        }
        int temp = arr[k];
        arr[k] = arr[b];
        arr[b] = temp;
        k = b;
    }
}
void heapSort(int* arr, int size){
    makeMaxHeap(arr, size);
    while(size != 1){
        extractMax(arr, size);
        size--;
        maxHeapify(arr, size, 0);
    }
}