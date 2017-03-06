/*
 * BSD 2-clause "Simplified" License
 *
 * Copyright (c) 2017, Lans Zhang <jia.zhang@windriver.com>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * * Redistributions of source code must retain the above copyright notice, this
 *   list of conditions and the following disclaimer.
 *
 * * Redistributions in binary form must reproduce the above copyright notice,
 *   this list of conditions and the following disclaimer in the documentation
 *   and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef BASE_LIBRARY_H
#define BASE_LIBRARY_H

#include <Efi.h>

/* Threshold used to decide to use short byte/word copy or dword/qword copy. */
#define THRESHOLD_SHORT_COPY		(sizeof(long) * 64)

/* Threshold used to decide to go entire or parital reverse memcpy. */
#define THRESHOLD_REVERSE_MEMCPY	(sizeof(long) * 16)

#define UNALIGNED(p)	(((unsigned long)(p)) % __alignof__ (unsigned long))

VOID *
MemCpy(VOID *Destination, CONST VOID *Source, UINTN MaxLength);

VOID *
MemMove(VOID *Destination, CONST VOID *Source, UINTN MaxLength);

VOID *
MemSet(VOID *Destination, UINT8 Value, UINTN Length);

VOID *
MemDup(VOID *Source, UINTN Length);

#ifndef GNU_EFI
CHAR16 *
StrCpy(CHAR16 *Destination, CONST CHAR16 *Source);

UINTN
StrLen(CONST CHAR16 *String);
#endif

CHAR16 *
StrnCpy(CHAR16 *Destination, CONST CHAR16 *Source, UINTN MaxLength);

UINTN
StrnLen(CONST CHAR16 *String, UINTN MaxLength);

CHAR16 *
StrStr(CONST CHAR16 *String, CONST CHAR16 *SearchString);

CHAR16 *
StrChr(CONST CHAR16 *String, CHAR16 SearchChar);

CHAR16 *
StrChr(CONST CHAR16 *String, CHAR16 SearchChar);

CHAR16 *
StrnChr(CONST CHAR16 *String, UINTN MaxLength, CHAR16 SearchChar);

CHAR16 *
StrrChr(CONST CHAR16 *String, CHAR16 SearchChar);

INTN
StrCmp(CONST CHAR16 *FirstString, CONST CHAR16 *SecondString);

INTN
StrCaseCmp(CONST CHAR16 *FirstString, CONST CHAR16 *SecondString,
	   UINTN MaxLength);

CHAR16 *
StrDup(CONST CHAR16 *String);

CHAR16 *
StrAppend(CONST CHAR16 *Source, CONST CHAR16 *Suffix);

#endif	/* BASE_LIBRARY_H */
