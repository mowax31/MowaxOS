#include "../include/string.h"

void *memoryset(void *bufptr, int value, size_t size) {
	unsigned char *buf = (unsigned char*)bufptr;
	
	size_t i;
	for(i=0; i < size; i++) {
		buf[i] = (unsigned char)value;
	}
	
	return bufptr;
}
