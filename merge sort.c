#include <stdio.h>
#include <stdlib.h>

/* Merge two subarrays arr[left..mid] and arr[mid+1..right] */
void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *leftArr = (int*)malloc(n1 * sizeof(int));
    int *rightArr = (int*)malloc(n2 * sizeof(int));

    if(leftArr == NULL || rightArr == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    /* Copy data to temp arrays */
    for(i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for(j = 0; j < n2; j++)
        rightArr[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;

    /* Merge back into arr[] */
    while(i < n1 && j < n2) {
        if(leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    /* Copy remaining elements */
    while(i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }
    while(j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }

    free(leftArr);
    free(rightArr);
}

/* Recursive merge sort */
void mergeSort(int arr[], int left, int right) {
    int mid;
    if(left < right) {
        mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int i;

    mergeSort(arr, 0, n - 1);

    printf("Sorted array: ");
    for(i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
