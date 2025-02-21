#include <stdio.h>
#include <stdlib.h>
void QuickSort(int* arr, int size);
int main(){
    int n;
    printf("Enter the number of elements to be sorted: ");
    scanf("%d", &n);
    int arr[n];
    for(int i=0; i<n; i++){
        printf("Enter element %d: ", i+1);
        scanf("%d", &arr[i]);
    }
    mergeSort(arr, n);
    printf("Sorted array:\n");
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
}
void QuickSort(int* arr, int size){
}