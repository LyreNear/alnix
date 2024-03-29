#ifndef _INCLUDE_VARGS_H_
#define _INCLUDE_VARGS_H_

typedef __builtin_va_list va_list;

#define va_start(ap, last) (__builtin_va_start(ap, last))
#define va_arg(ap, type) (__builtin_va_arg(ap, type))
#define va_end(ap)

#endif // _INCLUDE_VARGS_H_

