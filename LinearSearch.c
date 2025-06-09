#include <stdio.h>
#include <stdlib.h>
int linearSearch(int* arr, int key, int size);
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
    int index = linearSearch(a, b, n);
    index != -1 ? printf("Element found at index %d", index) : printf("Element not found");
}
int linearSearch(int* arr, int key, int size){
    for(int i = 0; i < size; i++){
        if(arr[i] == key){
            return i;
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