/*
 * @ Author: Abdechahid Ihya
 * @ Create Time: 2021-12-20 22:23:40
 * @ Modified by: Abdechahid Ihya
 * @ Modified time: 2021-12-21 00:46:51
 */

#ifndef ARRAY_H
# define ARRAY_H

# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include <limits.h>
# include <assert.h>
# include <errno.h>

# define MAX_NUM_ARGS 5

typedef enum    e_datatype
{
    INT,
    FLOAT,
    DOUBLE,
}               t_datatype;

typedef struct  s_matrix
{
    size_t      size;
    int         *dims;
    void        *vect;
}               t_matrix;

// t_vector    *__alloc_vector(size_t vect_size);
t_matrix    *__alloc_matnd(int ndims, va_list ap);


#endif