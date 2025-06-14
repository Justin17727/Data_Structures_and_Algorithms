#include <stdio.h>
#include <stdlib.h>
int* merge(int* left, int end1, int* right, int end2);
int* mergeSort(int* arr, int begin, int end);
int main(){
    int n;
    printf("Enter the number of elements to be sorted: ");
    scanf("%d", &n);
    int* arr = calloc(n, sizeof(int));
    for(int i = 0; i < n; i++){
        printf("Enter element %d: ", i+1);
        scanf("%d", &arr[i]);
    }
    arr = mergeSort(arr, 0, n - 1);
    printf("Sorted array:\n");
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    free(arr);
}
int* merge(int* left, int end1, int* right, int end2){
    int size = end1 + end2 + 2;
    int* arr = calloc(size, sizeof(int));
    for(int i = 0, j = 0, k = 0; k < size; k++){
        if(i > end1){
            arr[k] = right[j++];
        }
        else if(j > end2){
            arr[k] = left[i++];
        }
        else{
            if(left[i] <= right[j]){
                arr[k] = left[i++];
            }
            else{
                arr[k] = right[j++];
            }
        }
    }
    free(right);
    free(left);
    return arr;
}
int* mergeSort(int* arr, int begin, int end){
    if(begin == end){
        return arr;
    }
    int mid = (end + begin) / 2;
    int* left = calloc(mid - begin + 1, sizeof(int));
    for(int i = begin, j = 0; i <= mid; i++, j++){
        left[j] = arr[i];
    }
    int* right = calloc(end - mid, sizeof(int));
    for(int i = mid + 1, j = 0; i <= end; i++, j++){
        right[j] = arr[i];
    }
    free(arr);
    end = end - mid - 1;
    left = mergeSort(left, 0, mid);
    right = mergeSort(right, 0, end);
    return merge(left, mid, right, end);
}