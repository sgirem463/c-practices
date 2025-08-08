#include <stdio.h>
#include <memory.h>


typedef struct n {
    int val;
    struct n *next;
} node;


// remove a middle item, i.e. not the first or last
void removeMiddle3(node **list)
{
    node *prev, *p;
    int n;

    prev = NULL;
    p = *list;

    // remove the 2nd item if there are 3rd
    n = 0;
    while (p && (++n <= 2)) {
        if (n == 2) {
            // remove the current item if the next is not NULL
            if (p->next) {
                prev->next = p->next;
            }
        } else {
            prev = p;
            p = p->next;
        }
    }
}


// remove a middle item, i.e. not the first or last
void removeMiddle4(node **list)
{
    node *prev, *p;
    int n;

    prev = NULL;
    p = *list;

    // remove the 2nd item if there are 3rd
    n = 0;
    while (p) {
        ++n;
        if (n == 2) {
            // remove the current item if the next is not NULL
            if (p->next) {
                prev->next = p->next;
            }
            break;
        } else {
            prev = p;
            p = p->next;
        }
    }
}



void matchRemove3(node **list, int number)
{
    node *prev, *p, *head;

    head = *list;
    p = *list; // pointer to the curret element

    prev = NULL;

    while (p) {
        if (p->val == number) {
            if (prev == NULL) {
                //remove the first item
                *list = p->next;    

                // free(p) 
            } else {
                // delink the current item
                prev->next = p->next;    

                // free(p) if it's a dynamically allocated item
            }
            break;
        } else {
            prev = p;
            p = p->next;
        }
    }
}

void reverseList(node **list)
{
    node *prev, *p, *next, *q;
  
    prev = NULL;
    p = *list;

    while (p) {
      if (prev == NULL) {
        prev = p;
        p = p->next;
        prev->next = NULL;
      } else {
        q = p->next;
        p->next = prev;
        prev = p;
        p = q;
      }
    }
    *list = prev;
}


void reverseList2(node **list)
{
    node *prev, *p, *next, *q;

    prev = NULL;
    p = *list;
    while (p) {
        q = p->next;
        p->next = prev;
        prev = p;
        p = q;
    }
    *list = prev;
}


void reverseList3(node **list)
{
    node *prev;
    node *p;
    node *next;

    prev = NULL;
    p = *list;

    while (p) {
        next = p->next;
        p->next = prev;
        prev = p;
        p = next;
    }
    if (prev) {
        *list = prev;
    }

}



void reverseListPartial(node **list, int n)
{
    node *prev, *p, *next, *q;

    prev = NULL;
    p = *list;
    while (p && n--) {
        q = p->next;
        p->next = prev;
        prev = p;
        p = q;
    }

    /*
     * exiting the loop, p is set to the next item in the list to be processed
     */
    if (p) {
        (*list)->next = p;
    }

    if (n > 0) {
        *list = NULL;
    } else {
        *list = prev;
    }
}




void printlist(node *p) {
    while (p) {
        printf("%d ->", p->val);
        p = p->next;
    }
    printf("NULL\n");
}


void removeMiddle(node **list)
{
    node *prev, *p, *next, *q;
    int has_head = 0;
    int has_tail = 0;
    
    p = *list;
    prev = NULL;

    while(p) {
        if (prev == NULL) {
            prev = p;
            p = p->next;
        } else {
           // if we reach here, there is a head pointed by prev
           if (p->next) {
                // and now there is a tail
                prev->next = p->next;
                break;
           } else {
                break;
           }

        }
    }
}


void removeMiddle2(node **list)
{
    node *prev, *p, *next, *q;
  
    prev = NULL;
    p = *list;

    if (!p) {
        printf("empty list\n");
        return;
    }
        
    if (!p->next) {
        printf("only one item\n");
        return;
    }

    prev = p;
    p = p->next;
    if (!p->next) {
        printf("only two items\n");
        return;
    } else {
        prev->next = p->next;
    }

}

