/*
 * @ Author: Abdechahid Ihya
 * @ Create Time: 2021-12-21 00:35:58
 * @ Modified by: Abdechahid Ihya
 * @ Modified time: 2021-12-21 00:47:38
 */

#include "cmatrix.h"

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

t_matrix    *__alloc_matnd(int ndims, va_list ap)
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
    mat->vect = malloc(sizeof(int) * mat->size);
    if (mat->vect == NULL)
    {
        free(mat->dims);
        free(mat);
        return (NULL);
    }
    return (mat);
}
