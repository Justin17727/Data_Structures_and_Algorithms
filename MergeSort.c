#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int* merge(int* arr1, int arr1Size, int* arr2, int arr2Size);
void mergeSort(int* arr, int size);
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
int* merge(int* arr1, int arr1Size, int* arr2, int arr2Size){
    int* arr = calloc(arr1Size + arr2Size, sizeof(int));
    for(int i = 0, j = 0, k = 0; k < arr1Size + arr2Size; k++){
        if(j >= arr2Size){
            arr[k] = arr1[i];
            i++;
        }
        else if(i >= arr1Size){
            arr[k] = arr2[j];
            j++;
        }
        else{
            if(arr1[i] <= arr2[j]){
                arr[k] = arr1[i];
                i++;
            }
            else{
                arr[k] = arr2[j];
                j++;
            }
        }
    }
    return arr;
}
void mergeSort(int* arr, int size){
    if(size == 1){
        return;
    }
    int* left = calloc((size + 1) / 2, sizeof(int));
    memcpy(left, arr, (size + 1) / 2);
    int* right = calloc((size + 1) / 2, sizeof(int));
    memcpy(right, arr + ((size + 1) / 2), (size + 1) / 2);
    mergeSort(left, (size + 1) / 2);
    mergeSort(right, (size + 1) / 2);
    merge(left, (size + 1) / 2, right, (size + 1) / 2);
}