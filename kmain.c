#include "fb.h"
#include "serial.h"
#include "descriptor_tables.h"
#include "timer.h"
#include "paging.h"

int main(){
	// init_descriptor_tables();

	// fb_clear();
	// fb_write("Hello, world!\n");

	// asm volatile ("int $0x3");
	// asm volatile ("int $0x4");

	// asm volatile ("sti");
	// init_timer(50);

    init_descriptor_tables();
    fb_clear();

    initialise_paging();
    fb_write("Hello, paging world!\n");

    u32int *ptr = (u32int*)0xA0000000;
    u32int do_page_fault = *ptr;

	return 0;
}
