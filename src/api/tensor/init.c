/**
 * File              : init.c
 * Author            : Abdechahid Ihya <abdechahid.ihya@hotmail.com>
 * Date              : 25.02.2022
 * Last Modified Date: 25.02.2022
 * Last Modified By  : Abdechahid Ihya <abdechahid.ihya@hotmail.com>
 */

#include "ctensor.h"

Tensor *tensor(int ndims, ...)
{
	Tensor	*_tensor;
	va_list	ap;

	va_start(ap, ndims);
	_tensor = __alloc_tensor(ndims, ap);
	va_end(ap);
	return (_tensor);
}
