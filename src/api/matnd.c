/*
 * @ Author: Abdechahid Ihya
 * @ Create Time: 2021-12-20 22:21:29
 * @ Modified by: Abdechahid Ihya
 * @ Modified time: 2021-12-21 01:02:16
 */

#include "cmatrix.h"

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
