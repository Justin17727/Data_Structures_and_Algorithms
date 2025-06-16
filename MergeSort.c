#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void merge(int* arr1, int begin1, int end1, int begin2, int end2, int* arr2);
void mergeSort_inf(int* arr1, int begin, int end, int* arr2);
void mergeSort(int* arr, int size);
int main(){
    int n;
    printf("Enter the number of elements to be sorted: ");
    scanf("%d", &n);
    int* arr = calloc(n, sizeof(int));
    for(int i = 0; i < n; i++){
        printf("Enter element %d: ", i+1);
        scanf("%d", &arr[i]);
    }
    mergeSort(arr, n);
    printf("Sorted array:\n");
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    free(arr);
}
void merge(int* arr1, int begin1, int end1, int begin2, int end2, int* arr2){
    for(int i = begin1, j = begin2, k = begin1; k <= end2; k++){
        if(j > end2){
            arr2[k] = arr1[i++];
        }
        else if(i > end1){
            arr2[k] = arr1[j++];
        }
        else{
            if(arr1[i] <= arr1[j]){
                arr2[k] = arr1[i++];
            }
            else{
                arr2[k] = arr1[j++];
            }
        }
    }
    for(int k = begin1; k <= end2; k++){
        arr1[k] = arr2[k];
    }
}
void mergeSort_inf(int* arr1, int begin, int end, int* arr2){
    if(begin == end){
        arr2[begin] = arr1[begin];
        return;
    }
    int mid = (end + begin) / 2;
    mergeSort_inf(arr1, begin, mid, arr2);
    mergeSort_inf(arr1, mid + 1, end, arr2);
    merge(arr1, begin, mid, mid + 1, end, arr2);
}
void mergeSort(int* arr, int size){
    int* temp = calloc(size, sizeof(int));
    memcpy(temp, arr, size * sizeof(int));
    mergeSort_inf(arr, 0, size - 1, temp);
    free(temp);
}