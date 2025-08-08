//
//  main.c
//  linked list
//
//  Created by alue on 10/1/14.
//  Copyright (c) 2014 alue. All rights reserved.
//

#include <stdio.h>
#include <memory.h>


typedef struct n {
    int val;
    struct n *next;
} node;



void matchRemove(node **head, int v) {
    
    node *p, *prev;
    p = *head;
    
    /*
     
     if (p == NULL)
     return;
     
     
     // find the first item (head) not equal to v
     while (p->val == v) {
     
         // if p is not the last item, move *head and p to point to the next item
         *head = p = p->next;
         if (p == NULL)
         return;
     }
     
     */
    
    /*
     
     // find the first item (head) not equal to v
     while (p) {
         if (p->val == v) {
             *head = p = p->next;
         } else {
             break;
         }
     }
     
     // There are two cases to exit the previous loop, check for the NULL case
     if (p == NULL)
     return;
     
     
     // head (the first item) won't change after this point
     // and the first node is not NULL and its val is not v
     prev = p;
     p = p->next;
     while (p) {
     if (p->val == v) {
     // unlink *p
     prev->next = p->next;
     p = p->next;
     } else {
     // both prev and p move down one position
     prev = p;
     p = p->next;
     }
     }
     
     */
    
    *head = NULL;
    prev = NULL;
    
    // Single loop, work on setting of *head and prev later, seems more natural
    while (p) { // while (p) is always coupled with p = p->next
        if (p->val == v) {
            if (prev)
                prev->next = p->next;
        } else {
            if (!(*head))
                *head = p;  // head is only set 1 time
            prev = p;       // prev is set whenever the current node doesn't have "val",
        }                   // i.e. whenever it won't be removed
        p = p->next;
    }
}


void matchRemove2(node **head, int v)
{
    node *p = NULL;   // previous item
    node *q = *head;  // current item, starting from head
    node *h = NULL;   // head
    p = q;
    
    while (q) {
        if (q->val == v) {
            if (p)
                p->next = q->next;  // unlink q from the list
        }
        else
        {
            if (!h)
                h = q; // h is set only once
            p = q;   // p will be moving alng wirh q
        }
        q = q->next;
    }
    *head = h;
}



void printlist(node *p) {
    while (p) {
        printf("%d ->", p->val);
        p = p->next;
    }
    printf("NULL\n");
}

void reverseList(node **head){
    node *p, *q, *r;
    
    q = *head;
    
    /*
     // no point for reversing 0 or 1 item
     if ((q == NULL) || (q->next == NULL))
     return;
     */
    
    p = NULL;
    r = NULL;
    while (q) {
        // q->next needs to be reversed, save it first
        r = q->next;
        
        // reverse it
        q->next = p;
        
        // move down the list, indeed *head = q here
        p = q;
        q = r;
    }
    *head = p;
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
    int t9[10] = {2, 3, 6, 2, 2, 4, 2, 9, 5, 2};
    
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
    
    
    // Reverse linked list
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
    reverseList(&head);
    printlist(head);
}



