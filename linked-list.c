



struct node {
    int value;
    struct node *next
}


void reverse(struct node **list, int n)
{
    struct node *head, *prev, *next, *tmp, *curret;



    current = *list;
    head = *list;
    prev = NULL;
    next = NULL;

    while (current && --n) {

        if (prev == NULL) {

            next = current->next;
            current->next = prev;
            prev = current;
            current = next;

        } else {

            curre


        }

    }

    if (n > 0)
        *list = NULL;
        // return NULL;

    *list = prev;
    head->next = current;


}

