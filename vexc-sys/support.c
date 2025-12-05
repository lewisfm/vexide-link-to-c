#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

int32_t vexSerialWriteChar(uint32_t channel, uint8_t c);
int32_t vexSerialWriteFree(uint32_t channel);
void vexTasksRun(void);
void vexSystemExitRequest(void);
static int serial_putc(char c, FILE *file);
static int serial_getc(FILE *file);
static int serial_flush(FILE *file);


constexpr uint32_t STDIO_CHANNEL = 1;

static FILE stdio = {
    .flags = _FDEV_SETUP_RW,
    .put = serial_putc,
    .get = serial_getc,
    .flush = serial_flush,
};

// All 3 streams are aliased to the same `stdio` reference.
FILE *const stdin = &stdio;
extern FILE *const stdout [[gnu::alias("stdin")]];
extern FILE *const stderr [[gnu::alias("stdin")]];

int serial_putc(char c, FILE *file) {
    (void) file;

    int rtn = vexSerialWriteChar(STDIO_CHANNEL, c);

    while (vexSerialWriteFree(STDIO_CHANNEL) < 2048) {
        vexTasksRun();
    }

    return rtn == 1 ? c : EOF;
}

int serial_getc(FILE *file) {
    (void) file;
    return 0;
}

int serial_flush(FILE *file) {
    (void) file;
    return 0;
}

void _exit(int code) {
    (void) code;

    vexSystemExitRequest();

    while (true) {
        vexTasksRun();
    }
}

int getentropy(void *buf, size_t buflen) {
    (void) buf;
    (void) buflen;

    return 0;
}
