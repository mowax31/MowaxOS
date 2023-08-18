#include "../include/string.h"

char *ctos(char s[2], const char c) {
	s[0] = c;
	s[1] = '\0';
	
	return s;
}
