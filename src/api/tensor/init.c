/*
 * @ Author: Abdechahid Ihya
 * @ Create Time: 2021-12-21 02:22:15
 * @ Modified by: Abdechahid Ihya
 * @ Modified time: 2021-12-21 02:22:35
 */

#include "ctensor.h"

Tensor    *tensor(int ndims, ...)
{
    Tensor    *mat;
    va_list     ap;

    va_start(ap, ndims);
    mat = __alloc_tensor(ndims, ap);
    va_end(ap);
    return (mat);
}
