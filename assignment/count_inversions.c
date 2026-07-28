#include <stdio.h>
#include <stdlib.h>

long long merge(int arr[], int temp[], int left, int mid, int right) {
    int i = left;
    int j = mid + 1;
    int k = left;

    long long count = 0;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];

            // All remaining elements on the left are greater
            count += mid - i + 1;
        }
    }

    while (i <= mid)
        temp[k++] = arr[i++];

    while (j <= right)
        temp[k++] = arr[j++];

    for (i = left; i <= right; i++)
        arr[i] = temp[i];

    return count;
}

long long mergeSort(int arr[], int temp[], int left, int right) {
    if (left >= right)
        return 0;

    int mid = left + (right - left) / 2;

    long long count = 0;

    count += mergeSort(arr, temp, left, mid);
    count += mergeSort(arr, temp, mid + 1, right);
    count += merge(arr, temp, left, mid, right);

    return count;
}

int main() {
    int n;
    scanf("%d", &n);

    int *arr = malloc(n * sizeof(int));
    int *temp = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("%lld\n", mergeSort(arr, temp, 0, n - 1));

    free(arr);
    free(temp);

    return 0;
}