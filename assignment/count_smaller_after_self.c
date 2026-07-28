#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int value;
    int index;
} Node;

void mergeSort(Node arr[], Node temp[], int ans[], int left, int right) {
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;

    mergeSort(arr, temp, ans, left, mid);
    mergeSort(arr, temp, ans, mid + 1, right);

    int i = left;
    int j = mid + 1;
    int k = left;

    int smaller = 0;

    while (i <= mid && j <= right) {
        if (arr[j].value < arr[i].value) {
            temp[k++] = arr[j++];
            smaller++;
        } else {
            ans[arr[i].index] += smaller;
            temp[k++] = arr[i++];
        }
    }

    while (i <= mid) {
        ans[arr[i].index] += smaller;
        temp[k++] = arr[i++];
    }

    while (j <= right)
        temp[k++] = arr[j++];

    for (i = left; i <= right; i++)
        arr[i] = temp[i];
}

int main() {
    int n;
    scanf("%d", &n);

    Node *arr = malloc(n * sizeof(Node));
    Node *temp = malloc(n * sizeof(Node));
    int *ans = calloc(n, sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i].value);
        arr[i].index = i;
    }

    mergeSort(arr, temp, ans, 0, n - 1);

    for (int i = 0; i < n; i++) {
        if (i > 0)
            printf(" ");

        printf("%d", ans[i]);
    }

    printf("\n");

    free(arr);
    free(temp);
    free(ans);

    return 0;
}