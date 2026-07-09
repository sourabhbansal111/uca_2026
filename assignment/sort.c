#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NUM_SIZES 8
#define NUM_TYPES 3

/* -------------------------------------------------
   Swap
------------------------------------------------- */

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}


/* -------------------------------------------------
   Selection Sort
------------------------------------------------- */

void selectionSort(int arr[], int n)
{
    int i, j, minIndex;

    for (i = 0; i < n - 1; i++)
    {
        minIndex = i;

        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }

        if (minIndex != i)
        {
            swap(&arr[i], &arr[minIndex]);
        }
    }
}


/* -------------------------------------------------
   Bubble Sort
------------------------------------------------- */

void bubbleSort(int arr[], int n)
{
    int i, j;
    int swapped;

    for (i = 0; i < n - 1; i++)
    {
        swapped = 0;

        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
                swapped = 1;
            }
        }

        /* Already sorted */
        if (swapped == 0)
        {
            break;
        }
    }
}


/* -------------------------------------------------
   Merge Sort
------------------------------------------------- */

void merge(int arr[], int left, int mid, int right)
{
    int i, j, k;

    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    if (L == NULL || R == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }

    for (i = 0; i < n1; i++)
    {
        L[i] = arr[left + i];
    }

    for (j = 0; j < n2; j++)
    {
        R[j] = arr[mid + 1 + j];
    }

    i = 0;
    j = 0;
    k = left;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }

        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);
}


void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}


/* -------------------------------------------------
   Quick Sort
   Last element used as pivot intentionally.

   Random Input  -> Average O(n log n)

   Ascending and Descending Input
                 -> Worst Case O(n^2)
------------------------------------------------- */

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];

    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;

            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);

    return i + 1;
}


void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivotIndex = partition(arr, low, high);

        quickSort(arr, low, pivotIndex - 1);

        quickSort(arr, pivotIndex + 1, high);
    }
}


/* -------------------------------------------------
   Input Generators
------------------------------------------------- */

void generateRandom(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand();
    }
}


void generateAscending(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = i;
    }
}


void generateDescending(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = n - i;
    }
}


/* -------------------------------------------------
   Timer
------------------------------------------------- */

double getMilliseconds(struct timespec start,
                       struct timespec end)
{
    return

        (end.tv_sec - start.tv_sec) * 1000.0

        +

        (end.tv_nsec - start.tv_nsec) / 1000000.0;
}


/* -------------------------------------------------
   Run Selection Sort
------------------------------------------------- */

double runSelection(int original[], int n)
{
    int *copy = malloc(n * sizeof(int));

    memcpy(copy, original, n * sizeof(int));

    struct timespec start, end;

    clock_gettime(CLOCK_MONOTONIC, &start);

    selectionSort(copy, n);

    clock_gettime(CLOCK_MONOTONIC, &end);

    free(copy);

    return getMilliseconds(start, end);
}


/* -------------------------------------------------
   Run Bubble Sort
------------------------------------------------- */

double runBubble(int original[], int n)
{
    int *copy = malloc(n * sizeof(int));

    memcpy(copy, original, n * sizeof(int));

    struct timespec start, end;

    clock_gettime(CLOCK_MONOTONIC, &start);

    bubbleSort(copy, n);

    clock_gettime(CLOCK_MONOTONIC, &end);

    free(copy);

    return getMilliseconds(start, end);
}


/* -------------------------------------------------
   Run Merge Sort
------------------------------------------------- */

double runMerge(int original[], int n)
{
    int *copy = malloc(n * sizeof(int));

    memcpy(copy, original, n * sizeof(int));

    struct timespec start, end;

    clock_gettime(CLOCK_MONOTONIC, &start);

    mergeSort(copy, 0, n - 1);

    clock_gettime(CLOCK_MONOTONIC, &end);

    free(copy);

    return getMilliseconds(start, end);
}


/* -------------------------------------------------
   Run Quick Sort
------------------------------------------------- */

double runQuick(int original[], int n)
{
    int *copy = malloc(n * sizeof(int));

    memcpy(copy, original, n * sizeof(int));

    struct timespec start, end;

    clock_gettime(CLOCK_MONOTONIC, &start);

    quickSort(copy, 0, n - 1);

    clock_gettime(CLOCK_MONOTONIC, &end);

    free(copy);

    return getMilliseconds(start, end);
}


/* -------------------------------------------------
   Main
------------------------------------------------- */

int main()
{
    int sizes[NUM_SIZES] =
    {
        8000,
        12000,
        16000,
        20000,
        24000,
        28000,
        32000,
        36000
    };


    srand(42);


    /*
       Column order matches Excel exactly.

       A  Input Size

       B  Selection Random
       C  Selection Asc
       D  Selection Desc

       E  Bubble Random
       F  Bubble Asc
       G  Bubble Desc

       H  Merge Random
       I  Merge Asc
       J  Merge Desc

       K  Quick Random
       L  Quick Asc
       M  Quick Desc
    */


    printf("Input Size\t");

    printf("Selection Random\tSelection Asc\tSelection Desc\t");

    printf("Bubble Random\tBubble Asc\tBubble Desc\t");

    printf("Merge Random\tMerge Asc\tMerge Desc\t");

    printf("Quick Random\tQuick Asc\tQuick Desc\n");


    /* Zero row for graph origin */

    printf("0\t");

    for (int i = 0; i < 11; i++)
    {
        printf("0\t");
    }

    printf("0\n");


    for (int s = 0; s < NUM_SIZES; s++)
    {
        int n = sizes[s];


        int *randomArray =
            malloc(n * sizeof(int));

        int *ascendingArray =
            malloc(n * sizeof(int));

        int *descendingArray =
            malloc(n * sizeof(int));


        if (randomArray == NULL ||
            ascendingArray == NULL ||
            descendingArray == NULL)
        {
            printf("Memory allocation failed\n");

            return 1;
        }


        generateRandom(randomArray, n);

        generateAscending(ascendingArray, n);

        generateDescending(descendingArray, n);


        /*
           Selection Sort
        */

        double selectionRandom =
            runSelection(randomArray, n);

        double selectionAsc =
            runSelection(ascendingArray, n);

        double selectionDesc =
            runSelection(descendingArray, n);


        /*
           Bubble Sort
        */

        double bubbleRandom =
            runBubble(randomArray, n);

        double bubbleAsc =
            runBubble(ascendingArray, n);

        double bubbleDesc =
            runBubble(descendingArray, n);


        /*
           Merge Sort
        */

        double mergeRandom =
            runMerge(randomArray, n);

        double mergeAsc =
            runMerge(ascendingArray, n);

        double mergeDesc =
            runMerge(descendingArray, n);


        /*
           Quick Sort
        */

        double quickRandom =
            runQuick(randomArray, n);

        double quickAsc =
            runQuick(ascendingArray, n);

        double quickDesc =
            runQuick(descendingArray, n);


        /*
           Print Excel-compatible row
        */

        printf(
            "%d\t"

            "%.3f\t%.3f\t%.3f\t"

            "%.3f\t%.3f\t%.3f\t"

            "%.3f\t%.3f\t%.3f\t"

            "%.3f\t%.3f\t%.3f\n",

            n,

            selectionRandom,
            selectionAsc,
            selectionDesc,

            bubbleRandom,
            bubbleAsc,
            bubbleDesc,

            mergeRandom,
            mergeAsc,
            mergeDesc,

            quickRandom,
            quickAsc,
            quickDesc
        );


        free(randomArray);

        free(ascendingArray);

        free(descendingArray);
    }


    return 0;
}