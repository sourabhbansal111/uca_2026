#include <stdio.h>

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }

    swap(&arr[i], &arr[high]);
    return i;
}

void quickSelect(int arr[], int low, int high, int k) {
    if (low < high) {
        int p = partition(arr, low, high);

        if (p == k)
            return;
        else if (p > k)
            quickSelect(arr, low, p - 1, k);
        else
            quickSelect(arr, p + 1, high, k);
    }
}

int main() {
    int arr[] = {10, 4, 7, 2, 9, 1, 6, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 4;

    quickSelect(arr, 0, n - 1, k - 1);

    printf("Smallest %d elements:\n", k);
    for (int i = 0; i < k; i++)
        printf("%d ", arr[i]);

    return 0;
}