void matchRemove(node **list, int number)
{
  node *p, *q, *prev;
  
  q = *list;
  p = *list;
  prev = NULL;
  
  while (p) {
    if (p->val == number) {
      if (prev == NULL) {
        q = p->next;
        p->next = NULL;
      } else {
        prev->next = p->next;
      }
      printf("found value == %d\n", p->val);
      break;
    }
    prev = p;
    p = p->next;
  }
  *list = q;
}




int main(int argc, const char * argv[]) {
    int i;
    int t1[10] = {};
    int t2[10] = {2};
    int t3[10] = {2, 2};
    int t4[10] = {2, 2, 0, 3};
    int t5[10] = {4, 2, 2};
    int t6[10] = {5, 3, 2, 2, 3, 2, 3, 2};
    int t7[10] = {6, 2, 3, 2, 4, 5};
    int t8[10] = {3};
    int t9[10] = {2, 3, 6, 2, 4, 2, 9, 5, 2, 8};
    
    node n[10];
    node *head = n;
    node *p;
    int size;
    
  
    // test case 1
    memset(&(n[0]), 0, sizeof(node) * 10);
    head = p = n;
    size = 0;
    for (i = 0; i < size; i++) {
        // assign the value
        p->val = t1[i];
        
        // next item is not NULL only if the next index is less than size (C is zero based)
        if ((i + 1) < size) {
            // make link to the next item
            p->next = &n[i + 1];
            
            // move to work on the next item
            p = p->next;
        }
    }
    printlist(NULL);
    matchRemove(&head, 2);
    printlist(NULL);
    printf("\n");
    
    
    // test case 2
    memset(&(n[0]), 0, sizeof(node) * 10);
    head = p = n;
    size = 1;
    for (i = 0; i < size; i++) {
        p->val = t2[i];
        if ((i + 1) < size) {
            p->next = &n[i + 1];
            p = p->next;
        }
    }
    printlist(head);
    matchRemove(&head, 2);
    printlist(head);
    printf("\n");
    
    // test case 3
    memset(&(n[0]), 0, sizeof(node) * 10);
    head = p = n;
    size = 2;
    for (i = 0; i < size; i++) {
        p->val = t3[i];
        if ((i + 1) < size) {
            p->next = &n[i + 1];
            p = p->next;
        }
    }
    printlist(head);
    matchRemove(&head, 2);
    printlist(head);
    printf("\n");
    
    // test case 4
    memset(&(n[0]), 0, sizeof(node) * 10);
    head = p = n;
    size = 4;
    for (i = 0; i < size; i++) {
        p->val = t4[i];
        if ((i + 1) < size) {
            p->next = &n[i + 1];
            p = p->next;
        }
    }
    printlist(head);
    matchRemove(&head, 2);
    printlist(head);
    printf("\n");
    
    // test case 5
    memset(&(n[0]), 0, sizeof(node) * 10);
    head = p = n;
    size = 3;
    for (i = 0; i < size; i++) {
        p->val = t5[i];
        if ((i + 1) < size) {
            p->next = &n[i + 1];
            p = p->next;
        }
    }
    printlist(head);
    matchRemove(&head, 2);
    printlist(head);
    printf("\n");
    
    
    // test case 6
    memset(&(n[0]), 0, sizeof(node) * 10);
    head = p = n;
    size = 8;
    for (i = 0; i < size; i++) {
        p->val = t6[i];
        if ((i + 1) < size) {
            p->next = &n[i + 1];
            p = p->next;
        }
    }
    printlist(head);
    matchRemove(&head, 2);
    printlist(head);
    printf("\n");
    
    // test case 7
    memset(&(n[0]), 0, sizeof(node) * 10);
    head = p = n;
    size = 6;
    for (i = 0; i < size; i++) {
        p->val = t7[i];
        if ((i + 1) < size) {
            p->next = &n[i + 1];
            p = p->next;
        }
    }
    printlist(head);
    matchRemove(&head, 2);
    printlist(head);
    printf("\n");
    
    
    
    // test case 8
    memset(&(n[0]), 0, sizeof(node) * 10);
    head = p = n;
    size = 1;
    for (i = 0; i < size; i++) {
        p->val = t8[i];
        if ((i + 1) < size) {
            p->next = &n[i + 1];
            p = p->next;
        }
    }
    printlist(head);
    matchRemove(&head, 2);
    printlist(head);
    printf("\n");
    
    
    // test case 9
    memset(&(n[0]), 0, sizeof(node) * 10);
    head = p = n;
    size = 10;
    for (i = 0; i < size; i++) {
        p->val = t9[i];
        if ((i + 1) < size) {
            p->next = &n[i + 1];
            p = p->next;
        }
    }
    printlist(head);
    matchRemove(&head, 2);
    printlist(head);
    printf("\n");
    
    // test case 1
    memset(&(n[0]), 0, sizeof(node) * 10);
    head = p = n;
    size = 0;
    for (i = 0; i < size; i++) {
        // assign the value
        p->val = t1[i];
        
        // next item is not NULL only if the next index is less than size (C is zero based)
        if ((i + 1) < size) {
            // make link to the next item
            p->next = &n[i + 1];
            
            // move to work on the next item
            p = p->next;
        }
    }
    printlist(NULL);
    matchRemove3(&head, 2);
    printlist(NULL);
    printf("\n");
    
    
    // test case 2
    memset(&(n[0]), 0, sizeof(node) * 10);
    head = p = n;
    size = 1;
    for (i = 0; i < size; i++) {
        p->val = t2[i];
        if ((i + 1) < size) {
            p->next = &n[i + 1];
            p = p->next;
        }
    }
    printlist(head);
    matchRemove3(&head, 2);
    printlist(head);
    printf("\n");
    
    // test case 3
    memset(&(n[0]), 0, sizeof(node) * 10);
    head = p = n;
    size = 2;
    for (i = 0; i < size; i++) {
        p->val = t3[i];
        if ((i + 1) < size) {
            p->next = &n[i + 1];
            p = p->next;
        }
    }
    printlist(head);
    matchRemove3(&head, 2);
    printlist(head);
    printf("\n");
    
    // test case 4
    memset(&(n[0]), 0, sizeof(node) * 10);
    head = p = n;
    size = 4;
    for (i = 0; i < size; i++) {
        p->val = t4[i];
        if ((i + 1) < size) {
            p->next = &n[i + 1];
            p = p->next;
        }
    }
    printlist(head);
    matchRemove3(&head, 2);
    printlist(head);
    printf("\n");
    
    // test case 5
    memset(&(n[0]), 0, sizeof(node) * 10);
    head = p = n;
    size = 3;
    for (i = 0; i < size; i++) {
        p->val = t5[i];
        if ((i + 1) < size) {
            p->next = &n[i + 1];
            p = p->next;
        }
    }
    printlist(head);
    matchRemove3(&head, 2);
    printlist(head);
    printf("\n");
    
    
    // test case 6
    memset(&(n[0]), 0, sizeof(node) * 10);
    head = p = n;
    size = 8;
    for (i = 0; i < size; i++) {
        p->val = t6[i];
        if ((i + 1) < size) {
            p->next = &n[i + 1];
            p = p->next;
        }
    }
    printlist(head);
    matchRemove3(&head, 2);
    printlist(head);
    printf("\n");
    

    // test case 7
    memset(&(n[0]), 0, sizeof(node) * 10);
    head = p = n;
    size = 6;
    for (i = 0; i < size; i++) {
        p->val = t7[i];
        if ((i + 1) < size) {
            p->next = &n[i + 1];
            p = p->next;
        }
    }
    printlist(head);
    matchRemove3(&head, 2);
    printlist(head);
    printf("\n");
    
    
    // test case 8
    memset(&(n[0]), 0, sizeof(node) * 10);
    head = p = n;
    size = 1;
    for (i = 0; i < size; i++) {
        p->val = t8[i];
        if ((i + 1) < size) {
            p->next = &n[i + 1];
            p = p->next;
        }
    }
    printlist(head);
    matchRemove3(&head, 2);
    printlist(head);
    printf("\n");
    
    
    // test case 9
    memset(&(n[0]), 0, sizeof(node) * 10);
    head = p = n;
    size = 10;
    for (i = 0; i < size; i++) {
        p->val = t9[i];
        if ((i + 1) < size) {
            p->next = &n[i + 1];
            p = p->next;
        }
    }
    printlist(head);
    matchRemove3(&head, 2);
    printlist(head);
    printf("\n");
  

    //
    // Reverse linked list
    //
    memset(&(n[0]), 0, sizeof(node) * 10);
    head = p = n;
    size = 10;
    for (i = 0; i < size; i++) {
        p->val = t9[i];
        if ((i + 1) < size) {
            p->next = &n[i + 1];
            p = p->next;
        }
    }
    printf("\n\nReverse linked list\n\n");
    printlist(head);
    reverseList2(&head);
    printlist(head);



    memset(&(n[0]), 0, sizeof(node) * 10);
    head = p = n;
    size = 10;
    for (i = 0; i < size; i++) {
        p->val = t9[i];
        if ((i + 1) < size) {
            p->next = &n[i + 1];
            p = p->next;
        }
    }
    printf("\n\nReverse linked list 3\n\n");
    printlist(head);
    reverseList3(&head);
    printlist(head);



    // Reverse linked list partially
    memset(&(n[0]), 0, sizeof(node) * 10);
    head = p = n;
    size = 10;
    for (i = 0; i < size; i++) {
        p->val = t9[i];
        if ((i + 1) < size) {
            p->next = &n[i + 1];
            p = p->next;
        }
    }
    printf("\n\nReverse linked list partially, n = 5\n\n");
    printlist(head);
    reverseListPartial(&head, 5);
    printlist(head);


    // Reverse linked list partially
    memset(&(n[0]), 0, sizeof(node) * 10);
    head = p = n;
    size = 10;
    for (i = 0; i < size; i++) {
        p->val = t9[i];
        if ((i + 1) < size) {
            p->next = &n[i + 1];
            p = p->next;
        }
    }
    printf("\n\nReverse linked list partially, n = 10\n\n");
    printlist(head);
    reverseListPartial(&head, 10);
    printlist(head);


    // Reverse linked list partially
    memset(&(n[0]), 0, sizeof(node) * 10);
    head = p = n;
    size = 10;
    for (i = 0; i < size; i++) {
        p->val = t9[i];
        if ((i + 1) < size) {
            p->next = &n[i + 1];
            p = p->next;
        }
    }
    printf("\n\nReverse linked list partially, n = 0\n\n");
    printlist(head);
    reverseListPartial(&head, 0);
    printlist(head);


    // Reverse linked list partially
    memset(&(n[0]), 0, sizeof(node) * 10);
    head = p = n;
    size = 10;
    for (i = 0; i < size; i++) {
        p->val = t9[i];
        if ((i + 1) < size) {
            p->next = &n[i + 1];
            p = p->next;
        }
    }
    printf("\n\nReverse linked list partially, n = 11\n\n");
    printlist(head);
    reverseListPartial(&head, 11);
    printlist(head);


    // Reverse linked list partially, zero size list
    memset(&(n[0]), 0, sizeof(node) * 10);
    head = p = NULL;
    size = 0;   // zero size
    for (i = 0; i < size; i++) {
        // assign the pointer
        p = &n[i];
        // assign the value
        p->val = t1[i];

        // next item is not NULL only if the next index is less than size (C is zero based)
        if ((i + 1) < size) {
            // make link to the next item
            p->next = &n[i + 1];
        }
    }
    head = p;

    printf("\n\nReverse linked list partially, n = 0\n\n");
    printlist(head);
    reverseListPartial(&head, 0);
    printlist(head);


    // Reverse linked list partially, zero size list
    memset(&(n[0]), 0, sizeof(node) * 10);
    head = p = NULL;
    size = 0;   // zero size
    for (i = 0; i < size; i++) {
        // assign the pointer
        p = &n[i];
        // assign the value
        p->val = t1[i];

        // next item is not NULL only if the next index is less than size (C is zero based)
        if ((i + 1) < size) {
            // make link to the next item
            p->next = &n[i + 1];
        }
    }
    head = p;
    printf("\n\nReverse linked list partially, n = 5\n\n");
    printlist(head);
    reverseListPartial(&head, 5);
    printlist(head);





    //
    // remove a middle item, i.e. not first and not last
    //
    memset(&(n[0]), 0, sizeof(node) * 10);
    head = p = n;
    size = 10;
    for (i = 0; i < size; i++) {
        p->val = t9[i];
        if ((i + 1) < size) {
            p->next = &n[i + 1];
            p = p->next;
        }
    }
    printf("\n\nremove middle\n\n");
    printlist(head);
    removeMiddle(&head);
    printlist(head);

    // remove a middle item, i.e. not first and not last
    memset(&(n[0]), 0, sizeof(node) * 10);
    head = p = n;
    size = 1;
    for (i = 0; i < size; i++) {
        p->val = t9[i];
        if ((i + 1) < size) {
            p->next = &n[i + 1];
            p = p->next;
        }
    }
    printf("\n\nremove middle\n\n");
    printlist(head);
    removeMiddle(&head);
    printlist(head);

    // remove a middle item, i.e. not first and not last
    memset(&(n[0]), 0, sizeof(node) * 10);
    head = p = n;
    size = 2;
    for (i = 0; i < size; i++) {
        p->val = t9[i];
        if ((i + 1) < size) {
            p->next = &n[i + 1];
            p = p->next;
        }
    }
    printf("\n\nremove middle\n\n");
    printlist(head);
    removeMiddle(&head);
    printlist(head);

    // remove a middle item, i.e. not first and not last
    memset(&(n[0]), 0, sizeof(node) * 10);
    head = NULL ;
    printf("\n\nremove middle\n\n");
    printlist(head);
    removeMiddle(&head);
    printlist(head);

    //
    // remove a middle item, i.e. not first and not last
    //
    memset(&(n[0]), 0, sizeof(node) * 10);
    head = p = n;
    size = 10;
    for (i = 0; i < size; i++) {
        p->val = t9[i];
        if ((i + 1) < size) {
            p->next = &n[i + 1];
            p = p->next;
        }
    }
    printf("\n\nremove middle\n\n");
    printlist(head);
    removeMiddle3(&head);
    printlist(head);

    // remove a middle item, i.e. not first and not last
    memset(&(n[0]), 0, sizeof(node) * 10);
    head = p = n;
    size = 1;
    for (i = 0; i < size; i++) {
        p->val = t9[i];
        if ((i + 1) < size) {
            p->next = &n[i + 1];
            p = p->next;
        }
    }
    printf("\n\nremove middle\n\n");
    printlist(head);
    removeMiddle3(&head);
    printlist(head);

    // remove a middle item, i.e. not first and not last
    memset(&(n[0]), 0, sizeof(node) * 10);
    head = p = n;
    size = 2;
    for (i = 0; i < size; i++) {
        p->val = t9[i];
        if ((i + 1) < size) {
            p->next = &n[i + 1];
            p = p->next;
        }
    }
    printf("\n\nremove middle\n\n");
    printlist(head);
    removeMiddle3(&head);
    printlist(head);

    // remove a middle item, i.e. not first and not last
    memset(&(n[0]), 0, sizeof(node) * 10);
    head = NULL ;
    printf("\n\nremove middle\n\n");
    printlist(head);
    removeMiddle3(&head);
    printlist(head);
}
