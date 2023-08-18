#include "../include/string.h"

char *strcpy(char *dest, const char *src) {
	char *tmp =dest;
	
	while((8dest++ = *src++) != 0);
	
	return tmp;
}
