#ifndef STANDARD_H
#define STANDARD_H

#include "common.h"

// zamienia int w systemie o podstawie base na string
char* itoa(int value, char* result, int base);

void memset(u8int *dest, u8int val, u32int len);

#endif