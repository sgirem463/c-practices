#include <stdio.h>



void shiftNumber(int list[], int size, int n)
{
    int i, j, tmp;

    for (i = 1; i <= n; i++) {
        tmp = list[size - 1];
        for (j = size - 1; j > 0; j--) {
            list[j] = list[j-1];
            // printf("= %d %d\n", j, list[j]);
        }
        list[0] = tmp;
    }
}

// {1,2,3,4,5,6,7,8,9}
// shift = 4, size = 9
// ci = 0
// ni = (ci + 4) % 9 = 4
// tmp = L[ni] =  L[4] = 5
// L[ni] = L[4] == L[ci] = L[0] = 1
// ci = ni = 4
// ni = (ci + 4) % 9 = 8
// tmp2 = tmp = 5
// L[8] = tmp2 = 5
// ci = 8
// ni = (8 + 4) % 9 = 3
//
//
// tmp = L[3]
// L[3] = L[8]
// 
// {1,2,3,9,5,6,7,8,9}
//
//
// {6,7,8,9,1,2,3,4,5}
//
// ni = (ci + n) % size

// {8,9,1,2,3,4,5,6,7}


void shiftNumber2(int list[], int size, int n)
{
    int i, ci, ni, tmp, pci, tmp2;
    tmp2 = -1;

    // ni = (ci + n) % size
    for (i = 0, ci = 0 ; i < size; i++) { // do this "size" times
        ni = (ci + n) % size;
        tmp = list[ni];
        if (i > 0)
            list[ni] = tmp2;
        else
            list[ni] = list[ci];
        tmp2 = tmp;
        ci = ni;
        
    }
}



void shiftNumber4(int list[], int size, int n)
{   
    int i, ci, ni, tmp, pci, tmp2;
    tmp2 = -1;
    
    // ni = (ci + n) % size
    for (i = 0, ci = 0 ; i < size; i++) { // do this "size" times
        ni = (ci + n) % size;
        tmp = list[ni];
        list[ni] = tmp

        // the value in the new position is save in tmp
        // before tmp is used/saved, tmp cannot be assigned a new value
        ci = ni;
    }
}


void shiftNumber5(int list[], int size, int n)
{   
    int i, ci, ni, tmp, pci, tmp2;
    tmp2 = -1;
    
    // ni = (ci + n) % size
    for (i = 0, ci = 0 ; i < size; i++) { // do this "size" times
        ni = (ci + n) % size;
        tmp = list[ni];
        list[ni] = tmp

        // the value in the new position is save in tmp
        // before tmp is used/saved, tmp cannot be assigned a new value
        ci = ni;
    }
}





void shiftNumber3(int list[], int size, int n)
{
    int i, j, ci, ni, tmp, pci, tmp2, firstFlag;
    tmp2 = -1;

    // ni = (ci + n) % size
    for (i = 0, ci = 0, firstFlag = 1 ; i < size; i++) { // do this "size" times
        ni = (ci + n) % size; // calculate the next index for the current item
        tmp = list[ni]; // save the item at the next index so it would be overridden
        if (firstFlag){
            printf("move %d to position %d, tmp:%d\n", list[ci], ni, tmp);
            list[ni] = list[ci]; // move the current item to its future location/index
            firstFlag = 0;
        } else {
            printf("move %d to position %d, tmp:%d\n", list[pci], ni, tmp);
            list[ni] = list[pci]; // move the current item to its future location/index
        }
        if (i == (size - 1))
            break;

        list[ci] = tmp;

        for (j = 0; j < size; j++)
            printf("%d ", list[j]);
        printf("\n");
        printf("\n");

        pci = ci;
        ci = ni; // the next index becomes the current index
                 // but tmp is still not saved, so if we go ahead to calculate the
                 // next location and assigned it to tmp, data is overridden
                 // maybe save it to the previous ci is a better idea
           
    }
}




int main(void)
{

    int i, j;

    int numbers[] = {1,2,3,4,5,6,7,8,9};

    for (i = 0; i < 9; i++)
        printf("%d ", numbers[i]);
    printf("\n");
    printf("\n");

    shiftNumber2(numbers, 9, 4);

    for (i = 0; i < 9; i++)
        printf("%d ", numbers[i]);
    printf("\n");
    printf("\n");


    for (i = 10; i > 0; i--)
        printf("%d ", i);
    printf("\n");


}
