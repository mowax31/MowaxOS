#include "tty.h"
#include "io.h"

void move_cursor(int row, int col) {
    unsigned short pos = (row * 80) + col;
    outb(FB_COMMAND_PORT, FB_LOW_BYTE_COMMAND);
    outb(FB_DATA_PORT, (unsigned char)(pos & 0xff));
    outb(FB_COMMAND_PORT, FB_HIGH_BYTE_COMMAND);
    outb(FB_DATA_PORT, (unsigned char)((pos >> 8) & 0xff));
}

void printprompt(void) {
    printf("\n$> ");
    move_cursor(get_terminal_row(), get_terminal_col());
}

uint8_t inb(uint16_t port) {
    uint8_t ret;
    __asm__ __volatile__ ("inb %1, %0" : "=a" (ret): "Nd" (port));
    return ret;
}

void outb(uint16_t port, uint8_t val) {
    __asm__ __volatile__ ("outb %0, %1" : : "a" (val), "Nd" (port));
}

uint8_t scan(void) {
    unsigned char brk;
    static uint8_t key = 0;
    uint8_t scan = inb(0x60);
    brk = scan & 0x80;
    scan = scan & 0x7f;
    if (brk) {
        return key = 0;
    }
    else if (scan != key) {
        return key = scan;
    }
    else {
        return 0;
    }
}
