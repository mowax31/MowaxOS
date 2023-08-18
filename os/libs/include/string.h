#ifndef _STRING_H
#define _STRING_H 1

#include "stddef.h"

int memorycmp(const void *aptr, const void *bptr, size_t size);
void *memoryset(void *bufptr, int value, size_t size);
size_t stringlen(const char*);
char *stringcat(char *dest, const char *src);
char *stringcpy(char *d, const char *s);
int stringncmp(const char *s1, const char *s2);
char *stringncat(char *dest, const char *src, size_t n);
char *stringncpy(char *dest, const char *src, size_t n);
char stringstr(char *s1, const char *s2);
char stringchar(const char *s, int c);
int stringcmp(const char *s1, const char *s2, size_t n);
char *ctos(char s[2], const char c);

#endif
