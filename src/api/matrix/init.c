/**
 * File              : init.c
 * Author            : Abdechahid Ihya <abdechahid.ihya@hotmail.com>
 * Date              : 25.02.2022
 * Last Modified Date: 25.02.2022
 * Last Modified By  : Abdechahid Ihya <abdechahid.ihya@hotmail.com>
 */

#include "ctensor.h"

Tensor    *matrix(int n, int m)
{
    return (tensor(2, n, m));
}
