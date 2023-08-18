#include "../include/string.h"

size_t stringlen(const char *str) {

	size_t ret = 0;
	while (str[ret] != 0) {
	ret++;
}
return ret;
}
