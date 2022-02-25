/**
 * File              : __alloc.c
 * Author            : Abdechahid Ihya <abdechahid.ihya@hotmail.com>
 * Date              : 25.02.2022
 * Last Modified Date: 25.02.2022
 * Last Modified By  : Abdechahid Ihya <abdechahid.ihya@hotmail.com>
 */

#include "ctensor.h"

/* Multiply the dimentions all together.
 * Mainly used for allocation purposes to get the tensors vector size.
 */
size_t      __array_size(int nd, int *shape)
{
    int     i;
    size_t  size;

    size = shape[0];
    i = 0;
    while (++i < ndims)
        size *= shape[i];
    return (size);
}

/* Creates a tensor.
 * If allocation fails at any point, return NULL.
 */
Tensor *__alloc_tensor(int ndims, va_list ap)
{
    Tensor	*tensor;
    int		i;

	// Check if number of arguments is within the proper window
    if (ndims > MAX_NUM_ARGS || ndims <= 0)
        return (NULL);

	// Allocate tensor memory
    tensor = (Tensor *)malloc(sizeof(Tensor));
    if (tensor == NULL)
        return (NULL);

	// Allocate shape memory
    tensor->shape = (int *)malloc(sizeof(int) * ndims);
    if (tensor->shape == NULL)
    {
        free(tensor);
        return (NULL);
    }

	// Fill the shape array with ap content
    i = -1;
    while (++i < ndims)
        tensor->shape[i] = va_arg(ap, int);

    tensor->size = __mult_dims(ndims, tensor->shape);
    tensor->array = malloc(sizeof(int) * tensor->size);
    if (tensor->array == NULL)
    {
        free(tensor->dims);
        free(tensor);
        return (NULL);
    }
    return (tensor);
}

