#include "common.h"
#include "isr.h"
#include "fb.h"

// This gets called from our ASM interrupt handler stub.
void isr_handler(registers_t regs){
   fb_write("recieved interrupt: ");
   fb_write_dec(regs.int_no);
   fb_putc('\n', FB_BLACK, FB_WHITE);
}