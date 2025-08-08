#include <stdio.h>
#include <stdlib.h>


void display();

int main(void)
{
    void (*ptr)();
    char *y[];



    ptr = &display;
    (*ptr)();
}

void display()
{
    printf("hello world\n");
}
