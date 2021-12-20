/*
 * @ Author: Abdechahid Ihya
 * @ Create Time: 2021-12-20 22:21:29
 * @ Modified by: Abdechahid Ihya
 * @ Modified time: 2021-12-21 00:30:43
 */

#include "mat.h"

size_t      __mult_dims(int ndims, int *dims)
{
    int     i;
    size_t  total;

    total = dims[0];
    i = 0;
    while (++i < ndims)
        total *= dims[i];
    return (total);
}

t_matrix    *__alloc_matrix(int ndims, va_list ap)
{
    t_matrix    *mat;
    int         i;

    if (ndims > MAX_NUM_ARGS || ndims <= 0)
        return (NULL);
    mat = (t_matrix *)malloc(sizeof(t_matrix));
    if (mat == NULL)
        return (NULL);
    mat->dims = (int *)malloc(sizeof(int) * ndims);
    if (mat->dims == NULL)
    {
        free(mat);
        return (NULL);
    }
    i = -1;
    while (++i < ndims)
        mat->dims[i] = va_arg(ap, int);
    mat->size = __mult_dims(ndims, mat->dims);
    mat->vect = (t_vector *)malloc(sizeof(int) * mat->size);
    if (mat->vect == NULL)
    {
        free(mat->dims);
        free(mat);
        return (NULL);
    }
    return (mat);
}

t_matrix    *matnd(int ndims, ...)
{
    t_matrix    *mat;
    va_list     ap;

    va_start(ap, ndims);
    mat = __alloc_matrix(ndims, ap);
    va_end(ap);
    return (mat);
}

t_matrix    *mat2d(int n, int m)
{
    return (matnd(2, n, m));
}
