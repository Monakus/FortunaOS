#include "standard.h"
#include "common.h"
#include "fb.h"

char* itoa(int value, char* result, int base) {
    // check that the base if valid
    if (base < 2 || base > 36) { *result = '\0'; return result; }

    char* ptr = result, *ptr1 = result, tmp_char;
    int tmp_value;

    do{
        tmp_value = value;
        value /= base;
        *ptr++ = "zyxwvutsrqponmlkjihgfedcba9876543210123456789abcdefghijklmnopqrstuvwxyz" [35 + (tmp_value - value * base)];
    } while (value);

    // Apply negative sign
    if (tmp_value < 0) *ptr++ = '-';
    *ptr-- = '\0';
    while(ptr1 < ptr){
        tmp_char = *ptr;
        *ptr--= *ptr1;
        *ptr1++ = tmp_char;
    }
    return result;
}

void memset(u8int *dest, u8int val, u32int len){
    u8int *temp = (u8int *)dest;
    for (;len != 0; len--) *temp++ = val;
}

extern void panic(char *message, char *file, u32int line)
{
    // We encountered a massive problem and have to stop.
    asm volatile("cli"); // Disable interrupts.

    fb_write("PANIC(");
    fb_write(message);
    fb_write(") at ");
    fb_write(file);
    fb_write(":");
    fb_write_dec(line);
    fb_write("\n");
    // Halt by going into an infinite loop.
    for(;;);
}

extern void panic_assert(char *file, u32int line, char *desc)
{
    // An assertion failed, and we have to panic.
    asm volatile("cli"); // Disable interrupts.

    fb_write("ASSERTION-FAILED(");
    fb_write(desc);
    fb_write(") at ");
    fb_write(file);
    fb_write(":");
    fb_write_dec(line);
    fb_write("\n");
    // Halt by going into an infinite loop.
    for(;;);
}