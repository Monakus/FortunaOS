#ifndef STANDARD_H
#define STANDARD_H

#include "common.h"

// zamienia int w systemie o podstawie base na string
char* itoa(int value, char* result, int base);

void memset(u8int *dest, u8int val, u32int len);

// makra do funkcji, ktore wypisuja bledy
#define PANIC(msg) panic(msg, __FILE__, __LINE__);
#define ASSERT(b) ((b) ? (void)0 : panic_assert(__FILE__, __LINE__, #b))

extern void panic(char *message, char *file, u32int line);
extern void panic_assert(char *file, u32int line, char *desc);

#endif