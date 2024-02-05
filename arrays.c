/*
    Custom resizable array type and related functions.
    Author: Alexander Korostelin 
    https://github.com/flexits
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "arrays.h"

struct array {
    void *data;         // Pointer to the memory region to store the elements in.
    unsigned int elementSize;    // An element size in bytes.
    unsigned int length;         // The number of elements in the array.
};

array_t* ArrayAllocate(unsigned int length, unsigned int elementSize)
{ 
    if (length == 0 || elementSize == 0) return NULL;
    array_t *result = calloc(1, sizeof(array_t));
    if (!result) return NULL;
    result->data = calloc(length, elementSize);
    if (!result->data) return NULL;
    result->elementSize = elementSize;
    result->length = length;
    return result;
}

unsigned int ArrayResize(array_t *array, unsigned int newLength)
{
    if (newLength == 0 || !array) return 0;
    if (newLength == array->length) return newLength;
    void *newData = realloc(array->data, newLength * array->elementSize);
    if (!newData) return 0;
    array->data = newData;
    // set new elements to 0 if any
    if (newLength > array->length)
    {
        int newElementIndex = array->length;
        int newElementsCount = newLength - array->length;
        void *newElement = (unsigned char *)(array->data) + newElementIndex * array->elementSize;
        memset(newElement, 0, array->elementSize * newElementsCount);
    }
    array->length = newLength;
    return newLength;
}

void* ArrayElementAt(const array_t *array, unsigned int index)
{
    if (!array || !array->data) return NULL;
    if (index > array->length) return NULL;
    return (unsigned char *)(array->data) + index * array->elementSize;
}

unsigned int ArrayLength(const array_t *array)
{
    return array ? array->length : 0;
}

unsigned int ArraySizeofElement(const array_t *array)
{
    return array ? array->elementSize : 0;
}

void* ArrayExpose(const array_t *array)
{
    return array ? array->data : NULL;
}

void ArrayClear(array_t *array)
{
    if (!array) return;
    if (array->data)
    {
        memset(array->data, 0, array->elementSize * array->length);
    }
    else
    {
        array->data = calloc(array->length, array->elementSize);
    }
}

void ArrayShuffle(array_t *array)
{
    if (!array) return;
    void *temp = calloc(1, array->elementSize);    
    int charsInElement = array->elementSize / sizeof(unsigned char);
    srand(time(NULL));
    int j = 0;
    // Fisher–Yates shuffle
    for (int i = 0; i < array->length - 2; i++)
    {
        // random integer such that i ≤ j < n
        j = i + rand() % (array->length - i);
        // exchange a[i] and a[j]
        void *arr_i = (unsigned char *)(array->data) + i * array->elementSize;
        void *arr_j = (unsigned char *)(array->data) + j * array->elementSize;
        memcpy(temp, arr_i, charsInElement);
        memcpy(arr_i, arr_j, charsInElement);
        memcpy(arr_j, temp, charsInElement);
    }
}

/*void ArrayDispose(array_t **array)
{
    if (!array || !(*array)) return;
    if ((*array)->data) free((*array)->data);
    free(*array);
    *array = NULL;
}*/

void ArrayDispose(array_t *array)
{
    if (!array) return;
    if (array->data) free(array->data);
    free(array);
}
