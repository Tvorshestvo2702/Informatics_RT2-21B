#include <stdio.h>
#include <stdlib.h>

void siftDown(int* numbers, int root, int bottom)
{
    int maxChild; 
    int done = 0; 
    while ((root * 2 <= bottom) && (!done))
    {
        if (root * 2 == bottom)   
            maxChild = root * 2;   
        else if (numbers[root * 2] > numbers[root * 2 + 1])
            maxChild = root * 2;
        else
            maxChild = root * 2 + 1;
        if (numbers[root] < numbers[maxChild])
        {
            int temp = numbers[root]; 
            numbers[root] = numbers[maxChild];
            numbers[maxChild] = temp;
            root = maxChild;
        }
        else 
            done = 1; 
    }
}

void heapSort(int* numbers, int array_size)
(
    int i = (array_size / 2) - 1;
    while (i >= 0) {
        siftDown(numbers, i, array_size - 1);
        i--;
    }

    int j;
    for (j = array_size - 1; j >= 1; j--)
    {
        int temp = numbers[0];
        numbers[0] = numbers[j];
        numbers[j] = temp;
        siftDown(numbers, 0, j - 1);
    }
}
int main()
{   int z;
    printf ("Enter count of elements: ");
    scanf("%d", &z);
    int a[z];
    int i;
    int j;

    for ( i = 0; i < z; i++) {
        a[i] = rand() % 20 - 10;
    }

    printf ("Start array: ");
    for ( j = 0; j < z; j++) {
        printf("%d ", a[j]);
    }
    printf("\n");
    heapSort(a, z); 
    printf ("Sort array: ");
    int k = 0;
    while (k<z) {
        printf ("%d  ", a[k]);
        k++;
    }

    printf("\n");
    return 0;
}
