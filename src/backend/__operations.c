/*
 * @ Author: Abdechahid Ihya
 * @ Create Time: 2021-12-21 00:42:51
 * @ Modified by: Abdechahid Ihya
 * @ Modified time: 2021-12-21 02:05:11
 */

#include "ctensor.h"

// TODO: implement multithreaded addition for __add and __bulk_add

// Adds 2 matrices together.
// If the dimentions of both matrices don't match, return NULL.
Tensor    *__add(Tensor mat1, Tensor mat2)
{
    pthread_t   tid;

    return (NULL);
}

// Adds multiple matrices and return a new matrix.
// If size is 1, return *bulk.
// If the dimentions of all matrices don't match, return NULL.
Tensor    *__bulk_add(size_t size, Tensor **bulk)
{
    Tensor    *result;
    int         i;

    if (size == 0)
        return (NULL);
    i = 0;
    result = bulk[i];
    while (++i < size)
    {
        result = __add(result, bulk[i])
    }
    return (result);
}