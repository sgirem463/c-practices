


void reverseList(int *head)
{
    int *p, *q, *r;

    p = NULL;    // head of the reverse list
    q = head;    // head of the original list
    r = NULL;    // q->next

    while (q) {
        r = q->next;
        q->next = p;
        p = q;
        q = r;
    }
}



void delink(int head, int value)
{

    int *p, *q, *r, *h;

    p = head;    // current head
    h = NULL     //the new head
    prev = NULL;


    while (p)

        if (p->value == value) {
                        
            if (prev)
                prev->next = p->next;
        } else {
            if (!h)
                h = p;   // set once only

            prev = p;
        }

        p = p->next;
    }

    return h;

}



void reverseWord (char *s)
{
    char *p = s;
    char word[100];

    while (p) {
         if (*p == ' ') {
             p++;
             printf("%s", " "
             continue;
         }

         i = 0
         while (*p != ' ')
             word[i++] = *p++;
         for (j = i - 1; j >= 0; j--)
             printf("%s", word[j]);
        
    }

}
