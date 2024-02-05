#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include "arrays.h"

void ArrayPrint(const array_t *array)
{
    unsigned int length = ArrayLength(array);
    printf("Array length = %d; elementSize = %d\r\n", 
        length, ArraySizeofElement(array));
    for (int i = 0; i < length; i++)
    {
        int element = *(int*)ArrayElementAt(array, i);
        printf("Array[%d] = %d\r\n", i, element);
    }
}

int main()
{
    printf("Hello!\r\n");
    array_t *arrInt_Test = ArrayAllocate(7, sizeof(int));
    if (arrInt_Test)
    {
        ArrayPrint(arrInt_Test);
        *(int*)ArrayElementAt(arrInt_Test, 0) = 11;
        *(int*)ArrayElementAt(arrInt_Test, 1) = 12;
        *(int*)ArrayElementAt(arrInt_Test, 2) = 13;
        *(int*)ArrayElementAt(arrInt_Test, 3) = 14;
        *(int*)ArrayElementAt(arrInt_Test, 4) = 15;
        *(int*)ArrayElementAt(arrInt_Test, 5) = 16;
        *(int*)ArrayElementAt(arrInt_Test, 6) = 17;
        *(int*)ArrayElementAt(arrInt_Test, 7) = 18;
        ArrayPrint(arrInt_Test);
        ArrayShuffle(arrInt_Test);
        ArrayPrint(arrInt_Test);
        /*int *array = ArrayExpose(arrInt_Test);
        printf("0 %d\r\n", array[0]);
        printf("1 %d\r\n", array[1]);
        printf("2 %d\r\n", array[2]);
        printf("3 %d\r\n", array[3]);
        printf("4 %d\r\n", array[4]);
        printf("5 %d\r\n", array[5]);
        printf("6 %d\r\n", array[6]);
        ArrayClear(arrInt_Test);
        ArrayPrint(arrInt_Test);*/
        printf("Expand to 10\r\n");
        ArrayResize(arrInt_Test, 10);
        ArrayPrint(arrInt_Test);
        printf("Shrink to 5\r\n");
        ArrayResize(arrInt_Test, 5);
        ArrayPrint(arrInt_Test);
        printf("Expand to 10\r\n");
        ArrayResize(arrInt_Test, 10);
        ArrayPrint(arrInt_Test);
        ArrayDispose(arrInt_Test);
        return 1;
    }
}