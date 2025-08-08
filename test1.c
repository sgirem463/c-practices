#include <stdio.h>
void * display();
int main()
{
    int x[] = {1,2,3,4,5};
    int *ptr, i;
    ptr = x;
    for(i=0;i<5;i++) {
        printf("\nAddress : %d", (int) &x[i]);
        printf("\nElement : %d", x[i]);
        printf("\nElement : %u", *(x+i));
        printf("\nElement : %d", i[x]);
        printf("\nElement : %d", *ptr);
    }  
    printf("\n");



    char *arr[4] = {"C","C++","Java","VBA"};
    char *(*ptr2)[4] = &arr;

    printf("%s\n",++(*ptr2)[2]);


    void *(*ptr3)();
    ptr3 = &display;
    (*ptr3)();

    /* array of pointers to function */
    void (*arr11[])()

    // pointer to array of pointers to function
    void (*(*ptr11[]))()
    void *(*ptr11[])() // still array of pointer to function

    /* pointer to array of functions, doesn't make sense */
    void (*ptr4)()[]
    void (*ptr4)[]()











    return 0;
}

void * display()
{
    printf("Hello World\n");
    return (void *) 0;
}
