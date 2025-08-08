#include <stdio.h>

// To execute C, please define "int main()"

void bubblesort(int list[], int n);

int main() {
  int i;
  
  int list1[] = {3,2,5,7,1};
  int list2[] = {1,2,12,4,17,18};
    
  
  bubblesort(list1, 5);
    
  for (i = 0; i < 5; i++)
    printf("%d\n", list1[i]);
  
  printf("\n");
  bubblesort(list2, 6);
  
    for (i = 0; i < 6; i++)
    printf("%d\n", list2[i]);
      
  return 0;
}


/* 
Your previous Python 2 content is preserved below:

def bubblesort(my_list):
    pass

list1 = [3,2,5,7,1]
list2 = [1,2,12,4,17,18]

def bubblesort(List):
    n = len(List)
    
    for i in range(n, 1, -1):
        
        for j in range (
        
    
            
            
void bubbllesort(int chat)
 */


void swap(int *a, int *b)
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

void bubblesort(int list[], int n)
{
     int i, j;
  
     for (i = 0; i < n-1 ; i++) {
         for (j = n - 1; j >= i; j--) {
              if (list[j] < list[j-1]) {
                swap(&list[j], &list[j-1]);
              }
        }
    
     }
}
