#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "aud-3.h"

//#define MAX (150 * 1000)
#define MAX (150 * 1000)

void quick_sort_impl(int* array);

void selection_sort_impl(int* array);

void insertion_sort_impl(int* array);

void shell_sort_impl(int* array);

void heap_sort_impl(int* array);

void generateRandomArray(int* array);

void generateAscendingArray(int* array);

void generateDescendingArray(int* array);

void measureTime(char* algorithm, void (* fct)(int*));

int main() {

    printf("Hello, World!\n");

    //measureTime("quick-sort", &quick_sort_impl);

    //measureTime("shell-sort", &shell_sort_impl);

    //measureTime("heap-sort", &heap_sort_impl);

    //measureTime("selection-sort", &selection_sort_impl);

    measureTime("insertion-sort", &insertion_sort_impl);

    /*for(int i = 0;i < MAX;i++) {
        printf("%d\n", array4[i]);
    }*/

    return 0;
}

void quick_sort_impl(int* array) {
    quick_sort(array, MAX);
}

void selection_sort_impl(int* array) {
    selection_sort(array, MAX);
}

void insertion_sort_impl(int* array) {
    insertion_sort(array, MAX);
}

void shell_sort_impl(int* array) {
    shell_sort(array, MAX);
}

void heap_sort_impl(int* array) {
    heap_sort(array, MAX);
}

void generateRandomArray(int* array) {
    srand(time(NULL));
    for (int i = 0; i < MAX; i++) {
        array[i] = rand();
    }
}

void generateAscendingArray(int* array) {
    for (int i = 0; i < MAX; i++) {
        array[i] = i;
    }
}

void generateDescendingArray(int* array) {
    for (int i = 0,j = MAX; i < MAX; i++) {
        array[i] = j--;
    }
}


void measureTime(char* algorithm, void (* fct)(int*)) {
    int* array = calloc(sizeof(int), MAX);
    double times[9];
    for (int i = 0; i < 9; i++) {
        if (i < 3) {// 0,1,2
            generateRandomArray(array);
        } else if (i < 6) {//3,4,5
            generateAscendingArray(array);
        } else if (i < 9) {//6,7,8
            generateDescendingArray(array);
        }
        struct timespec start, end;
        clock_gettime(CLOCK_MONOTONIC_RAW, &start);
        fct(array);
        clock_gettime(CLOCK_MONOTONIC_RAW, &end);
        times[i] = ((double) end.tv_sec + 1.0e-9 * end.tv_nsec) -
                   ((double) start.tv_sec + 1.0e-9 * start.tv_nsec);
        printf("%s took %f s\n", algorithm, times[i]);
    }
    double sum = 0;
    for (int i = 0; i < 3; i++) {
        sum += times[i];
    }
    double averageAscending = sum / 3.0;
    sum = 0;
    for (int i = 3; i < 6; i++) {
        sum += times[i];
    }
    double averageDescending = sum / 3.0;
    sum = 0;
    for (int i = 6; i < 9; i++) {
        sum += times[i];
    }
    double averageRandom = sum / 3.0;

    printf("%s average ascending %f s\n", algorithm, averageAscending);
    printf("%s average descending %f s\n", algorithm, averageDescending);
    printf("%s average random %f s\n", algorithm, averageRandom);
}