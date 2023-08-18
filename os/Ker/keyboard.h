#define KBSTATP 0x64
#define KBS_DIB 0x01
#define KBDATAP 0x60

#define NO 0

#define SHIFT (1 << 0)
#define CTL (1 << 1)
#define ALT (1 << 2)

#define CAPSLOCK (1 << 3)
#define NUMLOCK (1 << 4)
#define SCROLLLOCK (1 << 5)

#define E0ESC (1 << 6)

#define KEY_HOME 0xe0
#define KEY_END 0xe1
#define KEY_UP 0xe2
#define KEY_DN 0xe3
#define KEY_LF 0xe4
#define KEY_RT 0xe5
#define KEY_PGUP 0xe6
#define KEY_PGDN 0xe7
#define KEY_INS 0xe8
#define KEY_DEL 0xe9

#define C(x) (x - '@')

static char shiftcode[256] = {
    [0x1d] CTL,
    [0x2a] SHIFT,
    [0x36] SHIFT,
    [0x38] ALT,
    [0x9d] CTL,
    [0xb8] ALT
};

static char togglecode[256] = {
    [0x3a] CAPSLOCK,
    [0x45] NUMLOCK,
    [0x46] SCROLLLOCK
};

static char normalmap[256] = {
    NO, 0x1b, '1', '2', '3', '4', '5', '6',
    '7', '8', '9', '0', '-', '=', '\b', '\t',
    'q', 'w', 'e', 'r', 't', 'y', 'u', 'i',
    'o', 'p', '[', ']', '\n', NO, 'a', 's',
    'd', 'f', 'g', 'h', 'j', 'k', 'l', ';',
    '\'', '`', NO, '\\', 'z', 'x', 'c', 'v',
    'b', 'n', 'm', ',', '.', '/', NO, '*',
    NO, ' ', NO, NO, NO, NO, NO, NO,
    NO, NO, NO, NO, NO, NO, NO, '7',
    '8', '9', '-', '4', '5', '6', '+', '1',
    '2', '3', '0', '.', NO, NO, NO, NO,
    [0x9c] '\n',
    [0xb5] '/',
    [0xc8] KEY_UP, [0xd0] KEY_DN,
    [0xc9] KEY_PGUP, [0xd1] KEY_PGDN,
    [0xcb] KEY_LF, [0xcd] KEY_RT,
    [0x97] KEY_HOME, [0xcf] KEY_END,
    [0xd2] KEY_INS, [0xd3] KEY_DEL
};

static char shiftmap[256] = {
     NO, 033, '!', '@', '#', '$', '%', '^',
     '&', '*', '(', ')', '_', '+', '\b', '\t',
     'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I',
     'O', 'P', '{', '}', '\n', NO, 'A', 'S',
     'D', 'F', 'G', 'H', 'J', 'K', 'L', ':',
     '"', '~', NO, '|', 'Z', 'X', 'C', 'V',
     'B', 'N', 'M', '<', '>', '?', NO, '*',
     NO, ' ', NO, NO, NO, NO, NO, NO,
     NO, NO, NO, NO, NO, NO, NO, '7',
     '8', '9', '-', '4', '5', '6', '+', '1',
     '2', '3', '0', '.', NO, NO, NO, NO,
     [0x9c] '\n',
     [0xb5] '/',
     [0xc8] KEY_UP, [0xd0] KEY_DN,
     [0xc9] KEY_PGUP, [0xd1] KEY_PGDN,
     [0xcb] KEY_LF, [0xcd] KEY_RT,
     [0x97] KEY_HOME, [0xcf] KEY_END,
     [0xd2] KEY_INS, [0xd3] KEY_DEL
};

static char ctlmap[256] = {
    NO, NO, NO, NO, NO, NO, NO, NO,
    NO, NO, NO, NO, NO, NO, NO, NO,
    C('Q'), C('W'), C('E'), C('R'), C('T'), C('Y'), C('U'), C('I'),
    C('O'), C('P'), NO, NO, '\r', NO, C('A'), C('S'),
    C('D'), C('F'), C('G'), C('H'), C('J'), C('K'), C('L'), NO,
    NO, NO, NO,  C('\\'), C('Z'), C('X'), C('C'), C('V'),
    C('B'), C('N'), C('M'), NO, NO, C('/'), NO, NO,
    [0X9C] '\r',
    [0xb5] C('/'),
    [0xc8] KEY_UP, [0xd0] KEY_DN,
    [0xc9] KEY_PGUP, [0xd1] KEY_PGDN,
    [0xcb] KEY_LF, [0xcd] KEY_RT,
    [0x97] KEY_HOME, [0xcf] KEY_END,
    [0xd2] KEY_INS, [0xd3] KEY_DEL
};
