#include <stdio.h>
#include <stdlib.h>

int binarySearch(int* arr, int key, int size);
int compare(const void* a, const void* b);

int main(){
    
    int n;  // number of elements of the array
    int b;  // element to be searched
    
    printf("Enter the number of elements of array: ");
    scanf("%d", &n);
    
    // initialising an array of n elements
    int a[n];
    for(int i = 0; i < n; i++){
        printf("Enter element %d: ", i + 1);
        scanf("%d", &a[i]);
    }
    
    // sorting the array
    qsort(a, n, sizeof(int), compare);
    
    printf("Enter element to be searched: ");
    scanf("%d", &b);
    
    // index of the element to be searched
    int index = binarySearch(a, b, n);
    index != -1 ? printf("Element found at index %d", index) : printf("Element not found");
}

// search a key in given array of given size, return key's index
int binarySearch(int* arr, int key, int size){

    int low = 0;          // lower bound (index) to be considered
    int high = size - 1;  // upper bound (index) to be considered
    int mid;              // element's index in question being key or not

    // lower bound should always be lesser or equal to upper bound
    while(low <= high){

        // middle element of given bounds
        mid = (low + high) / 2;

        // if the middle element is the key
        if(arr[mid] == key){
            return mid;
        }

        // if the middle element is smaller than key, then key might exist after it
        else if(arr[mid] < key){
            low = mid + 1;
        }

        // if the middle element is larger than key, then key might exist before it
        else{
            high = mid - 1;
        }
    }

    // the key does'nt exist in the given array
    return -1;
}

// function to compare two elements given the pointers to them for qsort()
int compare(const void* a, const void* b){
    
    // convert the two void pointers to integer pointers
    int* x = (int*)a;
    int* y = (int*)b;
    
    if(*x < *y){
        return -1;  // signifying y should come before x
    }

    if(*x > *y){
        return 1;   // signifying x should come before y
    }

    return 0;       // signifying x and y are equal for sorting
}