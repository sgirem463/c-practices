#include<stdio.h>

void display();

int main()
{
    void *(*ptr)();
    ptr = &display;
    (*ptr)();

    return(0);
}

void display()
{
    printf("Hello World");
}
