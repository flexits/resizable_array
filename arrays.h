/*
    Custom resizable array type and related functions.
    Author: Alexander Korostelin 
    https://github.com/flexits
*/

#ifndef H_ARRAYS
#define H_ARRAYS

/// @brief Custom dynamic array type.
typedef struct array array_t;

/// @brief Allocates an array containing 
///        the given number of elements of the given size.
///        All the elements will be zeroes.
/// @param length Number of element in the array. Must be greater than 0.
/// @param elementSize Size of an element in bytes. Must be greater than 0.
/// @return Pointer to the allocated array or NULL on any error.
array_t* ArrayAllocate(unsigned int length, unsigned int elementSize);

/// @brief Change the array length. On increase the new elements
///        will be zeroes and the existing elements will be preserved.
///        On decrease, the excess elements from the array's end will be lost.
/// @param array Pointer to the array to change the length of.
/// @param newLength The length of the array to be set. Must be greater than 0.
/// @return The length of the array after resizing or 0 on any error.
unsigned int ArrayResize(array_t *array, unsigned int newLength);

/*
/// @brief Appends an element, increasing the array length.
///        The element size must match the size of the element in the array
///        specified on its allocation. 
/// @param array Pointer to the array to append the element to.
/// @param element Pointer to the element to append.
/// @return Index of the appended element in the array or 0 on an error.
unsigned int ArrayAppend(array_t *array, void *element);
*/

/// @brief Get an element of the array by its index.
///        Returns NULL in case of an error, including out of range.
/// @param array Pointer to the array to get the element from.
/// @param index Index of the element to get from the array (zero-based).
/// @return Pointer to the element or NULL on an error.
void* ArrayElementAt(const array_t *array, unsigned int index);

/// @brief Get the length of an array (number of elements in it).
/// @param array Pointer to the array to get the length of.
/// @return The length of the array or 0 if any error occurred.
unsigned int ArrayLength(const array_t *array);

/// @brief Get the size of an array element in bytes.
/// @param array Pointer to the array containing the elements.
/// @return The size of the element or 0 if any error occurred.
unsigned int ArraySizeofElement(const array_t *array);

/// @brief Get the pointer to the memory region 
///        containing the array elements. 
/// @param array Pointer to the custom array structure to get the data from.
/// @return Pointer to the first element of the array or NULL on an error.
void* ArrayExpose(const array_t *array);

/// @brief Set all the elements in the array to zeroes.
/// @param array Pointer to the array to set the elements of.
void ArrayClear(array_t *array);

/// @brief Shuffle the elements of the array (Fisher–Yates algorithm).
/// @param array Pointer to the array to shuffle the elements of.
void ArrayShuffle(array_t *array);

/// @brief Deallocate the memory used by the array itself and its elements.
/// @param array Pointer to the array to be destroyed. 
///         The behaviour is undefined if the memory is accessed through the
///         pointer after calling this function.
void ArrayDispose(array_t *array);

//void ArrayDispose(array_t **array);

#endif