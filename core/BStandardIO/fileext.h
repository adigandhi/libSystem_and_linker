/*	$OpenBSD: fileext.h,v 1.2 2005/06/17 20:40:32 espie Exp $	*/
/* $NetBSD: fileext.h,v 1.5 2003/07/18 21:46:41 nathanw Exp $ */

/*-
 * Copyright (c)2001 Citrus Project,
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 * $Citrus$
 */

/*
 * DARWIN
 * file extension
 */

/* hold a buncha junk that would grow the ABI */
struct __sFILEX {
	unsigned char	*_up;	/* saved _p when _p is doing ungetc data */
	struct wchar_io_data _wcio; /* wide stuff, unused */
	
	int		fl_count;	/* recursive lock count */
	int		orientation;	/* orientation for fwide() */
	int	mbstate;	/* multibyte conversion state */
};

/* glue */
#define	__sFXInit3	{0, {0}, 0, 0, 0}

#define __sfileext __sFILEX

#define _EXT(fp) ((struct __sfileext *)((fp)->_extra))
#define _UB(fp) fp->_ub

#define _FILEEXT_INIT(fp) \
do { \
	_UB(fp)._base = NULL; \
	_UB(fp)._size = 0; \
	WCIO_INIT(fp); \
} while (0)

#define _FILEEXT_SETUP(f, fext) \
do { \
	(f)->_extra = (struct __sFILEX*)(fext); \
	_FILEEXT_INIT(f); \
} while (0)
