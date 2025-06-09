#include <stdio.h>
void selectionSort(int* arr, int size);
int main(){
    int n;
    printf("Enter the number of elements to be sorted: ");
    scanf("%d", &n);
    int arr[n];
    for(int i = 0; i < n; i++){
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    selectionSort(arr, n);
    printf("Sorted array:\n");
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
}
void selectionSort(int* arr, int size){
    for(int i = 0; i < size; i++){
        int index = i;
        int min = arr[i];
        for(int j = i; j < size; j++){
            if(arr[j] < min){
                min = arr[j];
                index = j;
            }
        }
        arr[index] = arr[i];
        arr[i] = min;
    }
}