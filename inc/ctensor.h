/**
 * File              : ctensor.h
 * Author            : Abdechahid Ihya <abdechahid.ihya@hotmail.com>
 * Date              : 25.02.2022
 * Last Modified Date: 25.02.2022
 * Last Modified By  : Abdechahid Ihya <abdechahid.ihya@hotmail.com>
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
# include <emmintrin.h>

# define MAX_NUM_ARGS 5
# define THREADS_CAP 4

union u_datatype
{
	int    dt_int;
	float  dt_float;
	double dt_double;
} t_dt;

typedef struct s_array
{
	void   *array;
	size_t size;
} t_array;

typedef struct s_tensor
{
    unsigned int *shape;
	t_array      array;
} Tensor;

// Backend functions
Tensor *__alloc_tensor(int ndims, va_list ap);

// Api functions
Tensor *tensor(int ndims, ...)

#endif
