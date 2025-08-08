#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sys/time.h>

#define MAX_ARRAY_SIZE 100
int list[MAX_ARRAY_SIZE];



void swap (int *p, int *q)
{
    int tmp = *p;

    *p = *q;
    *q = tmp;
}


void bubblesort(int list[], int size)
{
    int i, j;

    for (i = 0; i < size; i++) {
        for (j = size - 1 ; j > i; j--) {
            if (list[j] < list[j - 1])
                swap(&list[j], &list[j-1]);
        }
    }

}


void bubblesort2(int list[], int size)
{
    int i, j;
  
    for (i = size - 1; i >= 0; i--) {
        for (j = 0; j < i ; j++) {
            if (list[j] > list[j + 1])
                swap(&list[j], &list[j+1]);
        }
    }
   
}


int main(void)
{
//    int list[] = {6, 35, 24, 1, 25, 15, 8, 22, 3, 23, 5, 18, 2, 11, 17, 31, 27, 4, \
//        14, 7, 29, 9, 19, 16, 12}

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
    size = (rand() % MAX_ARRAY_SIZE) + 1;
    
    printf("arraysize: %d\n\n", size);
    
    for (i = 0; i < size ; i++) {
        list[i] = (int) rand();
        printf("%d\n", list[i]);
    }


    bubblesort(list, size);

    printf("\n\n");
    for (i = 0; i < size; i++)
        printf("%d\n", list[i]);

}
