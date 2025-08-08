#include <stdio.h>


void swap(int *p, int *q)
{
    int tmp = *p;
  
    *p = *q;
    *q = tmp;

}

void selectionsort(int list[], int size)
{
    int i, j;
  
    for (i = 0; i < size - 1; i++) {
      for (j = i ; j < size; j++) {
          if (list[j] < list[i])
              swap(&list[i], &list[j]);
      }
    }

}

int main(void)
{
    int list[] = {6, 35, 24, 1, 25, 15, 8, 22, 3, 23, 5, 18, 2, 11, 17, 31, 27, 4, 14, 7, 29, 9, 19, 16, 12};

    int size = 25, i;
    

    selectionsort(list, size);

    printf("\n\n");
    for (i = 0; i < size; i++)
        printf("%d\n", list[i]);

}

