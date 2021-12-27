#ifndef STANDARD_H
#define STANDARD_H

#include "common.h"

// change a number into a string 
char* itoa(int value, char* result, int base);

void memset(u8int *dest, u8int val, u32int len);
void memset32(u32int *dest, u32int val, u32int len);

char *strcpy(char *dest, const char *src);

// macros for functions to write errors
#define PANIC(msg) panic(msg, __FILE__, __LINE__);
#define ASSERT(b) ((b) ? (void)0 : panic_assert(__FILE__, __LINE__, #b))

extern void panic(char *message, char *file, u32int line);
extern void panic_assert(char *file, u32int line, char *desc);

#endif