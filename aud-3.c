//
// Created by Fabian Terhorst on 04.12.17.
//

#include "aud-3.h"

#define SWAP(a, b) (a ^= b ^= a ^=b)

/*
 Quicksort ist ein rekursiver Sortieralgorithmus,
 der die zu sortierende Liste in zwei Teillisten unterteilt und alle Elemente,
 die kleiner sind als das Pivot-Element,
 in die linke Teilliste, alle anderen in die rechte Teilliste einsortiert.
 */
/*void quick_sort(int a[], int l, int r) {
    int v, i, j, t;
    if (r > l) {
        v = a[r];
        i = l - 1;
        j = r;
        for (;;) {
            while (a[++i] < v);
            while (a[--j] > v);
            if (i >= j) break;
            t = a[i];
            a[i] = a[j];
            a[j] = t;
        }
        t = a[i];
        a[i] = a[r];
        a[r] = t;
        quick_sort(a, l, i - 1);
        quick_sort(a, i + 1, r);
    }
}*/

void quick_sort(int* arr, int elements) {

#define  MAX_LEVELS  150000

    int piv, beg[MAX_LEVELS], end[MAX_LEVELS], i = 0, L, R, swap;

    beg[0] = 0;
    end[0] = elements;
    while (i >= 0) {
        L = beg[i];
        R = end[i] - 1;
        if (L < R) {
            piv = arr[L];
            while (L < R) {
                while (arr[R] >= piv && L < R) R--;
                if (L < R) arr[L++] = arr[R];
                while (arr[L] <= piv && L < R) L++;
                if (L < R) arr[R--] = arr[L];
            }
            arr[L] = piv;
            beg[i + 1] = L + 1;
            end[i + 1] = end[i];
            end[i++] = L;
            if (end[i] - beg[i] > end[i - 1] - beg[i - 1]) {
                swap = beg[i];
                beg[i] = beg[i - 1];
                beg[i - 1] = swap;
                swap = end[i];
                end[i] = end[i - 1];
                end[i - 1] = swap;
            }
        } else {
            i--;
        }
    }
}

/*void quick_sort(int *arr, int low, int high)
{
    int pivot, i, j, temp;
    if(low < high) {
        pivot = low; // select a pivot element
        i = low;
        j = high;
        while(i < j) {
            // increment i till you get a number greater than the pivot element
            while(arr[i] <= arr[pivot] && i <= high)
                i++;
            // decrement j till you get a number less than the pivot element
            while(arr[j] > arr[pivot] && j >= low)
                j--;
            // if i < j swap the elements in locations i and j
            if(i < j) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }

        // when i >= j it means the j-th position is the correct position
        // of the pivot element, hence swap the pivot element with the
        // element in the j-th position
        temp = arr[j];
        arr[j] = arr[pivot];
        arr[pivot] = temp;
        // Repeat quicksort for the two sub-arrays, one to the left of j
        // and one to the right of j
        quick_sort(arr, low, j-1);
        quick_sort(arr, j+1, high);
    }
}*/

/*int partition( int a[], int l, int r) {
    int pivot, i, j, t;
    pivot = a[l];
    i = l; j = r+1;

    while( 1)
    {
        do ++i; while( a[i] <= pivot && i <= r );
        do --j; while( a[j] > pivot );
        if( i >= j ) break;
        t = a[i]; a[i] = a[j]; a[j] = t;
    }
    t = a[l]; a[l] = a[j]; a[j] = t;
    return j;
}

void quick_sort( int a[], int l, int r)
{
    int j;

    if( l < r )
    {
        // divide and conquer
        j = partition( a, l, r);
        quick_sort( a, l, j-1);
        quick_sort( a, j+1, r);
    }

}*/

/*void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void quick_sort(int *begin, int *end)
{
    int *ptr;
    int *split;
    if (end - begin <= 1)
        return;
    ptr = begin;
    split = begin + 1;
    while (++ptr <= end) {
        if (*ptr < *begin) {
            swap(ptr, split);
            ++split;
        }
    }
    swap(begin, split - 1);
    quicksort(begin, split - 1);
    quicksort(split, end);
}*/

/*

 */
void selection_sort(int daten[], int anzahl) // Anzahl und Array mit Daten
{
    int i, k, t, min; // i ist Kontrollvariable für die äußere, k für die innere Schleife.
    // t ist Zwischenspeicher beim Tauschen. min merkt sich den kleinsten Wert
    // im Teilarray.

    for (i = 0; i < anzahl - 1; i++) {
        min = i;
        for (k = i + 1; k < anzahl; k++) {
            if (daten[k] < daten[min])
                min = k;
        }

        t = daten[min];  // Tauschen
        daten[min] = daten[i];
        daten[i] = t;
    }
}

/*void insertion_sort(int a[], int n) {
    int i, j, v;
    for (i = 2; i <= n; i++) {
        v = a[i];
        j = i;
        while (a[j - 1] > v) {
            a[j] = a[j - 1];
            j--;
        }
        a[j] = v;
    }
}*/

void insertion_sort(int a[], int n) {
    int i, j, v;
    for (i = 1; i < n; i++) {
        v = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > v) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = v;
    }
}

/*void insertion_sort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}*/


/* Move elements of arr[0..i-1], that are
           greater than key, to one position ahead
           of their current position */

/*void down_heap(int a[], int N, int k) {
    int j, v;
    v = a[k];
    while (k <= N / 2) {
        j = k + k;
        if (j < N && a[j] < a[j + 1]) j++;
        if (v >= a[j]) break;
        a[k] = a[j];
        k = j;
    }
    a[k] = v;
}

void heap_sort(int a[], int N) {
    int k, t;
    for (k = N / 2; k >= 1; k--) down_heap(a, N, k);
    while (N > 1) {
        t = a[1];
        a[1] = a[N];
        a[N] = t;
        down_heap(a, --N, 1);
    }
}*/

// To heapify a subtree rooted with node i which is
// an index in arr[]. n is size of heap
void heapify(int arr[], int n, int i) {
    int largest = i;  // Initialize largest as root
    int l = 2 * i + 1;  // left = 2*i + 1
    int r = 2 * i + 2;  // right = 2*i + 2

    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;

    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;

    // If largest is not root
    if (largest != i) {
        SWAP(arr[i], arr[largest]);

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

// main function to do heap sort
void heap_sort(int arr[], int n) {
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // One by one extract an element from heap
    for (int i = n - 1; i >= 0; i--) {
        // Move current root to end
        SWAP(arr[0], arr[i]);

        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

/*void shell_sort(int a[], int N) {
    int i, j, h, v;
    for (h = 1; h <= N / 3; h = 3 * h + 1);
    for (; h > 0; h /= 3)
        for (i = h + 1; i <= N; i++) {
            v = a[i];
            j = i;
            while (j > h && a[j - h] > v) {
                a[j] = a[j - h];
                j -= h;
            }
            a[j] = v;
        }
}*/

void shell_sort(int arr[], int n) {
    // Start with a big gap, then reduce the gap
    for (int gap = n / 2; gap > 0; gap /= 2) {
        // Do a gapped insertion sort for this gap size.
        // The first gap elements a[0..gap-1] are already in gapped order
        // keep adding one more element until the entire array is
        // gap sorted
        for (int i = gap; i < n; i += 1) {
            // add a[i] to the elements that have been gap sorted
            // save a[i] in temp and make a hole at position i
            int temp = arr[i];

            // shift earlier gap-sorted elements up until the correct
            // location for a[i] is found
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];

            //  put temp (the original a[i]) in its correct location
            arr[j] = temp;
        }
    }
}