#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#define MAXYEAR 2020

typedef struct Person {
    char name[20];
    int birth;
    int death;
    struct Person *next;

} Person;

Person people[] = {
    {"john", 1912, 1978},
    {"tom", 1912, 2010},
    {"jim", 1936, 1969},
    {"ken", 1945, 2111},
    {"larry", 1956, 1988},
    {"marry", 1961, 2016},
    {"hellen", 1892, 2001},
    {"jerry", 1899, 1956},
    {"derek", 1903, 1951},
    {"bob", 1887, 1944},
    {"alan", 1878, 1937},
    {"adam", 1961, 2009},
    {"brian", 1922, 1976},
    {"frank", 1902, 1981},
    {"terri", 1885, 1932},
    {"nancy", 1897, 1952},
    {"smile", 1922, 1991},
    {"queen", 1945, 2006},
    {"cathy", 1938, 1979},
    {"gin", 1965, 2016},
    {"vince", 1977, 1991},
    {"jane", 1958, 1983},
    {"leena", 1968, 2008},
    {"sandy", 1973, 1985},
    {"tin", 1964, 2010},
    {"keli", 1949, 1995},
    {"eric", 1953, 2011},
    {"winnie", 1974, 2016},
    {"yale", 1941, 1986},
    {"olla", 1957, 2002},
    {"gille", 1982, 2000},
    {"endoflist", -1, -1}
};

struct Peak {
    int year;
    int count;
    struct Peak *next;
};

typedef struct Peak Peak;

typedef struct queue {
    struct Person *head;
    struct Person *tail;
} Queue;

typedef struct stack {
    struct Person *top;
} Stack;

struct Peak *pList = NULL;

void deleteList(void)
{
    struct Peak *p, *next;

    p = pList;
    pList = NULL;
    while (p) {
        next = p->next;
        free(p);
        p = next;
    }
}

void addList(int y, int count)
{
    struct Peak *item;

    item = malloc(sizeof(struct Peak));
    item->year = y;
    item->count = count;
    item->next = pList;
    pList = item;
}

void initList(int year, int count)
{
    deleteList();
    addList(year, count);

}

void printList(void)
{
    struct Peak *p;

    p = pList;
    while (p) {
        printf("year: %d, population: %d\n", p->year, p->count);
        p = p->next;
    }
}

/*
 * add an item to the end of the queue
 */
void put(Queue *q, struct Person *item)
{
    if (!item)
        return;
    if (!q)
        return;

    if (!q->tail) {
        q->tail = item;
        q->head = item;
    } else {
        q->tail->next = item;
        q->tail = item;
    }
    item->next = NULL;
}

/*
 * get and remove an item from the head of the queue
 */
Person *get(Queue *q)
{
    Person *item;

    if (!q)
        return NULL;
    else
        item = q->head;

    if (q->head) {
        if (q->head == q->tail) {
            q->head = NULL;
            q->tail = NULL;
        } else {
            q->head = q->head->next;
        }
    }
    return item;
}

void printqueue(Queue *q)
{
    Person *p;

    printf("Queue:\n");
    p = q->head;
    while (p) {
        printf("%s %d %d\n", p->name, p->birth, p->death);
        p = p->next;
    }

    printf("\n");
}


/*
 * push an item to a stack, implement it as a simple linked list
 */
void push(Stack *s, struct Person *item)
{
    if (!item)
        return;

    if (!s)
        return;

    item->next = s->top;
    s->top = item;
}

/*
 * pop an item from a stack
 */
Person *pop(Stack *s)
{
    Person *item;

    if (!s)
        return NULL;
    item = s->top;
    if (s->top)
        s->top = s->top->next;

    return item;
}

void printstack(Stack *s)
{
    Person *p;

    if (!s)
        return;
    printf("Stack:\n");
    p = s->top;
    while (p) {
        printf("%s %d %d\n", p->name, p->birth, p->death);
        p = p->next;
    }
        
    printf("\n");
}


Stack s1;
Queue q1;

