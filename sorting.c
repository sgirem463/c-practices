//
//  main.c
//  QuickSort
//
//  Created by alue on 9/25/14.
//  Copyright (c) 2014 alue. All rights reserved.
//

#include <stdio.h>
#include<stdlib.h>
#include <math.h>
#include <sys/time.h>

#define MAX_ARRAY_SIZE 100000000
int list[MAX_ARRAY_SIZE];

void quicksort(int list[], int n) {
    int i, tmp, tmp2;
    int j = 0; // pivot index, initialized to the first item
    
    if (n == 1)
        return;
    
    
//    printf("\n n = %d\n", n);
    
//    for (i = 0; i < n; i++)
//        printf("%d\n", list[i]);
//    printf("\n");
    
    for (i = 1; i < n; i++) {
        if (list[i] < list[j]) {
            if ((j+1) == i) {
                tmp = list[i];
                list[i] = list[j];
                list[j] = tmp;
                j = j + 1;
            } else {
                tmp = list[j];
                tmp2 = list[j+1];
                list[j] = list[i];
                list[j+1] = tmp;
                list[i] = tmp2;
                j = j + 1;
            }
        }
    }
    
//    printf("j = %d\n", j);
//    for (i = 0; i < n; i++)
//        printf("%d \n", list[i]);
//    printf("\n");
    
    if (j > 1) // at least 2 items
        quicksort(list, j);
    if ((n - j) > 2) // at least 2 items
        quicksort(&list[j+1], n - j - 1);
}

void swap(int a, int b) {
    int tmp;
    
//    printf("swap: %3d %d - %3d %d\n", a, list[a], b, list[b]);
    tmp = list[a];
    list[a] = list[b];
    list[b] = tmp;
}

void selectionSort(int list[], int n) {
    int i, j, tmp;
    
    
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (list[j] < list[i]) {
                tmp = list [i];
                list[i] = list[j];
                list[j] = tmp;
            }
        }
        
    }
}

void pushdown_old(int i, int n){
    
    
    while (i < (int)(n / 2)) {
        if (((2 * i) + 1) == n) {
            if (list[(2 * i) + 1] < list[i]) {
                swap(i, (2 * i) + 1);
                i = (2 * i) + 1;  // or just break
            }
        }
        else if (list[(2 * i) + 1] < list[(2 * i) + 2]) {
            if (list[(2 * i) + 1] < list[i]) {
                swap(i, (2 * i) + 1);
                i = (2 * i) + 1;
            } else {
                break;
            }
        } else {
            if (list[(2 * i) + 2] < list[i]) {
                swap(i, (2 * i) + 2);
                i = (2 * i) + 2;
            } else {
                break;
            }
        }
    }
}

void pushdown(int i, int last) // last is the last index of the passed in list
{
    int max; // idex of the max item in the parent children relationship
    int parent = i;

    printf("-- pushdown %d %d\n", i, last);
    while ((parent * 2 + 1) <= last) { // the parent has at least one child
        max = parent;
        if (list[max] < list[parent * 2 + 1])
            max = parent * 2 + 1;
        if (((parent * 2 + 2) <= last) && list[max] < list[parent * 2 + 2])
            max = parent * 2 + 2;
        if (max != parent) {
            swap(parent, max);
            parent = max;
        } else {
            break;
        }
    }
    printf("\n");

}



void heapSort(int list[], int n) { // n is the size of the list
    int i, j;
    
    printf("heapsort:\n");
    for (j = 0; j < n; j++)
        printf("%d %d\n", j, list[j]);
    printf("\n");

    // build the heap, left child = 2i + 1, right child = 2i + 2, parent = (int)((i - 1)/2)

    for (i = (int)((n - 1 - 1) / 2); i >= 0 ; i--) {
        pushdown(i, n - 1);
        printf("\n");
        for (j = 0; j < n; j++)
            printf("%d %d\n", j, list[j]);
    }
    for (i = n - 1 ; i >= 1; i--) {
        swap(0, i);
        pushdown(0, i - 1);
        
    }
}

void bubblesort(int list[], int n) {
    
    int i, j;
    
    for (i = n - 1; i >= 0 ; i--) {
        for (j = n - 1 ; j >= (n - i); j--) {
            if (list[j] < list[j - 1])
                swap(j, j - 1);
        }
    }
}



int main(int argc, const char * argv[]) {
    int size, i;
    unsigned long long millisecondsSinceEpoch;
    int seed;
    
    
    struct timeval tv;
    
    gettimeofday(&tv, NULL);
    
    millisecondsSinceEpoch =
    (unsigned long long)(tv.tv_sec) * 1000 +
    (unsigned long long)(tv.tv_usec) / 1000;
    
    seed = (int)(((unsigned long long) 0xffffffff) & millisecondsSinceEpoch);
    printf("seed: %x\n", seed);
    
    srand(seed);
    
    printf("%d   %d   RAND_MAX:%d\n", rand(), rand(), RAND_MAX);
//    size = (rand() % MAX_ARRAY_SIZE) + 1;
    size = 100000000;
    
    printf("arraysize: %d\n\n", size);
    
    for (i = 0; i < size ; i++) {
        list[i] = (int) rand();
//        printf("%d\n", list[i]);
    }
    
     quicksort(list, size);

    /*
     if (size > 1)
     quicksort(list, size);
     
     
     selectionSort(list, size);
     
    
     */
    
//    heapSort(list, size);
//   bubblesort(list, size);
    
//    printf("\n\n");
//    for (i = 0; i < size; i++)
//        printf("%d\n", list[i]);
    
}
