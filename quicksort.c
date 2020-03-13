#include <stdio.h>
#include <stdlib.h>

 void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int l, int h)
{
    int right = arr[h];
    int i = (l - 1);
    int j;
    for ( j = l; j <= h - 1; j++) {
        if (arr[j] <= x) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[h]);
    return (i + 1);
}

void quickSortIterative(int arr[], int l, int h)
{

    int stack[h - l + 1];


    int top = -1;


    stack[++top] = l;
    stack[++top] = h;


    while (top >= 0) {

        h = stack[top--];
        l = stack[top--];


        int p = partition(arr, l, h);


        if (p - 1 > l) {
            stack[++top] = l;
            stack[++top] = p - 1;
        }

        if (p + 1 < h) {
            stack[++top] = p + 1;
            stack[++top] = h;
        }
    }
}

// A utility function to print contents of arr
void printArr(int arr[], int n)
{
    int i;
    for (i = 0; i < n; ++i)
        printf("%d ", arr[i]);
}

// Driver program to test above functions
/*int main()
{
    int arr[] = { 10,20,1,9,21,13,40,86,124,65};
    int n = sizeof(arr) / sizeof(*arr);
    quickSortIterative(arr, 0, n - 1);
    printArr(arr, n);
    return 0;
}
*/
