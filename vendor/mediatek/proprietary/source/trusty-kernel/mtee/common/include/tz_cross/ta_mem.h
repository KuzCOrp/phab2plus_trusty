/*
* Copyright (c) 2015 MediaTek Inc.
*
* Permission is hereby granted, free of charge, to any person obtaining
* a copy of this software and associated documentation files
* (the "Software"), to deal in the Software without restriction,
* including without limitation the rights to use, copy, modify, merge,
* publish, distribute, sublicense, and/or sell copies of the Software,
* and to permit persons to whom the Software is furnished to do so,
* subject to the following conditions:
*
* The above copyright notice and this permission notice shall be
* included in all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

/** Commands for TA memory **/

#ifndef __TRUSTZONE_TA_MEM__
#define __TRUSTZONE_TA_MEM__

#define TZ_TA_MEM_UUID   "4477588a-8476-11e2-ad15-e41f1390d676"

/* Command for Secure Memory Management */
#define TZCMD_MEM_SHAREDMEM_REG       0
#define TZCMD_MEM_SHAREDMEM_UNREG     1
#define TZCMD_MEM_SECUREMEM_ALLOC     2
#define TZCMD_MEM_SECUREMEM_REF       3
#define TZCMD_MEM_SECUREMEM_UNREF     4
#define TZCMD_MEM_SECURECM_ALLOC      5
#define TZCMD_MEM_SECURECM_REF        6
#define TZCMD_MEM_SECURECM_UNREF      7
#define TZCMD_MEM_SECURECM_RELEASE    8
#define TZCMD_MEM_SECURECM_APPEND     9
#define TZCMD_MEM_SECURECM_READ      10
#define TZCMD_MEM_SECURECM_WRITE     11
#define TZCMD_MEM_SECURECM_RSIZE     12
#define TZCMD_MEM_TOTAL_SIZE         13
#define TZCMD_MEM_SECUREMEM_ZALLOC   14
#define TZCMD_MEM_SECURECM_ZALLOC    15

#endif /* __TRUSTZONE_TA_MEM__ */
