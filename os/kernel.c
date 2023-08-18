#include "Ker/tty.h"
#include "Ker/io.h"
#include "Ker/keyboard.h"
#include "libs/include/string.h"

void kernel(void) {
	terminal_initialize();
}

int main(void) {
	char *buff;
	stringcpy(&buff[stringlen(buff)], "");
	printprompt();
	while(1) {
		uint8_t byte;
		while(byte = scan()) {
			if(byte == 0x1c) {
				if(stringlen(buff) > 0 && stringcmp(buff, "hello") == 0) {
					printf("\nHello world");
				}
				printprompt();
				memoryset(&buff[0], 0, sizeof(buff));
				break;
			}
			else {
				char c = normalmap[byte];
				char *s;
				s = ctos(s, c);
				printf("%s", s);
				stringcpy(&buff[stringlen(buff)], s);
			}
			move_cursor(get_terminal_row(), get_terminal_col());

		}
	}
	return 0;
}

