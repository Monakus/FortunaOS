#include "common.h"
#include "isr.h"
#include "fb.h"
#include "io.h"

isr_t interrupt_handlers[256];

void register_interrupt_handler(u8int n, isr_t handler){
    interrupt_handlers[n] = handler;
}

// This gets called from interrupt.s
void isr_handler(registers_t regs){
    // debugging
    fb_write("recieved interrupt: ");
    fb_write_dec(regs.int_no);
    fb_putc('\n', FB_BLACK, FB_WHITE);

    if(interrupt_handlers[regs.int_no] != 0){
        isr_t handler = interrupt_handlers[regs.int_no];
        handler(regs);
    }else{
        fb_write("unhandled interrupt: ");
        fb_write_dec(regs.int_no);
        fb_putc('\n', FB_BLACK, FB_WHITE);
    }
}

// This also gets called from interrupt.s
void irq_handler(registers_t regs){
    // Send an EOI (end of interrupt) signal to the PICs.
    // If this interrupt involved the slave.
    if (regs.int_no >= 40) //Interrupts 32-39 = master   40-47 = slave
      outb(0xA0, 0x20); // Send reset signal to slave.

    outb(0x20, 0x20); // Send reset signal to master. (As well as slave, if necessary).

    if (interrupt_handlers[regs.int_no] != 0){
        isr_t handler = interrupt_handlers[regs.int_no];
        handler(regs);
    }
}