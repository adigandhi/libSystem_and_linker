/*
 * Copyright (c) 2007 Apple Inc. All rights reserved.
 *
 * @APPLE_LICENSE_HEADER_START@
 *
 * This file contains Original Code and/or Modifications of Original Code
 * as defined in and that are subject to the Apple Public Source License
 * Version 2.0 (the 'License'). You may not use this file except in
 * compliance with the License. Please obtain a copy of the License at
 * http://www.opensource.apple.com/apsl/ and read it before using this
 * file.
 *
 * The Original Code and all software distributed under the License are
 * distributed on an 'AS IS' basis, WITHOUT WARRANTY OF ANY KIND, EITHER
 * EXPRESS OR IMPLIED, AND APPLE HEREBY DISCLAIMS ALL SUCH WARRANTIES,
 * INCLUDING WITHOUT LIMITATION, ANY WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, QUIET ENJOYMENT OR NON-INFRINGEMENT.
 * Please see the License for the specific language governing rights and
 * limitations under the License.
 *
 * @APPLE_LICENSE_HEADER_END@
 */

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <limits.h>

extern void __chk_fail (void) __attribute__((__noreturn__));
extern int __vsnprintf_chk (char * __restrict, size_t, int, size_t,
                            const char * __restrict, va_list arg)
  __DARWIN_LDBL_COMPAT (__vsnprintf_chk);

#undef vsnprintf

int
__vsnprintf_chk (char *s, size_t maxlen, int flags, size_t len,
		const char *format, va_list arg)
{
  int done;

  if (maxlen > len)
    __chk_fail ();

  done = vsnprintf (s, maxlen, format, arg);

  return done;
}
