#ifndef __INCLUDE_STRING_H__
#define __INCLUDE_STRING_H__

#include "types.h"

static inline void memcpy(uint8_t *dest, const u_int8_t *src, u_int32_t len) {
    for ( ; len != 0; len--) {
        *dest++ = *src++;
    }
}

static inline void memset(void *dest, u_int8_t val, uint32_t len) {
    uint8_t *dst = (uint8_t *)dest;

    for ( ; len != 0; len--) {
        *dst++ = val;
    }
}

static inline void bzero(void *dest, uint32_t len) {
    memset(dest, 0, len);
}

static inline char *strcpy(char *dest, const char *src) {
    char *tmp = dest;

    while (*src) {
        *dest++ = *src++;
    }

    *dest = '\0';

    return tmp;
}

static inline char *strcat(char *dest, const char *src) {
    char *cp = dest;

    while (*cp) {
        cp++;
    }

    while ((*cp++ = *src++))
        ;

    return dest;
}

static inline int strlen(const char *src) {
    const char *eos = src;

    while (*eos++)
        ;

    return (eos - src - 1);
}

#endif // __INCLUDE_STRING_H__
