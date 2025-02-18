#include <stdio.h>
void bubbleSort(int* arr, int size);
int main(){
    int n;
    printf("Enter the number of elements to be sorted: ");
    scanf("%d", &n);
    int arr[n];
    for(int i=0; i<n; i++){
        printf("Enter element %d: ", i+1);
        scanf("%d", &arr[i]);
    }
    bubbleSort(arr, n);
    printf("Sorted array:\n");
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
}
void bubbleSort(int* arr, int size){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size - i - 1; j++){
            if(arr[j] > arr[j + 1]){
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}