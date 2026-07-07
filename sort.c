#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>

/* Generate Random Array */
void generateRandom(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        a[i] = rand() % 10000;
    }
}

/* Generate Ascending Array */
void generateAsc(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        a[i] = i;
    }
}

/* Generate Descending Array */
void generateDesc(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        a[i] = n - i;
    }
}

/* Selection Sort */
void Sort(int a[], int n)
{
    int i, j, min, temp;

    for (i = 0; i < n - 1; i++)
    {
        min = i;

        for (j = i + 1; j < n; j++)
        {
            if (a[j] < a[min])
            {
                min = j;
            }
        }

        if (min != i)
        {
            temp = a[i];
            a[i] = a[min];
            a[min] = temp;
        }
    }
}

/* Print Array */
void print(int a[], int s)
{
    for (int i = 0; i < s; i++)
    {
        printf("%d ", a[i]);
    }

    printf("\n");
}

int main()
{
    struct timeval te;

    int size = 8000;
    int step = 4000;

    for (int i = 0; i < 8; i++)
    {
        int a[size];

        /* Choose ONE input type */

        generateRandom(a, size);

        // generateAsc(a, size);

        // generateDesc(a, size);


        gettimeofday(&te, NULL);

        long long start =
            te.tv_sec * 1000LL + te.tv_usec / 1000;


        Sort(a, size);


        gettimeofday(&te, NULL);

        long long end =
            te.tv_sec * 1000LL + te.tv_usec / 1000;


        printf("Size: %d  Time: %lld ms\n",
               size, end - start);


        size += step;
    }

    return 0;
}
