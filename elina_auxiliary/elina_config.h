/*
 *
 *  This source file is part of ELINA (ETH LIbrary for Numerical Analysis).
 *  ELINA is Copyright © 2021 Department of Computer Science, ETH Zurich
 *  This software is distributed under GNU Lesser General Public License Version 3.0.
 *  For more information, see the ELINA project website at:
 *  http://elina.ethz.ch
 *
 *  THE SOFTWARE IS PROVIDED "AS-IS" WITHOUT ANY WARRANTY OF ANY KIND, EITHER
 *  EXPRESS, IMPLIED OR STATUTORY, INCLUDING BUT NOT LIMITED TO ANY WARRANTY
 *  THAT THE SOFTWARE WILL CONFORM TO SPECIFICATIONS OR BE ERROR-FREE AND ANY
 *  IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE,
 *  TITLE, OR NON-INFRINGEMENT.  IN NO EVENT SHALL ETH ZURICH BE LIABLE FOR ANY     
 *  DAMAGES, INCLUDING BUT NOT LIMITED TO DIRECT, INDIRECT,
 *  SPECIAL OR CONSEQUENTIAL DAMAGES, ARISING OUT OF, RESULTING FROM, OR IN
 *  ANY WAY CONNECTED WITH THIS SOFTWARE (WHETHER OR NOT BASED UPON WARRANTY,
 *  CONTRACT, TORT OR OTHERWISE).
 *
 */


/* ************************************************************************* */
/* elina_config.h */
/* ************************************************************************* */

#ifndef _ELINA_CONFIG_H_
#define _ELINA_CONFIG_H_

#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Append to the string and return the amount of appended characters, excluding
 * the null terminating byte.
 */
static inline size_t string_append(char *str, size_t remaining_sz, const char *fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    size_t result = vsnprintf(str, remaining_sz, fmt, ap);
    va_end(ap);

    if (result < remaining_sz)
        return result;
    else if (remaining_sz > 0)
        return remaining_sz - 1;
    else
        return 0;
}

#ifdef __cplusplus
extern "C" {
#else
#include <stdbool.h>
#endif

#if !(defined __USE_SVID || defined __USE_BSD || defined __USE_XOPEN_EXTENDED || defined __APPLE__ || defined __CYGWIN__)

#endif

#ifdef __cplusplus
}
#endif

#endif
