#include "../include/string.h"

char *stringstr(char *s1, const char *s2){
	size_t n = stringlen(s2);
	while (*s1) {
	if (!memorycmp(s1++, s2, n)) {
		return s1 - 1;
	}
}
return 0;
}
