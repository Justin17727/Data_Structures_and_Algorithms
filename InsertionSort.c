#include <stdio.h>
void insertionSort(int* a, int size);
int main(){
    int n;
    printf("Enter the number of elements to be sorted: ");
    scanf("%d", &n);
    int arr[n];
    for(int i=0; i<n; i++){
        printf("Enter element %d: ", i+1);
        scanf("%d", &arr[i]);
    }
    insertionSort(arr, n);
    printf("Sorted array:\n");
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
}
void insertionSort(int* a, int size){
    for(int i=1; i<size; i++){
        int k=a[i], j=i-1;
        while(j >= 0 && k<a[j]){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=k;
    }
}