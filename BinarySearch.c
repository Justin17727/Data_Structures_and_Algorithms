#include <stdio.h>
#include <stdlib.h>
int binarySearch(int* arr, int key, int size);
int compare(const void* a, const void* b);
int main(){
    int n, b;
    printf("Enter the number of elements of array: ");
    scanf("%d", &n);
    int a[n];
    for(int i = 0; i < n; i++){
        printf("Enter element %d: ", i + 1);
        scanf("%d", &a[i]);
    }
    qsort(a, n, sizeof(int), compare);
    printf("Enter element to be searched: ");
    scanf("%d", &b);
    int index = binarySearch(a, b, n);
    index != -1 ? printf("Element found at index %d", index) : printf("Element not found");
}
int binarySearch(int* arr, int key, int size){
    int low = 0, high = size - 1, mid;
    while(low <= high){
        mid = (low + high) / 2;
        if(arr[mid] == key){
            return mid;
        }
        else if(arr[mid] < key){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return -1;
}
int compare(const void* a, const void* b){
    int* x = (int*)a;
    int* y = (int*)b;
    if(*x < *y){
        return -1;
    }
    if(*x > *y){
        return 1;
    }
    return 0;
}