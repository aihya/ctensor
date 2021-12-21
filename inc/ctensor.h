/*
 * @ Author: Abdechahid Ihya
 * @ Create Time: 2021-12-20 22:23:40
 * @ Modified by: Abdechahid Ihya
 * @ Modified time: 2021-12-21 02:12:09
 */

#ifndef ARRAY_H
# define ARRAY_H

# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include <limits.h>
# include <assert.h>
# include <errno.h>
# include <pthread.h>

# define MAX_NUM_ARGS 5
# define THREADS_CAP 4

typedef enum    e_dtype
{
    INT,
    FLOAT,
    DOUBLE,
}               t_dtype;

typedef struct  s_tensor
{
    size_t      size;
    int         *dims;
    void        *vect;
}               Tensor;

// t_vector    *__alloc_vector(size_t vect_size);
Tensor    *__alloc_tensor(int ndims, va_list ap);


#endif