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
    //check for this node/index
    //arr[k] < arr[2 * k + 1] || arr[k] < arr[2 * k + 2]
    while(2 * k + 1 < size){//if child node exists
        int temp = arr[k];
        if(2 * k + 2 == size){//if no right child
            if(arr[k] < arr[2 * k + 1]){
                arr[k] = arr[2 * k + 1];
                arr[2 * k + 1] = temp;
                return;
            }
        }
        int b = (arr[2 * k + 1] >= arr[2 * k + 2]) ? 2 * k + 1 : 2 * k + 2;//which child node is bigger
        printf("Checking with this node: %d\tSize: %d\t", b, size);
        if(arr[k] >= arr[b]){//is the child smaller than node
            return;
        }
        printf("Prev: %d", arr[k]);
        arr[k] = arr[b];
        printf("New: %d\n", arr[k]);
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