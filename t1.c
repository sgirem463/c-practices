#include <stdio.h>
#include <stdlib.h>

int main (void)
{
    int *arr[10];

    int **i = arr;

    int *(*pA)[10];

    pA = &arr;


    printf("arr: %x\n", (unsigned int) arr);
    printf("&arr: %x\n",(unsigned int) &arr);
    printf("&(arr[0]): %x\n", (unsigned int) &(arr[0]));
    printf("pA: %x\n", (unsigned int) pA);


    printf("(arr +1): %x\n",(unsigned int) (arr + 1));
    printf("(&arr +1): %x\n",(unsigned int) (&arr + 1));
    printf("(pA + 1): %x\n", (unsigned int) (pA + 1));

}