int main(void)
{
    int p, y, max;
    int population[MAXYEAR];
    Person *t, *tt;
 
    for (y = 0; y < MAXYEAR; y++)
        population[y] = 0;


    for (p = 0; people[p].birth != -1; p++) {
        printf("-- %s birth: %d death: %d\n", people[p].name, people[p].birth, people[p].death);
        for (y = people[p].birth; y <= people[p].death && y < MAXYEAR; y++) {
            population[y]++;
        }
    }


    max = 0;
    for (y = 0; y < MAXYEAR; y++) {
        if (population[y] > max) {
            max = population[y];
            initList(y, max);
        } else if (population[y] == max) {
            addList(y, max);
        }
    }

    printList();


    t = malloc(sizeof(Person));
    strcpy(t->name, "aa");
    t->birth = 1901;
    t->death = 1971;
    put(&q1, t);

    t = malloc(sizeof(Person));
    strcpy(t->name, "bb");
    t->birth = 1911;
    t->death = 1981;
    put(&q1, t);

    t = malloc(sizeof(Person));
    strcpy(t->name, "cc");
    t->birth = 1921;
    t->death = 1991;
    put(&q1, t);

    t = malloc(sizeof(Person));
    strcpy(t->name, "dd");
    t->birth = 1931;
    t->death = 1961;
    put(&q1, t);
    printqueue(&q1);

    printqueue(&q1);
    tt = get(&q1);
    if (tt)
        printf("get - %s %d %d\n", tt->name, tt->birth, tt->death);
    else
        printf("get - Null\n");

    tt = get(&q1);
    if (tt)
        printf("get - %s %d %d\n", tt->name, tt->birth, tt->death);
    else
        printf("get - Null\n");

    tt = get(&q1);
    if (tt)
        printf("get - %s %d %d\n", tt->name, tt->birth, tt->death);
    else
        printf("get - Null\n");

    printqueue(&q1);

    tt = get(&q1);
    if (tt)
        printf("get - %s %d %d\n", tt->name, tt->birth, tt->death);
    else
        printf("get - Null\n");
    tt = get(&q1);
    if (tt)
        printf("get - %s %d %d\n", tt->name, tt->birth, tt->death);
    else
        printf("get - Null\n");

    printqueue(&q1);

    if (tt)
        printf("get - %s %d %d\n", tt->name, tt->birth, tt->death);
    else
        printf("get - Null\n");


    t = malloc(sizeof(Person));
    strcpy(t->name, "ee");
    t->birth = 1905;
    t->death = 1955;
    push(&s1, t);

    t = malloc(sizeof(Person));
    strcpy(t->name, "ff");
    t->birth = 1915;
    t->death = 1965;
    push(&s1, t);

    t = malloc(sizeof(Person));
    strcpy(t->name, "gg");
    t->birth = 1925;
    t->death = 1995;
    push(&s1, t);

    t = malloc(sizeof(Person));
    strcpy(t->name, "hh");
    t->birth = 1935;
    t->death = 1985;
    push(&s1, t);

    printstack(&s1);

    tt = pop(&s1);
    if (tt)
        printf("pop - %s %d %d\n", tt->name, tt->birth, tt->death);
    else
        printf("pop - Null\n");
        
    tt = pop(&s1);
    if (tt)
        printf("pop - %s %d %d\n", tt->name, tt->birth, tt->death);
    else
        printf("pop - Null\n");
        
    tt = pop(&s1);
    if (tt)
        printf("pop - %s %d %d\n", tt->name, tt->birth, tt->death);
    else
        printf("pop - Null\n");
        
    printstack(&s1);

    tt = pop(&s1);
    if (tt)
        printf("pop - %s %d %d\n", tt->name, tt->birth, tt->death);
    else
        printf("pop - Null\n");
        
    tt = pop(&s1);
    if (tt)
        printf("pop - %s %d %d\n", tt->name, tt->birth, tt->death);
    else
        printf("pop - Null\n");
        
    printstack(&s1);
}
